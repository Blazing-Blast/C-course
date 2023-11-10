#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Maybe this saves memory, idk.
char *ZEROPTR = "";
// All the options the program may use. Use character litterals when defining short options.
typedef enum OptionType
{
    //  name    letter      value
    INPUT = 0,     //  yes
    PROGRAM = 1,   //  yes
    ERROR = 2,     //  no
    version = 'V', //  no
    optimise,      //  no
    jobs = 'j',    //  yes
    directory,     //  yes
} OptionType;
// The stringified version of the option names. One big array that negates all other memory savings.
const char *const type_str[] = {
    [INPUT] = "input",
    [PROGRAM] = "program",
    [ERROR] = "error",
    [version] = "version",
    [optimise] = "optimise",
    [jobs] = "jobs",
    [directory] = "directory"};

struct Option
{
    OptionType type;
    char *value;
};

int has_value(OptionType type);
OptionType get_type(char *name);
int get_arg(struct Option *result, char *current, char *next);
int get_args(struct Option buffer[], int argc, char **argv);
struct Option *get_options(int argc, char **argv, int *size);
int main(int argc, char **argv);
