#pragma once
#include <iostream>
#include <cstring> // Just here for one memcpy()
#include <vector>
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
std::string *type_str = new std::string[256];
void init_types()
{
    type_str[INPUT] = "input";
    type_str[PROGRAM] = "program";
    type_str[ERROR] = "error";
    type_str[version] = "version";
    type_str[optimise] = "optimise";
    type_str[jobs] = "jobs";
    type_str[directory] = "directory";
}

typedef struct Option
{
    OptionType type;
    std::string value;
} Option;

int has_value(OptionType type);
OptionType get_type(std::string name);
int get_arg(Option &buffer, std::string current, std::string next);
void get_args(std::vector<Option> &buffer, int argc, char **argv);
int main(int argc, char **argv);