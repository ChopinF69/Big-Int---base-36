//
// Created by lazar on 20.02.2024.
//
#include "big_int_general.h"
#include "tests.h"

int main()
{
    TestResults results = runAllTests();
    std::cout << "Total tests: " << results.totalTests << std::endl;
    std::cout << "Passed tests: " << results.passedTests << std::endl;


}