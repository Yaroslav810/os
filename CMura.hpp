#pragma once
#include "./utils.hpp"
#include "CMiles.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

class CMiles;

class CMura {
public:
    CMura() = default;

    void FromCSV(const std::string &csv) {
        std::cout << "Not implemented" << std::endl;
    }

    void FromData(const std::vector<std::string> &states,
                  const std::vector<std::string> &paths,
                  const std::vector<std::string> &output,
                  const std::vector<std::vector<std::string>> &transitions) {
        m_states = states;
        m_paths = paths;
        m_output = output;
        m_transitions = transitions;
    }

    std::string ConvertToCSV() {
        std::string csv;
        for (const auto &out: m_output) {
            csv.append(";" + out);
        }
        csv.append("\n");
        for (const auto &st: m_states) {
            csv.append(";" + st);
        }
        csv.append("\n");
        for (int i = 0; i < m_paths.size(); ++i) {
            csv.append(m_paths[i]);
            for (auto &j: m_transitions[i]) {
                csv.append(";" + j);
            }
            csv.append("\n");
        }
        return csv;
    }

    void ToMiles(CMiles &miles) {
        std::cout << "Not implemented" << std::endl;
    }

private:
    void ReadStatesCSV(const std::string &line) {
        std::cout << "Not implemented" << std::endl;
    }

    void ReadTransitionsCSV(const std::string &line) {
        std::cout << "Not implemented" << std::endl;
    }

    std::vector<std::string> m_states;
    std::vector<std::string> m_paths;
    std::vector<std::string> m_output;
    std::vector<std::vector<std::string>> m_transitions;
};
