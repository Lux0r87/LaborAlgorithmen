#include <iostream>
#include <array>
#include <chrono>
#include <random>
#include <stdio.h>
#include <time.h>
#include <typeinfo>
#include <iomanip>
#include <memory>

#include "InsertionSort.h"
#include "InsertionSort_v1.h"
#include "InsertionSort_v2.h"
#include "InsertionSort_v3.h"
#include "Timer.h"

#include "BasicTest.h"
#include "TestInsertionSort.h"

#define BASIC_TEST 1
#define INSERTION_SORT_TEST 1

using namespace std;

int main() {
    size_t startSize;
    size_t maxSteps;
    size_t runs = 1;

    #if BASIC_TEST
        //freopen("BasicTest.txt", "w", stdout);
        BasicTest basicTest;
        basicTest.run();
    #endif // BASIC_TEST

    maxSteps = 9;
    startSize = 500;

    #if INSERTION_SORT_TEST
        unique_ptr<TestInsertionSort> testInsertionSort = make_unique <TestInsertionSort>();
        freopen("InsertionSort.txt", "w", stdout);
        testInsertionSort->measureTime<InsertionSort_v1>(startSize, maxSteps, runs);
        testInsertionSort->measureTime<InsertionSort_v2>(startSize, maxSteps, runs);
        testInsertionSort->measureTime<InsertionSort_v3>(startSize, maxSteps, runs);
    #endif // INSERTION_SORT_TEST

    return 0;
}
