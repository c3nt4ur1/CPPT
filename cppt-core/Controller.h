//
// Created by ANBonin on 26/10/2025.
//

#ifndef CPPT_CONTROLLER_H
#define CPPT_CONTROLLER_H
#endif

#include <functional>
#include <queue>
#include <utility>
#include "CpptInit.h"

using namespace std;

void registerTests(){}

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
            test_functions_queue.pop();

            testFunc();
        }

        Test::pushFinalResults();

    }

private:
    inline static queue<function<bool()>> test_functions_queue = *(new queue<function<bool()>>); //Important: Test must be a boolean function that receives no parameters
    inline static bool initialized = false;
};

typedef struct reg{
    explicit reg(const function<bool()>& testCase){
        Controller::addTestCase(testCase);
    }
}RegisterTest;