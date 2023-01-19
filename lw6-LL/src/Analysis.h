#pragma once
#include "./Rule.h"
#include <iostream>
#include <stack>
#include <string>

bool ProgramAnalysis(std::vector<Rule> const &rules, std::string line) {
    std::stack<int> stack;
    int ruleIndex = 0;
    int chIndex = 0;

    while (true) {
        auto currentRule = rules.at(ruleIndex);
        auto symbol = (chIndex >= line.size()) ? '\0' : line[chIndex];
        auto guidingSymbols = rules[ruleIndex].guidingSymbols;
        auto found = std::find(guidingSymbols.begin(), guidingSymbols.end(), symbol) != guidingSymbols.end() || std::find(guidingSymbols.begin(), guidingSymbols.end(), '\n') != guidingSymbols.end();

        std::cout << symbol << ": " << (found ? "true" : "false") << " : " << ruleIndex << " | ";
        auto newQ = stack;
        while (!newQ.empty()) {
            std::cout << newQ.top() << " ";
            newQ.pop();
        }
        std::cout << " | " << line << std::endl;

        if (!found) {
            if (currentRule.error) {
                return false;
            }
            ruleIndex++;
            continue;
        }

        if (currentRule.isEnd) {
            break;
        }

        if (currentRule.shift) {
            chIndex++;
        }

        if (currentRule.addNextToStack) {
            stack.push(ruleIndex + 1);
        }

        if (currentRule.ptr != -1) {
            ruleIndex = currentRule.ptr;
        } else {
            if (stack.empty()) {
                return false;
            } else {
                ruleIndex = stack.top();
                stack.pop();
            }
        }
    }

    return true;
}
