//
// Created by Maxim Alexeev on 31.03.2022.
//

#include "Solver.h"

Solver::Solver(const std::string& FileName) {
    std::ifstream file;
    file.open(FileName);
    automat_.AddText(file);
    file.close();
}

int64_t Solver::FirstEntry(const std::string& query) {
    return automat_.FirstEntry(query);
}
