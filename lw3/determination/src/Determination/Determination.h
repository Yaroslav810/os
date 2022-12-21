#pragma once
#include "../Common/CommonFunc.h"
#include "../Common/CommonType.h"
#include "../Machine/DeterministicMachine.h"
#include "../Machine/Machine.h"
#include <fstream>
#include <iostream>
#include <queue>

DeterministicMachine DeterminationLeft(const Machine &machine) {
    return DeterministicMachine{};
}

DeterministicMachine DeterminationRight(const Machine &machine) {
    DeterministicMachine deterministicMachine{};
    std::queue<std::set<std::string>> queue;
    if (!machine.states.empty()) {
        queue.push({machine.states[0]});
    }

    while (!queue.empty()) {
        auto item = queue.front();
        queue.pop();

        DeterministicMachineTransitionState tempTransitions;
        std::vector<std::set<std::string>> tempStates;
        for (const auto &it: item) {
            auto valueItem = machine.transitions.find(it);
            if (valueItem == machine.transitions.end()) {
                continue;
            }

            for (const auto &transitionItem: valueItem->second) {
                tempTransitions[transitionItem.first].insert(transitionItem.second.begin(), transitionItem.second.end());
            }
        }

        for (const auto &tempTransitionsItem: tempTransitions) {
            tempStates.push_back(tempTransitionsItem.second);
        }

        auto index = int(deterministicMachine.states.size());
        deterministicMachine.transitions[index] = tempTransitions;
        deterministicMachine.states.push_back(item);
        deterministicMachine.paths = machine.paths;

        for (const auto &tempStatesItem: tempStates) {
            if (std::find(deterministicMachine.states.begin(), deterministicMachine.states.end(), tempStatesItem) == deterministicMachine.states.end()) {
                queue.push(tempStatesItem);
            }
        }
    }
    return deterministicMachine;
}

Machine Determination(const Machine &machine, DeterminationType type) {
    auto result = type == DeterminationType::LEFT
                          ? DeterminationLeft(machine)
                          : DeterminationRight(machine);

    //    for (const auto &itemStates: result.states) {
    //        for (const auto &item: itemStates) {
    //            std::cout << item << "-";
    //        }
    //        std::cout << std::endl;
    //    }
    //    std::cout << "|||" << std::endl;
    //    for (const auto &item: result.paths) {
    //        std::cout << item << "-";
    //    }
    //    std::cout << std::endl;
    //    std::cout << "|||" << std::endl;
    //    for (const auto &[key, value]: result.transitions) {
    //        std::cout << key << ": " << std::endl;
    //        for (const auto &[k, v]: value) {
    //            std::cout << "- " << k << ": ";
    //            for (const auto &item: v) {
    //                std::cout << item << "|";
    //            }
    //            std::cout << std::endl;
    //        }
    //    }
    //    std::cout << "|||" << std::endl;

    return Machine{};
}
