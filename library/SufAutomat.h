//
// Created by Maxim Alexeev on 31.03.2022.
//
#pragma once
#include <vector>
#include <unordered_map>
#include <fstream>


class sufAuto {
public:
    void AddText(std::ifstream& file);
    int64_t FirstEntry(const std::string& query);
private:
    void addChar(char c);
    struct Node {
        std::unordered_map<char, int64_t> to{};
        int64_t link = -1;
        int64_t len = 0;
        int64_t first_entry = 0;
    };
    std::vector<Node> nodes_{1};
    int64_t last_ = 0;
};
