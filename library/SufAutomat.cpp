//
// Created by Maxim Alexeev on 31.03.2022.
//

#include "SufAutomat.h"

void sufAuto::dfs(int64_t v) {
    if (cont[v].term) {
        assert(cont[v].amount == 0);
        cont[v].amount += 1;
    }
    for (auto& next : cont[v].to) {
        if (cont[next.second].amount == 0) {
            dfs(next.second);
        }
        cont[v].amount += cont[next.second].amount;
    }
}

void sufAuto::finishBuild() {
    long long p = last;
    while (p >= 0) {
        cont[p].term = true;
        p = cont[p].link;
    }
    dfs(0);
}

void sufAuto::addChar(char c) {
    cont.emplace_back();
    cont.back().len = cont[last].len + 1;
    int64_t cur = cont.size() - 1;

    int64_t p = last;

    while (p >= 0 && !cont[p].to.count(c)) {
        cont[p].to[c] = cur;
        p = cont[p].link;
    }

    if (p != -1) {
        int64_t q = cont[p].to[c];
        if (cont[p].len + 1 == cont[q].len) {
            cont[cur].link = q;
        } else {
            cont.push_back(cont[q]);
            int64_t new_node = cont.size() - 1;
            cont[new_node].len = cont[p].len + 1;
            cont[q].link = new_node;
            cont[cur].link = new_node;
            while (p >= 0 && cont[p].to[c] == q) {
                cont[p].to[c] = new_node;
                p = cont[p].link;
            }
        }
    } else {
        cont[cur].link = 0;
    }
    last = cur;
}