#include "program.hxx"

int main(int argc, char **argv)
{
    init_types();
    std::vector<Option> options = std::vector<Option>();
    get_args(options, argc, argv);

    for (auto opt : options)
        std::cout << type_str[opt.type] << ": " << opt.value << std::endl;

    return 0;
}

/// Writes all arguments it finds into the `buffer`.
/// @param buffer A vector that the options will be pushed into.
/// @param argc The amount of strings to look through.
/// @param argv An array of strings to look through.
void get_args(std::vector<Option> &buffer, int argc, char **argv)
{
    // Manually constructs the first option.
    Option opt = {PROGRAM, std::string()};
    opt.value = std::string(argv[0]);
    // First adds opt then makes a new option.
    for (int i = 1; i < argc; i += get_arg(opt, std::string(argv[i]), std::string(argv[std::min(i + 1, argc - 1)])))
        buffer.push_back(opt);
    // Add the final option.
    buffer.push_back(opt);
}
/// Gets the current Option type and value.
/// @param result An out-parameter to store the found option in.
/// @param current The current string to look through. It may contain the full option, or just its type.
/// @param next The next string. It is used when a value is needed, but not it the `current` string.
/// @returns The amount of strings taken. (`get_arg(voidptr, "-j", "8")` return 2 because both `current` and `next` were part of the option)
int get_arg(Option &result, std::string current, std::string next)
{
    std::string value;
    int size = 1;
    OptionType type;

    if (current[0] != '-')
    {
        type = INPUT;
        value = std::string(current);
    }
    else if (current[1] != '-')
    {
        type = (OptionType)current[1];
        if (current[2])
        {
            value = std::string(current, 2);
        }
        else if (has_value(type))
        {
            value = std::string(next);
            size = 2;
        }
    }
    else
    {
        type = get_type(std::string(current, 2));
        size_t offset = current.find_first_of('=');
        if (offset != current.length())
            value = std::string(current, offset + 1);
    }

    Option opt = {type, value};
    result = opt;
    return size;
}
/// The macro that is used to check within `get_type()`
/// @param enumname The `OptionType` to check against.
/// @returns `enumname` if it was found. Otherwise it doesn't return.
#define STRENUM(enumname)                     \
    if (name.starts_with(type_str[enumname])) \
        return enumname;
/// Gets the type of a string of a long option.
/// @param name The string containing the name of the option. Without the leading `--`.
/// @returns The `OptionType` of said string.
OptionType get_type(std::string name)
{
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