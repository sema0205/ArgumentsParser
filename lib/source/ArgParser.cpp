#include "../headers/ArgParser.h"

ArgumentParser::ArgParser::ArgParser(std::string name) : parser_name_(name) {

}

ArgumentParser::Flag &ArgumentParser::ArgParser::AddFlag(char short_name, std::string full_name) {
    list_of_flags_.push_back(Flag(short_name, full_name));
    return list_of_flags_.back();
}

ArgumentParser::Flag &ArgumentParser::ArgParser::AddFlag(char short_name, std::string full_name, std::string flag_description) {
    list_of_flags_.push_back(Flag(short_name, full_name, flag_description));
    return list_of_flags_.back();
}

ArgumentParser::Flag &ArgumentParser::ArgParser::AddFlag(std::string full_name) {
    list_of_flags_.push_back(Flag(full_name));
    return list_of_flags_.back();
}

ArgumentParser::Flag &ArgumentParser::ArgParser::AddFlag(char short_name) {
    list_of_flags_.push_back(Flag(short_name));
    return list_of_flags_.back();
}

ArgumentParser::Flag &ArgumentParser::ArgParser::AddFlag(std::string full_name, std::string flag_description) {
    list_of_flags_.push_back(Flag(full_name, flag_description));
    return list_of_flags_.back();
}

void ArgumentParser::ArgParser::AddHelp(char short_name, std::string full_name, std::string flag_description) {
    list_of_flags_.push_back(Flag(short_name, full_name, flag_description));
}

bool ArgumentParser::ArgParser::Help() {

    return true;
}

std::string ArgumentParser::ArgParser::HelpDescription() {
    std::string result;
    result += parser_name_;
    result += "\n";
    result += "Some Description about program\n";
    result += "\n";

    for (int i = 0; i < list_of_flags_.size(); i++) {
        result += '-';
        result += list_of_flags_[i].GetShortName();
        result += ",  ";
        result += "--";
        result += list_of_flags_[i].GetFullName();
        result += ",  ";
        result += list_of_flags_[i].GetDescription();
        result += "\n";
    }

    for (int i = 0; i < list_of_string_arguments.size(); i++) {
        result += '-';
        result += list_of_string_arguments[i].GetShortName();
        result += ",  ";
        result += "--";
        result += list_of_string_arguments[i].GetFullName();
        result += ",  ";
        result += list_of_string_arguments[i].GetFullDescription();
        result += "\n";
    }

    for (int i = 0; i < list_of_int_arguments.size(); i++) {
        result += "  ";
        result += "--";
        result += list_of_int_arguments[i].GetFullName();
        result += ",  ";
        result += list_of_int_arguments[i].GetFullDescription();
        result += "\n";
    }

    return result;
}

bool ArgumentParser::ArgParser::GetFlag(std::string flag_value) {
    for (auto &s : list_of_flags_) {
        if (s.GetFullName() == flag_value) {
            return s.IsFound();
        }
    }

    return false;
}

bool ArgumentParser::ArgParser::GetFlag(char flag_value) {
    for (auto &s: list_of_flags_) {
        if (s.GetShortName() == flag_value) {
            return s.IsFound();
        }
    }

    return false;
}



ArgumentParser::IntArgument& ArgumentParser::ArgParser::AddIntArgument(std::string full_name) {
    list_of_int_arguments.push_back(IntArgument(full_name));
    return list_of_int_arguments.back();
}

ArgumentParser::IntArgument& ArgumentParser::ArgParser::AddIntArgument(char short_name, std::string full_name) {
    list_of_int_arguments.push_back(IntArgument(short_name, full_name));
    return list_of_int_arguments.back();
}

ArgumentParser::IntArgument& ArgumentParser::ArgParser::AddIntArgument(std::string full_name, std::string description) {
    list_of_int_arguments.push_back(IntArgument(full_name, description));
    return list_of_int_arguments.back();
}


ArgumentParser::StringArgument& ArgumentParser::ArgParser::AddStringArgument(std::string full_name) {
    list_of_string_arguments.push_back(StringArgument(full_name));
    return list_of_string_arguments.back();
}

ArgumentParser::StringArgument& ArgumentParser::ArgParser::AddStringArgument(char short_name, std::string full_name) {
    list_of_string_arguments.push_back(StringArgument(short_name, full_name));
    return list_of_string_arguments.back();
}

ArgumentParser::StringArgument& ArgumentParser::ArgParser::AddStringArgument(std::string full_name, std::string description) {
    list_of_string_arguments.push_back(StringArgument(full_name, description));
    return list_of_string_arguments.back();
}

