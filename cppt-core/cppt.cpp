#include <iostream>
#include "cppt-core/Controller.h"
#include "cppt-examples/test1.h"
int main() {
    registerCases();
    Controller::runAllTests();
    return 0;
}
