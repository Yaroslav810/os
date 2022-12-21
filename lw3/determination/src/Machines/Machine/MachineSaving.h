#pragma once
#include "Machine.h"
#include <iostream>

constexpr char CSV_SEPARATOR = ';';

std::string GetStringFromSet(const std::set<std::string> &set) {
    std::string result;
    for (const auto &item: set) {
        result.append(item);
    }
    return result;
}

void SaveMachineToStreamAsCsv(std::ostream &output, const Machine &machine) {
    std::vector<std::vector<std::string>> table;

    for (const auto &path: machine.paths) {
        std::vector<std::string> line;
        for (const auto &item: machine.states) {
            line.emplace_back("");
        }
        table.push_back(line);
    }

    for (const auto &transitionItem: machine.transitions) {
        auto state = transitionItem.first;
        auto indexStateIt = std::find(machine.states.begin(), machine.states.end(), state);
        if (indexStateIt == machine.states.end()) {
            continue;
        }
        auto indexState = indexStateIt - machine.states.begin();
        for (const auto &item: transitionItem.second) {
            auto indexPathsIt = std::find(machine.paths.begin(), machine.paths.end(), item.first);
            if (indexPathsIt == machine.paths.end()) {
                continue;
            }

            auto indexPaths = indexPathsIt - machine.paths.begin();
            table[indexPaths][indexState] = GetStringFromSet(item.second);
        }
    }

    output << CSV_SEPARATOR;
    for (const auto &item: machine.states) {
        output << item << CSV_SEPARATOR;
    }
    output << std::endl;

    for (int i = 0; i < machine.paths.size(); ++i) {
        output << machine.paths[i] << CSV_SEPARATOR;
        for (auto &j: table[i]) {
            output << j << CSV_SEPARATOR;
        }
        output << std::endl;
    }

    output << std::endl;
}