ArgumentParser::StringArgument& ArgumentParser::ArgParser::AddStringArgument(char short_name, std::string full_name, std::string description) {
    list_of_string_arguments.push_back(StringArgument(short_name, full_name, description));
    return list_of_string_arguments.back();
}



int ArgumentParser::ArgParser::GetIntValue(std::string full_name, int index) {
    for (int i = 0; i < list_of_int_arguments.size(); i++) {
        if (list_of_int_arguments[i].GetFullName() == full_name) {
            return list_of_int_arguments[i].GetMultiArguments()[index];
        }
    }
}

int ArgumentParser::ArgParser::GetIntValue(std::string full_name) {
    for (int i = 0; i < list_of_int_arguments.size(); i++) {
        if (list_of_int_arguments[i].GetFullName() == full_name) {
            return list_of_int_arguments[i].GetSaveSingleArgument();
        }
    }
}


std::string ArgumentParser::ArgParser::GetStringValue(std::string full_name, int index) {
    for (int i = 0; i < list_of_string_arguments.size(); i++) {
        if (list_of_string_arguments[i].GetFullName() == full_name) {
            return list_of_string_arguments[i].GetMultiArguments()[index];
        }
    }
}

std::string ArgumentParser::ArgParser::GetStringValue(std::string full_name) {
    for (int i = 0; i < list_of_string_arguments.size(); i++) {
        if (list_of_string_arguments[i].GetFullName() == full_name) {
            return list_of_string_arguments[i].GetSaveSingleArgument();
        }
    }
}



bool ArgumentParser::ArgParser::Parse(int arguments_amount, char **arguments_massive) {
    std::vector<std::string> vector_of_arguments(arguments_massive, arguments_massive + arguments_amount);
    return Parse(vector_of_arguments);
}

