#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "matching.h"

void readFile(const std::string& filename, int dept[5][5], int prog[5][5]) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) { 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                inputFile >> dept[j][i];
            }
    	}
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                inputFile >> prog[j][i];
            }
        }
        inputFile.close();
    }			
}

int inArray(int arr[5], int n) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] == n) {
            return 1;
        }
    }
    return 0;
}

int indexOf(int arr[5], int n) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] == n) {
            return i;
        }
    }
    return -1;
}

void changePriority(int arr[5][5], int dept) {
    for(int i = 0; i < 4; i++) {
        arr[dept][i] = arr[dept][i+1];
    }
    arr[dept][4] = 0;
}

void assignProgrammers(int dept[5][5], int prog[5][5], int assignments[5]) {
    int index = 0;
    while (inArray(assignments, 0)) {  // while not all dept's have programmers
        if (assignments[index] != 0) {  // if the current index has an assigned programmer
            if (index == 4) {
                index = 0;
            } else {                     
                ++index; }
        } else { // the current index doesn't have an assigned programmer
            if (inArray(assignments, dept[index][0])) {  // if the current dept's preferred is already assigned
                int pref_prog = dept[index][0] - 1;  // index of preferred programmer
                int cur_dept = indexOf(assignments, dept[index][0]);  // gets the index of current assignment
                int cur_priority = indexOf(prog[pref_prog], cur_dept + 1);  // gets programmers preference of cur
                int new_priority = indexOf(prog[pref_prog], index + 1);
                if (new_priority < cur_priority) {  // if the new spot is preferred by programmer
                    assignments[index] = dept[index][0];  // reassign programmer
                    assignments[cur_dept] = 0;  // remove old assignment
                    changePriority(dept, cur_dept);  // move to next preference
                } else {  // if current assignment preferred
                    changePriority(dept, index);  // move to next preference
                }
            } else {  // if the current dept's preferred is not yet assigned
                assignments[index] = dept[index][0];  // assign the programmer
            }
        }
    }
}
