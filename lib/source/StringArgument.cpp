#include "../headers/StringArgument.h"

ArgumentParser::StringArgument::StringArgument() {
    short_name_ = {};
    full_name_ = "";
    full_description_ = "";

    is_position_ = false;
    min_arguments_amount_ = 0;
    real_amount_ = 0;

    save_single_argument_ = "";
    multi_arguments_ = {};

    single_argument_store_ = nullptr;
    multi_arguments_store_ = {};
    is_multi_ = false;
    was_used_ = false;
}

ArgumentParser::StringArgument::StringArgument(std::string full_name) : ArgumentParser::StringArgument::StringArgument() {
    full_name_ = full_name;
}

ArgumentParser::StringArgument::StringArgument(std::string full_name, std::string full_description) : ArgumentParser::StringArgument::StringArgument() {
    full_name_ = full_name;
    full_description_ = full_description;
}

ArgumentParser::StringArgument::StringArgument(char short_name, std::string full_name, std::string full_description) : ArgumentParser::StringArgument::StringArgument() {
    short_name_ = short_name;
    full_name_ = full_name;
    full_description_ = full_description;
}

ArgumentParser::StringArgument::StringArgument(char short_name, std::string full_name) : ArgumentParser::StringArgument::StringArgument() {
    short_name_ = short_name;
    full_name_ = full_name;
}

ArgumentParser::StringArgument::StringArgument(char short_name) : ArgumentParser::StringArgument::StringArgument() {
    short_name_ = short_name;
}



ArgumentParser::StringArgument &ArgumentParser::StringArgument::StoreValues(std::vector<std::string> &value_store) {
    multi_arguments_store_ = &value_store;
    return *this;
}

ArgumentParser::StringArgument &ArgumentParser::StringArgument::StoreValue(std::string &value) {
    single_argument_store_ = &value;
    return *this;
}



ArgumentParser::StringArgument &ArgumentParser::StringArgument::MultiValue(int amount) {
    min_arguments_amount_ = amount;
    is_multi_ = true;
    return *this;
}

ArgumentParser::StringArgument &ArgumentParser::StringArgument::MultiValue() {
    min_arguments_amount_ = 0;
    is_multi_ = true;
    return *this;
}



ArgumentParser::StringArgument &ArgumentParser::StringArgument::Positional() {
    is_position_ = true;
    return *this;
}

ArgumentParser::StringArgument &ArgumentParser::StringArgument::Default(std::string value) {
    save_single_argument_ = value;
    AddRealAmount();
    return *this;
}



char ArgumentParser::StringArgument::GetShortName() {
    return short_name_;
}

std::string ArgumentParser::StringArgument::GetFullName() {
    return full_name_;
}

std::string ArgumentParser::StringArgument::GetFullDescription() {
    return full_description_;
}

bool ArgumentParser::StringArgument::GetIsPosition() {
    return is_position_;
}

int ArgumentParser::StringArgument::GetMinArgumentsAmount() {
    return min_arguments_amount_;
}

int ArgumentParser::StringArgument::GetRealAmount() {
    return real_amount_;
}

std::string ArgumentParser::StringArgument::GetSaveSingleArgument() {
    return save_single_argument_;
}

std::vector<std::string> ArgumentParser::StringArgument::GetMultiArguments() {
    return multi_arguments_;
}

std::string *ArgumentParser::StringArgument::GetSingleArgumentStore() {
    return single_argument_store_;
}

std::vector<std::string> *ArgumentParser::StringArgument::GetMultiArgumentsStore() {
    return multi_arguments_store_;
}

bool ArgumentParser::StringArgument::GetIsMulti() {
    return is_multi_;
}

bool ArgumentParser::StringArgument::GetWasUsed() {
    return was_used_;
}


void ArgumentParser::StringArgument::SetWasUsed() {
    was_used_ = true;
}

void ArgumentParser::StringArgument::SetSaveSingleArgument(std::string value) {
    save_single_argument_ = value;
}

void ArgumentParser::StringArgument::SetMultiArguments(std::string value) {
    multi_arguments_.push_back(value);
}

void ArgumentParser::StringArgument::SetSingleArgumentStore(std::string value) {
    *single_argument_store_ = value;
}

void ArgumentParser::StringArgument::SetMultiArgumentsStore(std::string value) {
    multi_arguments_store_->push_back(value);
}


void ArgumentParser::StringArgument::AddRealAmount() {
    real_amount_++;
}
