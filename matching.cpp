#include <iostream>
#include <fstream>
#include <string>
#include "matching.h"

void readFile(const std::string& filename, int dept[5][5], int prog[5][5]) {
	std::ifstream inputFile(filename);
	if (inputFile.is_open()) { 
        	for (int i = 0; i < 5; i++) {
            		for (int j = 0; j < 5; j++) {
                		inputFile >> dept[i][j];
            		}
        	}
        	for (int i = 0; i < 5; i++) {
            		for (int j = 0; j < 5; j++) {
                		inputFile >> prog[i][j];
            		}
        	}
        inputFile.close();
    }			
}
