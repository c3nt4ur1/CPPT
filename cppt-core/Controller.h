//
// Created by ANBonin on 26/10/2025.
//

#ifndef CPPT_CONTROLLER_H
#define CPPT_CONTROLLER_H
#endif

#include <functional>
#include <queue>
#include <utility>
#include "Test.h"

using namespace std;

class Controller {
public:
    Controller()= default;

    ~Controller() = default;

    static void addTestCase(const function<bool()>& testCase){
        test_functions_queue.push(testCase);
    }

    static void runAllTests(){

        while(!test_functions_queue.empty()){
            function<bool()> testFunc = test_functions_queue.front();

            testFunc();
            test_functions_queue.pop();
        }

        Test::pushFinalResults();

    }

private:
    inline static queue<function<bool()>> test_functions_queue; //Important: Test must be a boolean function that receives no parameters
    inline static bool initialized = false;
};
