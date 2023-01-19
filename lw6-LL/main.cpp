#include "src/Analysis.h"
#include "src/Args.h"
#include "src/Rules.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    auto args = ParseArgs(argc, argv);
    if (!args.has_value()) {
        std::cout << "No arguments" << std::endl;
        return 1;
    }

    std::ifstream input(args.value().input);
    auto rules = GetRulesTable();
    std::string line;
    while (getline(input, line)) {
        try {
            std::cout << "'" << line << "': is ";
            ProgramAnalysis(rules, line)
                    ? std::cout << "true" << std::endl
                    : std::cout << "false" << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
