/*      
        Project:        eznet
        File Purpose:   Test Manager
        Author:         Nicholas Fortune
        Created:        31-12-2025
        First Release:  31-12-2025
        Updated:        --

        Description:    A test manager to run all tests for the neural network's logic

        Notes:          --

        -------------------------------------

        © Nicholas Fortune 2025, all rights reserved.
*/

#include "iostream"
#include "../tests/main.h"
#include "../tests/binary.h"
#include "../tests/network.h"

const int total_tests = 2;
int tests_passed = 0;
int tests_done = 0;

void all_tests() {
    tests_done++;
    std::cout << "\033[1mtest manager: (" << tests_done << "/" << total_tests << ") running binary tests\033[0m" << std::endl;
    if (binary()) {tests_passed++;}

    tests_done++;
    std::cout << "\033[1mtest manager: (" << tests_done << "/" << total_tests << ") running network tests\033[0m" << std::endl;
    if (network()) {tests_passed++;}
    

    if (tests_passed == total_tests) {
        std::cout << std::endl << "\033[1mtest manager:\033[0m all tests passed!" << std::endl << std::endl;
    } else {
        std::cout << std::endl << "\033[1mtest manager:\033[0m some tests finished with errors." << std::endl << std::endl;
    }
}