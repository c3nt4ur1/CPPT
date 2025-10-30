//
// Created by ANBonin on 29/10/2025.
//

#ifndef CPPT_DOUBLEASSERT_H
#define CPPT_DOUBLEASSERT_H

#endif //CPPT_DOUBLEASSERT_H
#include <cmath>

#include "cppt-core/Assertion.h"

//Considers a tolerance of 10^-10 in float point variations.
//For precise calculation testing, the constructor must be reimplemented

class DoubleAssert : public Assertion{

public:
    bool passed;

    DoubleAssert(string testName, double expected, double actual)
    : Assertion(std::fabs(expected - actual) < 1e-10, testName){

        this->expected = expected;
        this->actual = actual;

        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }
    }

    DoubleAssert(int testNum, string testName, double expected, double actual)
            : Assertion(std::fabs(expected - actual) < 1e-9, testName, testNum){
        this->expected = expected;
        this->actual = actual;

        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }

        if(!this->assertedCondition){
            printGottenOutput();
        }
    }

private:

    inline bool run(){
        return outputAssertion();
    }

    void printGottenOutput() const{
        Test::resultsOutput << "EXPECTED: " << this->expected << " ACTUAL: " << this->actual << endl;
    }

    bool outputAssertion() override{
        if(!Test::resultsOutput){
            cerr << "Unloaded target file\n";
            return false;
        }

        Test::resultsOutput << this->testName;
        if(this->testNumber != -1){
            Test::resultsOutput << " " << this->testNumber;
        }

        if(this->passed){
            Test::resultsOutput << " " << "PASSED" << endl;
        }else{
            Test::resultsOutput << " " << "FAILED" << endl;
        }

        return true;
    }

    double expected;
    double actual;

};