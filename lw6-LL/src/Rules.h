#pragma once
#include "Rule.h"

std::vector<Rule> GetRulesTable() {
    std::vector<Rule> rules;
    rules.push_back({"EXP", {'-', '(', 'a', 'b', '8', '3'}, false, true, 1, false, false}); // 0
    rules.push_back({"T", {'-', '(', 'a', 'b', '8', '3'}, false, true, 3, true, false}); // 1
    rules.push_back({"EXP'", {'\n', ')', '+'}, false, true, 6, false, false}); // 2
    rules.push_back({"T", {'-', '(', 'a', 'b', '8', '3'}, false, true, 4, false, false}); // 3
    rules.push_back({"F", {'-', '(', 'a', 'b', '8', '3'}, false, true, 14, true, false}); // 4
    rules.push_back({"T'", {'\n', ')', '*', '+'}, false, true, 29, false, false}); // 5
    rules.push_back({"EXP'", {'\n'}, false, false, 9, false, false}); // 6
    rules.push_back({"EXP'", {')'}, false, false, 10, false, false}); // 7
    rules.push_back({"EXP'", {'+'}, false, true, 11, false, false}); // 8
    rules.push_back({"\n", {'\n'}, false, true, -1, false, true}); // 9
    rules.push_back({")", {')'}, false, true, -1, false, false}); // 10
    rules.push_back({"+", {'+'}, true, true, 12, false, false}); // 11
    rules.push_back({"T", {'-', '(', 'a', 'b', '8', '3'}, false, true, 13, true, false}); // 12
    rules.push_back({"EXP'", {'\n', ')', '+'}, false, true, 6, false, false}); // 13
    rules.push_back({"F", {'-'}, false, false, 20, false, false}); // 14
    rules.push_back({"F", {'('}, false, false, 22, false, false}); // 15
    rules.push_back({"F", {'a'}, false, false, 25, false, false}); // 16
    rules.push_back({"F", {'b'}, false, false, 26, false, false}); // 17
    rules.push_back({"F", {'8'}, false, false, 27, false, false}); // 18
    rules.push_back({"F", {'3'}, false, true, 28, false, false}); // 19
    rules.push_back({"-", {'-'}, true, true, 21, false, false}); // 20
    rules.push_back({"F", {'-', '(', 'a', 'b', '8', '3'}, false, true, 14, false, false}); // 21
    rules.push_back({"(", {'('}, true, true, 23, false, false}); // 22
    rules.push_back({"EXP", {'-', '(', 'a', 'b', '8', '3'}, false, true, 0, true, false}); // 23
    rules.push_back({")", {')'}, true, true, -1, false, false}); // 24
    rules.push_back({"a", {'a'}, true, true, -1, false, false}); // 25
    rules.push_back({"b", {'b'}, true, true, -1, false, false}); // 26
    rules.push_back({"8", {'8'}, true, true, -1, false, false}); // 27
    rules.push_back({"3", {'3'}, true, true, -1, false, false}); // 28
    rules.push_back({"T'", {'\n'}, false, false, 33, false, false}); // 29
    rules.push_back({"T'", {')'}, false, false, 34, false, false}); // 30
    rules.push_back({"T'", {'*'}, false, false, 35, false, false}); // 31
    rules.push_back({"T'", {'+'}, false, true, 38, false, false}); // 32
    rules.push_back({"\n", {'\n'}, false, true, -1, false, true}); // 33
    rules.push_back({")", {')'}, false, true, -1, false, false}); // 34
    rules.push_back({"*", {'*'}, true, true, 36, false, false}); // 35
    rules.push_back({"F", {'-', '(', 'a', 'b', '8', '3'}, false, true, 14, true, false}); // 36
    rules.push_back({"T'", {'\n', ')', '*', '+'}, false, true, 29, false, false}); // 37
    rules.push_back({"+", {'+'}, true, true, 39, false, false}); // 38
    rules.push_back({"T", {'-', '(', 'a', 'b', '8', '3'}, false, true, 3, true, false}); // 39
    rules.push_back({"EXP'", {'\n', ')', '+'}, false, true, 6, false, false}); // 40
    return rules;
}
