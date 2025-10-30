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

    }

private:

    inline bool run(){
        return outputAssertion();
    }

    void printGottenOutput() const{
        Test::resultsOutput << "\tEXPECTED: " << this->expected << " ACTUAL: " << this->actual << endl;
    }

    bool outputAssertion() override{

        if(!Test::resultsOutput.is_open()){
            cerr << "Unloaded target file\n";
            return false;
        }

        if(this->testNumber != -1){
            Test::resultsOutput << "TEST NUM: " << this->testNumber << " | ";
        }

        Test::resultsOutput << this->testName;

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

    IntAssertDiffers(string testName, int expected, int actual)
            : Assertion(expected != actual, testName){

        this->expected = expected;
        this->actual = actual;

        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }
    }

    IntAssertDiffers(int testNum, string testName, int expected, int actual)
            : Assertion(expected != actual, testName, testNum){
        this->expected = expected;
        this->actual = actual;

        this->passed = this->assertedCondition;
        this->testNumber = testNum;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }

    }

private:

    inline bool run(){
        return outputAssertion();
    }

    void printGottenOutput() const{
        Test::resultsOutput << "\tEXPECTED: " << this->expected << " ACTUAL: " << this->actual << endl;
    }

    bool outputAssertion() override{

        if(!Test::resultsOutput.is_open()){
            cerr << "Unloaded target file\n";
            return false;
        }

        if(this->testNumber != -1){
            Test::resultsOutput << "TEST NUM: " << this->testNumber << " | ";
        }

        Test::resultsOutput << this->testName;

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


#endif //CPPT_INTASSERT_H
