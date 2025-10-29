//
// Created by ANBonin on 29/10/2025.
//

#ifndef CPPT_OBJECTASSERT_H
#define CPPT_OBJECTASSERT_H

#endif //CPPT_OBJECTASSERT_H

#include "cppt-core/Assertion.h"

namespace Value { //This has the Object Assertion accessing the object's stored value
    template<typename objT>
    class ObjectAssert : public Assertion {
    public:
        bool passed;

        bool identical(objT src, objT target) {

        }

        ObjectAssert(string testName, objT expected, objT actual)
                : Assertion(identical(expected, actual), testName) {
            this->passed = this->assertedCondition;
            this->actual = actual;
            this->expected = expected;

            if (!this->run()) {
                cerr << "Failed to push out assertion\n";
                exit(102);
            }
        }

        ObjectAssert(int testNum, string testName, objT expected, objT actual)
                : Assertion(identical(expected, actual), testName, testNum) {
            this->passed = this->assertedCondition;
            this->actual = actual;
            this->expected = expected;

            if (!this->run()) {
                cerr << "Failed to push out assertion\n";
                exit(102);
            }

            if (!this->assertedCondition) {
                printGottenOutput();
            }

        }

    protected:
        inline bool run() {
            return outputAssertion();
        }

        void printGottenOutput() const {

        }

        bool outputAssertion() override {
            if (!Test::resultsOutput.is_open()) {
                cerr << "Unloaded target file\n";
                return false;
            }

            Test::resultsOutput << this->testName;

            if (this->testNumber != -1) {
                Test::resultsOutput << " " << this->testNumber;
            }

            if (this->passed) {
                Test::resultsOutput << " " << "PASSED" << endl;
            } else {
                Test::resultsOutput << " " << "FAILED" << endl;
            }

            Test::resultsOutput.flush();

            return true;
        }

    private:
        objT expected;
        objT actual;
    };
}