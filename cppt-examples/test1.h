//
// Created by ANBonin on 29/10/2025.
//

#ifndef CPPT_TEST1_H
#define CPPT_TEST1_H

#endif //CPPT_TEST1_H

#include "CPPT.h"
bool test1(){

    return IntAssert("NONE", 1, 1).passed;

}

void registerCases(){ //Pushes the test cases to the function<bool()> queue
    RegisterTest test1_reg(&test1);
}


/*
 * Then inside main, call Controller::runAllTests();
 */