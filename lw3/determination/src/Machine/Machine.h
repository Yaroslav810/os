#pragma once
#include "../Common/CommonFunc.h"
#include "../Common/CommonType.h"
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

constexpr char SEPARATOR = '|';

using MachineTransitionState = std::unordered_map<std::string, std::set<std::string>>;

struct Machine {
    std::vector<std::string> states;
    std::vector<std::string> paths;
    std::unordered_map<std::string, MachineTransitionState> transitions;
};

void ParseTransition(const std::string &string, Machine &machine, DeterminationType type) {
    auto currentState = machine.states[machine.states.size() - 1];
    std::vector<std::string> transitions;
    Split(string, SEPARATOR, transitions);
    for (auto &item: transitions) {
        trim(item);
        std::string in;
        std::string st;
        if (type == DeterminationType::LEFT) {
            in = getString(item[item.size() - 1]);
            st = item.substr(0, item.size() - 1);
            machine.transitions[st][in].insert(currentState);
        } else {
            in = getString(item[0]);
            st = item.substr(1, item.size() - 1);
            machine.transitions[currentState][in].insert(st);
        }

        if (std::find(machine.paths.begin(), machine.paths.end(), in) == machine.paths.end()) {
            machine.paths.push_back(in);
        }
    }
}

Machine ParseMachineFromStream(std::istream &input, DeterminationType type) {
    Machine machine{};

    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string state;
        iss >> state;
        machine.states.push_back(state);

        std::string last;
        iss >> last;

        std::getline(iss, last);
        ParseTransition(last, machine, type);
    }
    machine.states.emplace_back("");

    return machine;
}
