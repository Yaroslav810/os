#pragma once
#include <vector>
#include <string>

struct Rule {
    std::string nonTerminal;
    std::vector<char> guidingSymbols;
    bool shift;
    bool error;
    int ptr;
    bool addNextToStack;
    bool isEnd;
};
