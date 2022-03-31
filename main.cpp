#include <iostream>
#include "library/Solver.h"

int main(int argc, char** argv) {
    Solver solver(argv[1]);
    std::string query;
    while (std::cin >> query) {
        std::cout << solver.FirstEntry(query) << std::endl;
    }
    return 0;
}
