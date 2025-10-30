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

bool test4(){
    return DoubleAssert("DoubleAssert Test", 2.00, 2.00).passed;
}

bool test5(){
    return DoubleAssert("DoubleAssert Failure", 2.00, 3.00).passed;
}

bool test6(){
    return DoubleAssert("DoubleAssert with integer", 2, 2.00).passed;
}

void registerCases(){ //Pushes the test cases to the function<bool()> queue
    Controller::addTestCase(test1);
    Controller::addTestCase(test2);
    Controller::addTestCase(test3);
    Controller::addTestCase(test4);
    Controller::addTestCase(test5);
    Controller::addTestCase(test6);
}


/*
 * Then inside main, call Controller::runAllTests();
 */