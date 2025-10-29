//
// Created by ANBonin on 26/10/2025.
//

#ifndef CPPT_CPPTINIT_H
#define CPPT_CPPTINIT_H

#include <ctime>
#include <fstream>
#include <iostream>

#include "Controller.h"

using namespace std;

class CpptInit {
private:
    inline static bool initialized = false;

public:
    static void initialize(clock_t* clockSrc, ofstream* file); //Must be called before any tests can be executed

    static void wrapUp(clock_t* clockSrc, ofstream* file, double* elapsedTime); //Must be called after the tests are done

    static bool isInitialized(){
        return initialized;
    }
};


#endif //CPPT_CPPTINIT_H
