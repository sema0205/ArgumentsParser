#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

namespace ArgumentParser {

    class StringArgument {
    public:

        // different contructors
        StringArgument();
        StringArgument(std::string full_name);
        StringArgument(std::string full_name, std::string full_description);
        StringArgument(char short_name, std::string full_name, std::string full_description);
        StringArgument(char short_name, std::string full_name);
        StringArgument(char short_name);


        // Overload of options to put value in certain variable
        StringArgument& StoreValues(std::vector<std::string>& value_store);
        StringArgument& StoreValue(std::string& value);

        // lowest possible amount of variables for specific argument
        StringArgument& MultiValue(int amount);
        // func with no parameter sets possible amount to 0
        StringArgument& MultiValue();

        // Positional sets if variables are free parameters
        StringArgument& Positional();
        // Default sets default value for specific argument
        StringArgument& Default(std::string value);


        // Getters and Setters for private values
        char GetShortName();
        std::string GetFullName();
        std::string GetFullDescription();
        bool GetIsPosition();
        int GetMinArgumentsAmount();
        int GetRealAmount();
        std::string GetSaveSingleArgument();
        std::vector<std::string> GetMultiArguments();
        std::string* GetSingleArgumentStore();
        std::vector<std::string>* GetMultiArgumentsStore();
        bool GetIsMulti();
        bool GetWasUsed();

        void SetWasUsed();
        void SetSaveSingleArgument(std::string value);
        void SetMultiArguments(std::string value);
        void SetSingleArgumentStore(std::string value);
        void SetMultiArgumentsStore(std::string value);

        // to track any changes in stored values
        void AddRealAmount();

    private:
        char short_name_;
        std::string full_name_;
        std::string full_description_;

        bool is_position_;
        int min_arguments_amount_;
        int real_amount_;

        std::string save_single_argument_;
        std::vector<std::string> multi_arguments_;

        std::string* single_argument_store_;
        std::vector<std::string>* multi_arguments_store_;

        bool is_multi_;
        bool was_used_;
    };

}
