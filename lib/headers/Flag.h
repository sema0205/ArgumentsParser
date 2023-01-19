#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

namespace ArgumentParser {

    class Flag {
    public:

        // different contructors
        Flag();
        Flag(char short_name, std::string full_name, std::string flag_description, bool is_found = false);
        Flag(char short_name, bool is_found = false);
        Flag(char short_name, std::string full_name, bool is_found = false);
        Flag(std::string full_name, bool is_found = false);
        Flag(std::string full_name, std::string flag_description, bool is_found = false);

        // set some rules
        Flag& Default(bool value);
        Flag& StoreValue(bool& value_store);

        // Getters and Setters
        char GetShortName();
        std::string GetFullName();
        std::string GetDescription();
        bool GetWasUsed();
        bool IsFound();

        void SetIsFound(bool value);
        void SetStoreValue(bool* value);
        void SetWasUsed();

        // change value in specific given variable
        void ChangeStoreValue();

    private:
        char short_name_;
        std::string full_name_;
        std::string flag_description_;

        bool is_found_;
        bool* store_value_;
        bool was_used_;
    };

}
