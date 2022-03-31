//
// Created by Maxim Alexeev on 31.03.2022.
//

#include "SufAutomat.h"


void sufAuto::addChar(char c) {
    nodes_.emplace_back();
    nodes_.back().len = nodes_[last_].len + 1;
    int64_t current = (int64_t)nodes_.size() - 1;
    nodes_[current].first_entry = nodes_[current].len - 1;

    int64_t parent = last_;

    while (parent >= 0 && !nodes_[parent].to.count(c)) {
        nodes_[parent].to[c] = current;
        parent = nodes_[parent].link;
    }

    if (parent != -1) {
        int64_t q = nodes_[parent].to[c];
        if (nodes_[parent].len + 1 == nodes_[q].len) {
            nodes_[current].link = q;
        } else {
            nodes_.push_back(nodes_[q]);
            int64_t new_node = nodes_.size() - 1;
            nodes_[new_node].len = nodes_[parent].len + 1;
            nodes_[q].link = new_node;
            nodes_[current].link = new_node;
            while (parent >= 0 && nodes_[parent].to[c] == q) {
                nodes_[parent].to[c] = new_node;
                parent = nodes_[parent].link;
            }
        }
    } else {
        nodes_[current].link = 0;
    }
    last_ = current;
}

void sufAuto::AddText(std::ifstream& file) {
    char symbol;
    while (file.get(symbol)) {
        addChar(symbol);
    }
}

int64_t sufAuto::FirstEntry(const std::string& query) {
    int64_t current_node = 0;
    for (auto& symbol : query) {
        if (nodes_[current_node].to.count(symbol)) {
            current_node = nodes_[current_node].to[symbol];
        } else {
            return -1;
        }
    }
    int64_t first_entry = nodes_[current_node].len - static_cast<int64_t>(query.size()) + 1;
    return first_entry;
}
