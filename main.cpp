#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    string inputString1 = argv[1];
    ifstream inputFile1(inputString1);
    string inputString2 = argv[2];
    ifstream inputFile2(inputString2);
    string outputString = argv[3];
    ofstream outputFile(outputString);

    string myText;
    vector<vector<int>> inputVector2;
    vector<vector<int>> inputVector1;

    while (getline (inputFile1, myText)) {
        vector<int> inner1;
        stringstream ss1(myText);
        string parsed1;
        while (getline(ss1,parsed1,' ')){
            int i = atoi(parsed1.c_str());
            inner1.push_back(i);
        }
        inputVector1.push_back(inner1);
    }
    inputFile1.close();

    while (getline (inputFile2, myText)) {
        vector<int> inner2;
        stringstream ss2(myText);
        string parsed2;
        while (getline(ss2,parsed2,' ')){
            int i = atoi(parsed2.c_str());
            inner2.push_back(i);
        }
        inputVector2.push_back(inner2);
    }
    inputFile2.close();

    vector<vector<int>> map;
    vector<int> inner;
    for (int i = 0; i < inputVector1[0][0]; i++){
        inner.push_back(0);
    }
    for (int i = 0; i < inputVector1[0][0]; i++){
        map.push_back(inner);
    }
    inputVector1.erase(inputVector1.begin());
    for (vector<int> v: inputVector1) {
        int i = v[0];
        int row = v[1];
        int col = v[2];
        map[row][col] = i;
    }
    outputFile << "PART1:" << endl;
    for (vector<int> v: map) {
        for (int i: v) {
            outputFile << i << " ";
        }
        outputFile << endl;
    }
    outputFile<< endl;

    int point = 0;
    vector<vector<int>> mapVector;
    vector<vector<int>> commandVector;

    for (vector<int> v: inputVector2) {
        if (v.size() > 2) {
            mapVector.push_back(v);
        }
    }

    for (vector<int> v: inputVector2) {
        if (v.size() == 2) {
            commandVector.push_back(v);
        }
    }

    for (vector<int> v:commandVector) {
        int row = v[0];
        int col = v[1];
        point += mapVector[row][col];
        int counter = 0;
        for (int i = row+1; i <mapVector.size() ; i+= 1) {
            counter += 1;
            int j = col + counter;
            if (j < mapVector.size()) {
                if (mapVector[i][j] == mapVector[row][col]) {
                    point += mapVector[i][j];
                    mapVector[i][j] = 0;
                }
            }
        }
        counter = 0;
        for (int i = row-1; i <mapVector.size() ; i+= -1) {
            counter += 1;
            int j = col + counter;
            if (j < mapVector.size()) {
                if (mapVector[i][j] == mapVector[row][col]) {
                    point += mapVector[i][j];
                    mapVector[i][j] = 0;
                }
            }
        }
        counter = 0;
        for (int i = row-1; i <mapVector.size() ; i+= -1) {
            counter += 0;
            int j = col + counter;
            if (j < mapVector.size()) {
                if (mapVector[i][j] == mapVector[row][col]) {
                    point += mapVector[i][j];
                    mapVector[i][j] = 0;
                }
            }
        }
        counter = 0;
        for (int i = row+1; i <mapVector.size() ; i+= 1) {
            counter += 0;
            int j = col + counter;
            if (j < mapVector.size()) {
                if (mapVector[i][j] == mapVector[row][col]) {
                    point += mapVector[i][j];
                    mapVector[i][j] = 0;
                }
            }
        }
        counter = 0;
        for (int i = row-1; i <mapVector.size() ; i+= -1) {
            counter += -1;
            int j = col + counter;
            if (j < mapVector.size()) {
                if (mapVector[i][j] == mapVector[row][col]) {
                    point += mapVector[i][j];
                    mapVector[i][j] = 0;
                }
            }
        }
        counter = 0;
        for (int i = row+1; i <mapVector.size() ; i+= 1) {
            counter += -1;
            int j = col + counter;
            if (j < mapVector.size()) {
                if (mapVector[i][j] == mapVector[row][col]) {
                    point += mapVector[i][j];
                    mapVector[i][j] = 0;
                }
            }
        }
        counter = 0;
        for (int i = col-1; i <mapVector.size() ; i+= -1) {
            counter += 0;
            int j = row + counter;
            if (j < mapVector.size()) {
                if (mapVector[j][i] == mapVector[row][col]) {
                    point += mapVector[j][i];
                    mapVector[j][i] = 0;
                }
            }
        }
        counter = 0;
        for (int i = col+1; i <mapVector.size() ; i+= 1) {
            counter += 0;
            int j = row + counter;
            if (j < mapVector.size()) {
                if (mapVector[j][i] == mapVector[row][col]) {
                    point += mapVector[j][i];
                    mapVector[j][i] = 0;
                }
            }
        }
        mapVector[row][col] = 0;
    }

    outputFile << "PART2:" << endl;
    for (int i = 0; i < mapVector.size(); i++) {
        for (int j = 0; j < mapVector.size(); j++) {
            outputFile<<mapVector[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile << "Final Point: " << point << "p" << endl;
    outputFile.close();
        return 0;
}

