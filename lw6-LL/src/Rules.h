#pragma once
#include "Rule.h"

std::vector<Rule> GetRulesTable() {
    std::vector<Rule> rules;
    rules.push_back({"EXP", {'-', '(', 'a', 'b', '8', '3'}, false, true, 1, false, false}); // 0
    rules.push_back({"T", {'-', '(', 'a', 'b', '8', '3'}, false, true, 3, true, false}); // 1
    rules.push_back({"EXP'", {'\n', '+'}, false, true, 6, false, false}); // 2
    rules.push_back({"T", {'-', '(', 'a', 'b', '8', '3'}, false, true, 4, false, false}); // 3
    rules.push_back({"F", {'-', '(', 'a', 'b', '8', '3'}, false, true, 12, true, false}); // 4
    rules.push_back({"T'", {'\n', '*'}, false, true, 27, false, false}); // 5
    rules.push_back({"EXP'", {'+'}, false, false, 9, false, false}); // 6
    rules.push_back({"EXP'", {'\n'}, false, true, 8, false, false}); // 7
    rules.push_back({"\n", {'\n'}, false, true, -1, false, true}); // 8
    rules.push_back({"+", {'+'}, true, true, 10, false, false}); // 9
    rules.push_back({"T", {'-', '(', 'a', 'b', '8', '3'}, false, true, 3, true, false}); // 10
    rules.push_back({"EXP'", {'\n', '+'}, false, true, 6, false, false}); // 11
    rules.push_back({"F", {'-'}, false, false, 18, false, false}); // 12
    rules.push_back({"F", {'('}, false, false, 20, false, false}); // 13
    rules.push_back({"F", {'a'}, false, false, 23, false, false}); // 14
    rules.push_back({"F", {'b'}, false, false, 24, false, false}); // 15
    rules.push_back({"F", {'8'}, false, false, 25, false, false}); // 16
    rules.push_back({"F", {'3'}, false, true, 26, false, false}); // 17
    rules.push_back({"-", {'-'}, true, true, 19, false, false}); // 18
    rules.push_back({"F", {'-', '(', 'a', 'b', '8', '3'}, false, true, 12, false, false}); // 19
    rules.push_back({"(", {'('}, true, true, 21, false, false}); // 20
    rules.push_back({"EXP", {'-', '(', 'a', 'b', '8', '3'}, false, true, 0, true, false}); // 21
    rules.push_back({")", {')'}, true, true, -1, false, false}); // 22
    rules.push_back({"a", {'a'}, true, true, -1, false, false}); // 23
    rules.push_back({"b", {'b'}, true, true, -1, false, false}); // 24
    rules.push_back({"8", {'8'}, true, true, -1, false, false}); // 25
    rules.push_back({"3", {'3'}, true, true, -1, false, false}); // 26
    rules.push_back({"T'", {'*'}, false, false, 30, false, false}); // 27
    rules.push_back({"T'", {'\n'}, false, true, 29, false, false}); // 28
    rules.push_back({"\n", {'\n'}, false, true, -1, false, false}); // 29
    rules.push_back({"*", {'*'}, true, true, 31, false, false}); // 30
    rules.push_back({"F", {'-', '(', 'a', 'b', '8', '3'}, false, true, 12, true, false}); // 31
    rules.push_back({"T'", {'\n', '*'}, false, true, 27, false, false}); // 32
    return rules;
}
