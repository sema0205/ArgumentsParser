#include "../headers/IntArgument.h"

ArgumentParser::IntArgument::IntArgument() {
    short_name_ = {};
    full_name_ = "";
    full_description_ = "";

    is_position_ = false;
    min_arguments_amount_ = 0;
    real_amount_ = 0;

    save_single_argument_ = 0;
    multi_arguments_ = {};

    single_argument_store_ = nullptr;
    multi_arguments_store_ = {};
    is_multi_ = false;
    was_used_ = false;
}

ArgumentParser::IntArgument::IntArgument(std::string full_name) : ArgumentParser::IntArgument::IntArgument() {
    full_name_ = full_name;
}

ArgumentParser::IntArgument::IntArgument(std::string full_name, std::string full_description) : ArgumentParser::IntArgument::IntArgument() {
    full_name_ = full_name;
    full_description_ = full_description;
}

ArgumentParser::IntArgument::IntArgument(char short_name, std::string full_name) : ArgumentParser::IntArgument::IntArgument() {
    short_name_ = short_name;
    full_name_ = full_name;
}

ArgumentParser::IntArgument::IntArgument(char short_name) : ArgumentParser::IntArgument::IntArgument() {
    short_name_ = short_name;
}

ArgumentParser::IntArgument &ArgumentParser::IntArgument::StoreValues(std::vector<int> &value_store) {
    multi_arguments_store_ = &value_store;
    return *this;
}

ArgumentParser::IntArgument &ArgumentParser::IntArgument::StoreValue(int &value) {
    single_argument_store_ = &value;
    return *this;
}

ArgumentParser::IntArgument &ArgumentParser::IntArgument::MultiValue(int amount) {
    min_arguments_amount_ = amount;
    is_multi_ = true;
    return *this;
}

ArgumentParser::IntArgument &ArgumentParser::IntArgument::MultiValue() {
    min_arguments_amount_ = 0;
    is_multi_ = true;
    return *this;
}


ArgumentParser::IntArgument &ArgumentParser::IntArgument::Positional() {
    is_position_ = true;
    return *this;
}

ArgumentParser::IntArgument &ArgumentParser::IntArgument::Default(int value) {
    save_single_argument_ = value;
    AddRealAmount();
    return *this;
}



char ArgumentParser::IntArgument::GetShortName() {
    return short_name_;
}

std::string ArgumentParser::IntArgument::GetFullName() {
    return full_name_;
}

std::string ArgumentParser::IntArgument::GetFullDescription() {
    return full_description_;
}

bool ArgumentParser::IntArgument::GetIsPosition() {
    return is_position_;
}

int ArgumentParser::IntArgument::GetMinArgumentsAmount() {
    return min_arguments_amount_;
}

int ArgumentParser::IntArgument::GetRealAmount() {
    return real_amount_;
}

int ArgumentParser::IntArgument::GetSaveSingleArgument() {
    return save_single_argument_;
}

std::vector<int> ArgumentParser::IntArgument::GetMultiArguments() {
    return multi_arguments_;
}

int *ArgumentParser::IntArgument::GetSingleArgumentStore() {
    return single_argument_store_;
}

std::vector<int> *ArgumentParser::IntArgument::GetMultiArgumentsStore() {
    return multi_arguments_store_;
}

bool ArgumentParser::IntArgument::GetWasUsed() {
    return was_used_;
}

bool ArgumentParser::IntArgument::GetIsMulti() {
    return is_multi_;
}


void ArgumentParser::IntArgument::SetWasUsed() {
    was_used_ = true;
}

void ArgumentParser::IntArgument::SetSaveSingleArgument(int value) {
    save_single_argument_ = value;
}

void ArgumentParser::IntArgument::SetMultiArguments(int value) {
    multi_arguments_.push_back(value);
}

void ArgumentParser::IntArgument::SetSingleArgumentStore(int value) {
    single_argument_store_ = &value;
}

void ArgumentParser::IntArgument::SetMultiArgumentsStore(int value) {
    multi_arguments_store_->push_back(value);
}



void ArgumentParser::IntArgument::AddRealAmount() {
    real_amount_++;
}
