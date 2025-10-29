//
// Created by ANBonin on 29/10/2025.
//

#ifndef CPPT_TEST1_H
#define CPPT_TEST1_H

#endif //CPPT_TEST1_H

#include "CPPT.h"
bool test1(){
    return IntAssert("INT ASSERT PASS", 1, 1).passed;
}

bool test2(){
    return IntAssertDiffers("INT DIFFER", 5, 3).passed;
}

bool test3(){
    return IntAssert("INT ASSERT FAILURE", 5, 3).passed;
}


void registerCases(){ //Pushes the test cases to the function<bool()> queue
    Controller::addTestCase(test1);
    Controller::addTestCase(test2);
    Controller::addTestCase(test3);
}


/*
 * Then inside main, call Controller::runAllTests();
 */