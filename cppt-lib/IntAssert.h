//
// Created by ANBonin on 27/10/2025.
//

#ifndef CPPT_INTASSERT_H
#define CPPT_INTASSERT_H

#include "cppt-core/Assertion.h"

class IntAssert : public Assertion{
public:
    bool passed;

    IntAssert(string testName, int expected, int actual)
    : Assertion(expected == actual, testName){

        this->expected = expected;
        this->actual = actual;

        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }
    }

    IntAssert(int testNum, string testName, int expected, int actual)
    : Assertion(expected == actual, testName, testNum){
        this->expected = expected;
        this->actual = actual;

        this->passed = this->assertedCondition;
        this->testNumber = testNum;

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

        if(!Test::resultsOutput.is_open()){
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
            printGottenOutput();
        }

        return true;
    }

    int expected;
    int actual;

};

class IntAssertDiffers : public Assertion{
public:
    bool passed;

    IntAssertDiffers(string testName, int val1, int val2)
            : Assertion(val1 != val2, testName){

        this->expected = val1;
        this->actual = val2;

        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }
    }

    IntAssertDiffers(int testNum, string testName, int val1, int val2)
            : Assertion(val1 != val2, testName, testNum){
        this->expected = val1;
        this->actual = val2;

        this->passed = this->assertedCondition;
        this->testNumber = testNum;

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
        if(!Test::resultsOutput.is_open()){
            cerr << "Unloaded target file\n";
            return false;
        }

        if (Test::resultsOutput.fail()) {
            Test::resultsOutput.clear();
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

    int expected;
    int actual;

};

#endif //CPPT_INTASSERT_H
