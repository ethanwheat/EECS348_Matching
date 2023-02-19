#include <iostream>
#include "matching.h"

int main() {
    int dept[5][5];
    int prog[5][5];
    readFile("matching-data.txt", dept, prog);
    std::cout << dept[4][2] << std::endl;
    std::cout << prog[3][3] << std::endl;

    return 0;
}
