#include "program.h"

int main(int argc, char **argv)
{
    int size;
    struct Option *options = get_options(argc, argv, &size);

    for (size_t i = 0; i < size; i++)
    {
        OptionType optype = options[i].type;
        const char *type = type_str[optype];
        const char *value = options[i].value;
        printf("%s: %s\n", type, value);
    }

    return 0;
}
/// Puts all arguments into an array and notes the size.
/// @param argc The amount of strings to look through.
/// @param argv An array of strings to look through.
/// @param size An out-parameter to store the size of the output array in.
/// @returns An array containing the options found in `argv`. It it sized to fit.
struct Option *get_options(int argc, char **argv, int *size)
{
    struct Option *optBuffer = malloc(sizeof(struct Option) * argc);
    *size = get_args(optBuffer, argc, argv);
    return realloc(optBuffer, *size * sizeof(struct Option));
}
/// Writes all arguments it finds into the `buffer`.
/// @param buffer An array of Option structs that has enough space to fit all arguments. (A size of at least `argc` is recommended to guarantee no overflow.)
/// @param argc The amount of strings to look through.
/// @param argv An array of strings to look through.
/// @returns The amount of options found in `argv`.
int get_args(struct Option buffer[], int argc, char **argv)
{
    int args = 0;
    // Manually constructs the first option.
    struct Option opt = {PROGRAM, malloc(strlen(argv[0]))};
    memcpy(opt.value, argv[0], strlen(argv[0]));
    // First adds opt then makes a new option.
    for (int i = 1; i < argc; i += get_arg(&opt, argv[i], argv[i + 1]))
    {
        buffer[args] = opt;
        args++;
    }
    // Add the final option.
    buffer[args] = opt;
    return ++args;
}
/// Gets the current Option type and value.
/// @param result An out-parameter to store the found option in.
/// @param current The current string to look through. It may contain the full option, or just its type.
/// @param next The next string. It is used when a value is needed, but not it the `current` string.
/// @returns The amount of strings taken. (`get_arg(NULL, "-j", "8")` return 2 because both `current` and `next` were part of the option)
int get_arg(struct Option *result, char *current, char *next)
{
    char *value = ZEROPTR;
    int clen = strlen(current);
    int size = 1;
    OptionType type;

    if (current[0] != '-')
    {
        type = INPUT;
        value = malloc(clen + 1);
        strcpy(value, current);
    }
    else if (current[1] != '-')
    {
        type = current[1];
        if (current[2])
        {
            value = malloc(clen - 1);
            strcpy(value, current + 2);
        }
        else if (has_value(type))
        {
            value = malloc(strlen(next) + 1);
            strcpy(value, next);
            size = 2;
        }
    }
    else
    {
        type = get_type(current + 2);
        int offset = strcspn(current, "=");
        if (offset != clen)
        {
            value = malloc(clen - offset - 1);
            strcpy(value, current + offset + 1);
        }
    }

    struct Option opt = {type, value};
    *result = opt;
    return size;
}
/// The macro that is used to check within `get_type()`
/// @param enumname The `OptionType` to check against.
/// @returns `enumname` if it was found. Otherwise it doesn't return.
#define STRENUM(enumname)                   \
    cmp = strcmp(name, type_str[enumname]); \
    if (cmp == 0 || cmp == '=')             \
        return enumname;
/// Gets the type of a string of a long option.
/// @param name The string containing the name of the option. Without the leading `--`.
/// @returns The `OptionType` of said string.
OptionType get_type(char *name)
{
    int cmp;
    STRENUM(optimise);
    STRENUM(directory);
    return ERROR;
}
#undef STRENUM
/// Checks if an option needs a value or just is a switch/bool.
/// @param type The type of said option.
/// @returns A boolean value of wheater the type needs a value or not.
int has_value(OptionType type)
{
    switch (type)
    {
    case INPUT:
    case PROGRAM:
    case jobs:
    case directory:
        return 1;
    default:
        return 0;
    }
}