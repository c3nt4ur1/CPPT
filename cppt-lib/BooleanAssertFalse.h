//
// Created by ANBonin on 13/11/2025.
//

#ifndef CPPT_BOOLEANASSERTFALSE_H
#define CPPT_BOOLEANASSERTFALSE_H

#include "cppt-core/Assertion.h"

class BooleanAssertFalse : public Assertion{
public:
    BooleanAssertFalse(int testNum, string testName, bool condition)
            : Assertion(!condition, testName, testNum){ //The ! operator flip the false to true, setting passed == true
        this->passed = this->assertedCondition;

        if(!this->run()){
            cerr << "Failed to push out assertion\n";
            exit(102);
        }
    }

    BooleanAssertFalse(string testName, bool condition)
    : Assertion(!condition, testName){ //The ! operator flip the false to true, setting passed == true
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


#endif //CPPT_BOOLEANASSERTFALSE_H