bool ArgumentParser::ArgParser::Parse(std::vector<std::string> vector_of_arguments) {

    for (int i = 1; i < vector_of_arguments.size(); i++) {

        bool is_passed = false;

        std::string::difference_type character_amount = std::count(vector_of_arguments[i].begin(), vector_of_arguments[i].end(), '-');

        if (vector_of_arguments[i].find('=') != -1) {

            for (int j = 0; j < list_of_string_arguments.size(); j++) {

                std::string temp(1, list_of_string_arguments[j].GetShortName());

                if (list_of_string_arguments[j].GetFullName() == vector_of_arguments[i].substr(2, vector_of_arguments[i].find_first_of('=') - 2)) {
                    if (list_of_string_arguments[j].GetIsMulti()) {
                        list_of_string_arguments[j].SetMultiArguments(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].SetMultiArgumentsStore(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].AddRealAmount();
                        is_passed = true;
                        list_of_string_arguments[j].SetWasUsed();
                    } else {
                        if (list_of_string_arguments[j].GetSingleArgumentStore() != nullptr) {
                            list_of_string_arguments[j].SetSingleArgumentStore(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1,vector_of_arguments[i].size()));
                        }
                        list_of_string_arguments[j].SetSaveSingleArgument(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].AddRealAmount();
                        list_of_string_arguments[j].SetWasUsed();
                        is_passed = true;
                    }

                } else if (temp == vector_of_arguments[i].substr(1, vector_of_arguments[i].find_first_of('=') - 1)) {
                    if (list_of_string_arguments[j].GetIsMulti()) {
                        list_of_string_arguments[j].SetMultiArguments(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].SetMultiArgumentsStore(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].AddRealAmount();
                        list_of_string_arguments[j].SetWasUsed();
                        is_passed = true;
                    } else {
                        if (list_of_string_arguments[j].GetSingleArgumentStore() != nullptr) {
                            list_of_string_arguments[j].SetSingleArgumentStore(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1,vector_of_arguments[i].size()));
                        }
                        list_of_string_arguments[j].SetSaveSingleArgument(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].AddRealAmount();
                        list_of_string_arguments[j].SetWasUsed();
                        is_passed = true;
                    }
                }
            }

            for (int j = 0; j < list_of_int_arguments.size(); j++) {
                if (list_of_int_arguments[j].GetFullName() == vector_of_arguments[i].substr(2, vector_of_arguments[i].find_first_of('=') - 2)) {
                    if (list_of_int_arguments[j].GetIsMulti()) {
                        list_of_int_arguments[j].SetMultiArguments(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].SetMultiArgumentsStore(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].AddRealAmount();
                        list_of_int_arguments[j].SetWasUsed();
                        is_passed = true;
                    } else {
                        list_of_int_arguments[j].SetSaveSingleArgument(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].SetSingleArgumentStore(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].AddRealAmount();
                        list_of_int_arguments[j].SetWasUsed();
                        is_passed = true;
                    }
                }
            }

        } else if (!is_passed && character_amount == 2) {
            for (int j = 0; j < list_of_flags_.size(); j++) {
                if (list_of_flags_[j].GetFullName() == vector_of_arguments[i].substr(vector_of_arguments[i].find_last_of('-') + 1, vector_of_arguments[i].size())) {
                    list_of_flags_[j].ChangeStoreValue();
                    list_of_flags_[j].SetIsFound(true);
                    is_passed = true;
                }
            }
        } else if (!is_passed && character_amount == 1 && !list_of_flags_.empty()) {
            std::string temp = vector_of_arguments[i].substr(vector_of_arguments[i].find_last_of('-') + 1, vector_of_arguments[i].size()).c_str();
            for (int h = 0; h < temp.size(); h++) {
                for (int j = 0; j < list_of_flags_.size(); j++) {
                    if (list_of_flags_[j].GetShortName() == temp[h]) {
                        list_of_flags_[j].ChangeStoreValue();
                        list_of_flags_[j].SetIsFound(true);
                    }
                }
            }
        } else if (!is_passed) {

            for (int j = 0; j < list_of_string_arguments.size(); j++) {
                if (list_of_string_arguments[j].GetIsPosition()) {
                    if (list_of_string_arguments[j].GetIsMulti()) {
                        list_of_string_arguments[j].SetMultiArguments(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].SetMultiArgumentsStore(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].AddRealAmount();
                        list_of_string_arguments[j].SetWasUsed();
                        is_passed = true;
                    } else {
                        if (list_of_string_arguments[j].GetSingleArgumentStore() != nullptr) {
                            list_of_string_arguments[j].SetSingleArgumentStore(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1,vector_of_arguments[i].size()));
                        }
                        list_of_string_arguments[j].SetSaveSingleArgument(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size()));
                        list_of_string_arguments[j].AddRealAmount();
                        list_of_string_arguments[j].SetWasUsed();
                        is_passed = true;
                    }
                }
            }

            for (int j = 0; j < list_of_int_arguments.size(); j++) {
                if (list_of_int_arguments[j].GetIsPosition()) {
                    if (list_of_int_arguments[j].GetIsMulti()) {
                        list_of_int_arguments[j].SetMultiArguments(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].SetMultiArgumentsStore(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].AddRealAmount();
                        list_of_int_arguments[j].SetWasUsed();
                        is_passed = true;
                    } else {
                        list_of_int_arguments[j].SetSaveSingleArgument(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].SetSingleArgumentStore(stoi(vector_of_arguments[i].substr(vector_of_arguments[i].find_first_of('=') + 1, vector_of_arguments[i].size())));
                        list_of_int_arguments[j].AddRealAmount();
                        list_of_int_arguments[j].SetWasUsed();
                        is_passed = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < list_of_string_arguments.size(); i++) {
        if (list_of_string_arguments[i].GetWasUsed()) {
            if (list_of_string_arguments[i].GetRealAmount() < list_of_string_arguments[i].GetMinArgumentsAmount()) {
                return false;
            }
        }
    }

    for (int i = 0; i < list_of_int_arguments.size(); i++) {
        if (list_of_int_arguments[i].GetWasUsed()) {
            if (list_of_int_arguments[i].GetRealAmount() < list_of_int_arguments[i].GetMinArgumentsAmount()) {
                return false;
            }
        }
    }


    if (!list_of_string_arguments.empty() && vector_of_arguments.size() == 1) {

        for (int i = 0; i < list_of_string_arguments.size(); i++) {
            if (list_of_string_arguments[i].GetRealAmount() == 0) {
                return false;
            }
        }

    } else if (!list_of_int_arguments.empty() && vector_of_arguments.size() == 1) {

        for (int i = 0; i < list_of_int_arguments.size(); i++) {
            if (list_of_int_arguments[i].GetRealAmount() == 0) {
                return false;
            }
        }

    } else if (!list_of_flags_.empty() && vector_of_arguments.size() == 1) {
        for (int i = 0; i < list_of_flags_.size(); i++) {
            if (!list_of_flags_[i].IsFound()) {
                return false;
            }
        }
    }

    return true;
}
