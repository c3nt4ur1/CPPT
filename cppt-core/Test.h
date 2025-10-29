//
// Created by ANBonin on 27/10/2025.
//

#ifndef CPPT_TEST_H
#define CPPT_TEST_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Test {
public:

    Test(){
        if(!resultsOutput.is_open()) {
            openOutputFile();
        }
        if(!resultsOutput.is_open()){
            cerr << "Failed to open output file\n";
            exit(205);
        }
    }

    ~Test() = default;

    static void resetCounters(){
        passedTestCases = 0;
        failedTestCases = 0;
    }

    static void pushFinalResults(){

        if(!resultsOutput.is_open()){
            cerr << "Unreachable output file\n";
            exit(103);
        }

        resultsOutput <<
        "PASSED: " << passedTestCases <<
        " FAILED: " << failedTestCases <<
        " TOTAL: " << passedTestCases + failedTestCases << endl;

        resultsOutput.close();
    }

protected:
    inline static ofstream resultsOutput;
    inline static int passedTestCases = 0;
    inline static int failedTestCases = 0;

    static bool validate(){
        return resultsOutput.is_open();
    }

    inline static void openOutputFile(){
        resultsOutput.open("cppt.txt", ios::out | ios::trunc);
    }

friend class Controller;

};



#endif //CPPT_TEST_H
