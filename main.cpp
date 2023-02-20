#include <iostream>
#include <fstream>
#include "matching.h"

int main() {
    int dept[5][5];
    int prog[5][5];
    int assignments[5] = {0,0,0,0,0};
    readFile("matching-data.txt", dept, prog);

    assignProgrammers(dept, prog, assignments);
    
    std::string s1 = "Department #";
    std::string s2 = " will get Programmer #";
    std::ofstream output("output.txt");
    for (int i = 0; i < 5; i++) {
        int d = i + 1;
        std::cout << s1 << d << s2 << assignments[i] << std::endl;
        output << s1 << d << s2 << assignments[i] << std::endl;
    }
    output.close();

    return 0;
}
