#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

namespace ArgumentParser {

    class IntArgument {
    public:

        // different constructors
        IntArgument();
        IntArgument(std::string full_name);
        IntArgument(std::string full_name, std::string full_description);
        IntArgument(char short_name, std::string full_name);
        IntArgument(char short_name);


        // set rules for arguments
        IntArgument& StoreValues(std::vector<int>& value_store);
        IntArgument& StoreValue(int& value);

        IntArgument& MultiValue(int amount);
        IntArgument& MultiValue();

        IntArgument& Positional();
        IntArgument& Default(int value);

        // Getters and Setters
        char GetShortName();
        std::string GetFullName();
        std::string GetFullDescription();
        bool GetIsPosition();
        int GetMinArgumentsAmount();
        int GetRealAmount();
        int GetSaveSingleArgument();
        std::vector<int> GetMultiArguments();
        int* GetSingleArgumentStore();
        std::vector<int>* GetMultiArgumentsStore();
        bool GetWasUsed();
        bool GetIsMulti();

        void SetWasUsed();
        void SetSaveSingleArgument(int value);
        void SetMultiArguments(int value);
        void SetSingleArgumentStore(int value);
        void SetMultiArgumentsStore(int value);

        // to track any changes in stored values
        void AddRealAmount();

    private:
        char short_name_;
        std::string full_name_;
        std::string full_description_;

        bool is_position_;
        int min_arguments_amount_;
        int real_amount_;

        int save_single_argument_;
        std::vector<int> multi_arguments_;

        int* single_argument_store_;
        std::vector<int>* multi_arguments_store_;

        bool is_multi_;
        bool was_used_;
    };

}
