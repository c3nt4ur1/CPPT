//
// Created by ANBonin on 26/10/2025.
//

#ifndef CPPT_ASSERTIONS_H
#define CPPT_ASSERTIONS_H

#include "CpptInit.h"
#include "Test.h"

class Assertion : public Test{
protected:
    string testName;
    bool assertedCondition;
    int testNumber = -1;

    Assertion(bool condition, string testName) : Test(){
        if(!Test::validate()){
            cerr << "Failed Test class validation\n";
            exit(201);
        }
        if(!CpptInit::isInitialized()){ //The CpptInit method already accounts for its own failures
            CpptInit::initialize(nullptr, &Test::resultsOutput); //nullptr should be latter changed to track clock time
        }

        this->assertedCondition = condition;
        this->testName = testName;

        if(this->assertedCondition){
            Test::passedTestCases++;
        }else{
            Test::failedTestCases++;
        }

    }

    Assertion(bool condition, string testName, int testNum) : Test(){
        if(!Test::validate()){
            cerr << "Failed Test class validation\n";
            exit(201);
        }
        if(!CpptInit::isInitialized()){
            CpptInit::initialize(nullptr, &Test::resultsOutput); //nullptr should be latter changed to track clock time
        }

        this->assertedCondition = condition;
        this->testName = testName;
        this->testNumber = testNum;

        if(this->assertedCondition){
            Test::passedTestCases++;
        }else{
            Test::failedTestCases++;
        }
    }

    virtual bool outputAssertion(){return false;}

};


#endif //CPPT_ASSERTIONS_H
