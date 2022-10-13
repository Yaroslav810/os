#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void Split(std::string const &str, char separator, std::vector<std::string> &out) {
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, separator)) {
        out.push_back(s);
    }
}
