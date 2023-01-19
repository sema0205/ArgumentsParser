#pragma once

#include "../headers/Flag.h"
#include "../headers/StringArgument.h"
#include "../headers/IntArgument.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

namespace ArgumentParser {


    class ArgParser {
    public:

        // parser construct
        ArgParser(std::string name);

        // overload of adding a flag
        Flag& AddFlag(char short_name, std::string full_name);
        Flag& AddFlag(char short_name, std::string full_name, std::string flag_description);
        Flag& AddFlag(std::string full_name);
        Flag& AddFlag(char short_name);
        Flag& AddFlag(std::string full_name, std::string flag_description);

        // show help functions
        void AddHelp(char short_name, std::string full_name, std::string flag_description);
        bool Help();
        std::string HelpDescription();

        // parse a console input functions
        bool Parse(int arguments_amount, char** arguments_massive);
        bool Parse(std::vector<std::string> vector_of_arguments);

        //
        bool GetFlag(std::string flag_value);
        bool GetFlag(char flag_value);

        // adding arguments constructors
        IntArgument& AddIntArgument(std::string full_name);
        IntArgument& AddIntArgument(char short_name, std::string full_name);
        IntArgument& AddIntArgument(std::string full_name, std::string description);

        StringArgument& AddStringArgument(std::string full_name);
        StringArgument& AddStringArgument(char short_name, std::string full_name);
        StringArgument& AddStringArgument(std::string full_name, std::string description);
        StringArgument& AddStringArgument(char short_name, std::string full_name, std::string description);

        // Get value
        int GetIntValue(std::string full_name, int index);
        int GetIntValue(std::string full_name);

        std::string GetStringValue(std::string full_name, int index);
        std::string GetStringValue(std::string full_name);

    private:
        std::string parser_name_;

        std::vector<Flag> list_of_flags_;
        std::vector<IntArgument> list_of_int_arguments;
        std::vector<StringArgument> list_of_string_arguments;
    };



} // namespace ArgumentParser
