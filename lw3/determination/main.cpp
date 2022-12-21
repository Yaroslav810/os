#include "src/Args/Args.h"
#include "src/Determination/Determination.h"
#include "src/Machines/Machine/MachineParser.h"
#include "src/Machines/Machine/MachineSaving.h"
#include <iostream>

int main(int argc, char *argv[]) {
    try {
        auto args = ParseArgs(argc, argv);
        std::ifstream input(args.input);
        std::ofstream output(args.output);
        CheckFileOpen(input, output);
        auto machine = ParseMachineFromStream(input, args.type);
        machine = Determination(machine, args.type);
        for (const auto &item: machine.states) {
            std::cout << item << "-";
        }
        std::cout << std::endl;
        for (const auto &item: machine.paths) {
            std::cout << item << "-";
        }
        std::cout << std::endl;
        for (const auto &[key, value]: machine.transitions) {
            std::cout << key << ": " << std::endl;
            for (const auto &[k, v]: value) {
                std::cout << "- " << k << ": ";
                for (const auto &item: v) {
                    std::cout << item << "|";
                }
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
