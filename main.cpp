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
#include "Mergesort_BU.h"
#include "Mergesort_Natural.h"
#include "Timer.h"

#include "BasicTest.h"
#include "TestSortAlgorithm.h"

#define BASIC_TEST 0
#define INSERTION_SORT_TEST 0
#define MERGESORT_TEST 1

using namespace std;

int main() {
    size_t startSize;
    size_t maxSteps;
    size_t runs = 1;

    #if BASIC_TEST
        freopen("BasicTest.txt", "w", stdout);
        BasicTest basicTest;
        basicTest.run();
    #endif // BASIC_TEST

    #if INSERTION_SORT_TEST
        maxSteps = 8;
        startSize = 500;

        unique_ptr<TestSortAlgorithm> testInsertionSort = make_unique <TestSortAlgorithm>();
        freopen("InsertionSort.txt", "w", stdout);
        testInsertionSort->measureTime<InsertionSort_v1>(startSize, maxSteps, runs);
        testInsertionSort->measureTime<InsertionSort_v2>(startSize, maxSteps, runs);
        testInsertionSort->measureTime<InsertionSort_v3>(startSize, maxSteps, runs);
    #endif // INSERTION_SORT_TEST

    #if MERGESORT_TEST
        maxSteps = 10;
        startSize = 16000;

        unique_ptr<TestSortAlgorithm> testMergesort = make_unique <TestSortAlgorithm>();
        freopen("Mergesort.txt", "w", stdout);
        testMergesort->measureTime<Mergesort_BU>(startSize, maxSteps, runs);
        testMergesort->measureTime<Mergesort_Natural>(startSize, maxSteps, runs);
    #endif // MERGESORT_TEST

    return 0;
}
