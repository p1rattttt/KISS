//
// Created by Maxim Alexeev on 31.03.2022.
//
#pragma once
#include <string>

#include "SufAutomat.h"



class Solver {
public:
    explicit Solver(const std::string& FileName);
    int64_t FirstEntry(const std::string& query);
private:
    sufAuto automat_;
};
