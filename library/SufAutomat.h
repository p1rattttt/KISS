//
// Created by Maxim Alexeev on 31.03.2022.
//
#pragma once
#include <vector>
#include <unordered_map>


struct sufAuto {
    struct Node {
        std::unordered_map<char, int64_t> to{};
        int64_t link = -1;
        int64_t len = 0;
        int64_t amount = 0;
        bool term = false;
    };

    std::vector<Node> cont = std::vector<Node>(1);
    int64_t last = 0;

    void addChar(char c);

    void finishBuild();

    void dfs(int64_t v);
};
