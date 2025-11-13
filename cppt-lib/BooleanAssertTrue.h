//
// Created by ANBonin on 30/10/2025.
//

#ifndef CPPT_BOOLEANASSERT_H
#define CPPT_BOOLEANASSERT_H

#include "cppt-core/Assertion.h"

class BooleanAssertTrue : public Assertion{
public:
    BooleanAssertTrue(int testNum, string testName, bool condition)
    : Assertion(condition, testName, testNum){
        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }
    }

    BooleanAssertTrue(string testName, bool condition)
            : Assertion(condition, testName){
        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }
    }


    bool passed;

private:


    bool run(){
        return outputAssertion();
    }

    bool outputAssertion(){
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
            Test::resultsOutput << "\tEXPECTED: true ACTUAL: false" << endl;
        }
        return true;
    }

};

#endif //CPPT_BOOLEANASSERT_H
