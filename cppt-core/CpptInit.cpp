//
// Created by ANBonin on 26/10/2025.
//

#include "CpptInit.h"

void CpptInit::initialize(clock_t* clockSrc, ofstream* file){
    if(clockSrc != nullptr){
        cerr << "An invalid pointer-type clock controller was provided upon initializing the CPPT framework\n";
        exit(001);
    }

    clockSrc = new clock_t;
    *clockSrc = clock();

    if(!file->is_open()){
        cerr << "failed to load the storage file\n";
        exit(101);
    }

    Test::resetCounters();

    CpptInit::initialized = true;
}


void CpptInit::wrapUp(clock_t* clockSrc, ofstream* file, double* elapsedTime){
    if(clockSrc != nullptr) {
        clock_t endTime = clock();

        if (elapsedTime != nullptr) { //If elapsed time is not important, it can be passed as nullptr and won't be computed
            *elapsedTime = (double) (*clockSrc - endTime);
        }
    }
    file->close();

    if(file->is_open()){
        cerr << "Failed to close the output file\n";
        exit(102);
    }
}