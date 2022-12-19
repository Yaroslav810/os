#pragma once
#include "../Common/CommonFunc.h"
#include "../Common/CommonType.h"
#include <fstream>
#include <iostream>

void DeterminationLeft(std::istream &input, std::ostream &output) {
    //
}

void DeterminationRight(std::istream &input, std::ostream &output) {
    //
}

void Determination(const std::string &inputFileName, const std::string &outputFileName, DeterminationType type) {
    std::ifstream input(inputFileName);
    std::ofstream output(outputFileName);
    CheckFileOpen(input, output);

    if (type == DeterminationType::LEFT) {
        DeterminationLeft(input, output);
    }
    if (type == DeterminationType::RIGHT) {
        DeterminationRight(input, output);
    }
}