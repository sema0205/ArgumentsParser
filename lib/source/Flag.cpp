#include "../headers/Flag.h"

ArgumentParser::Flag::Flag() {
    short_name_ = {};
    full_name_ = "";
    flag_description_ = "";
    is_found_ = false;
    was_used_ = true;
}

ArgumentParser::Flag::Flag(char short_name, std::string full_name, std::string flag_description, bool is_found) : ArgumentParser::Flag::Flag() {
    short_name_ = short_name;
    full_name_ = full_name;
    flag_description_ = flag_description;
    is_found_ = is_found;
}

ArgumentParser::Flag::Flag(char short_name, bool is_found) : ArgumentParser::Flag::Flag() {
    short_name_ = short_name;
    is_found_ = is_found;
}

ArgumentParser::Flag::Flag(char short_name, std::string full_name, bool is_found) : ArgumentParser::Flag::Flag() {
    short_name_ = short_name;
    full_name_ = full_name;
    is_found_ = is_found;
}

ArgumentParser::Flag::Flag(std::string full_name, bool is_found) : ArgumentParser::Flag::Flag() {
    full_name_ = full_name;
    is_found_ = is_found;
}

ArgumentParser::Flag::Flag(std::string full_name, std::string flag_description, bool is_found) : ArgumentParser::Flag::Flag() {
    full_name_ = full_name;
    flag_description_ = flag_description;
    is_found_ = is_found;
}



ArgumentParser::Flag &ArgumentParser::Flag::Default(bool value) {
    is_found_ = value;
    return *this;
}

ArgumentParser::Flag &ArgumentParser::Flag::StoreValue(bool &value_store) {
    store_value_ = &value_store;
    return *this;
}



char ArgumentParser::Flag::GetShortName() {
    return short_name_;
}

std::string ArgumentParser::Flag::GetFullName() {
    return full_name_;
}

std::string ArgumentParser::Flag::GetDescription() {
    return flag_description_;
}

bool ArgumentParser::Flag::GetWasUsed() {
    return was_used_;
}

bool ArgumentParser::Flag::IsFound() {
    return is_found_;
}


void ArgumentParser::Flag::SetIsFound(bool value) {
    is_found_ = value;
}

void ArgumentParser::Flag::SetStoreValue(bool *value) {
    store_value_ = value;
}

void ArgumentParser::Flag::SetWasUsed() {
    was_used_ = true;
}


void ArgumentParser::Flag::ChangeStoreValue() {
    *store_value_ = true;
}
