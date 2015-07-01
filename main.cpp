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
#include "Quicksort_3WayPartitioning.h"
#include "Quicksort_Hybrid1.h"
#include "Quicksort_Hybrid2.h"
#include "Heapsort.h"
#include "Heapsort_BU.h"
#include "Timer.h"

#include "BasicTest.h"
#include "TestSortAlgorithm.h"

#define BASIC_TEST 1
#define INSERTION_SORT_TEST 0
#define MERGESORT_TEST 0
#define QUICKSORT_TEST 0
#define HEAPSORT_TEST 1

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

    #if QUICKSORT_TEST
        maxSteps = 3;
        startSize = 1000;

        unique_ptr<TestSortAlgorithm> testQuicksort = make_unique <TestSortAlgorithm>();
        freopen("Quicksort.txt", "w", stdout);
        testQuicksort->measureTime<Quicksort_3WayPartitioning>(startSize, maxSteps, runs);
        testQuicksort->measureTime<Quicksort_Hybrid1>(startSize, maxSteps, runs);
        testQuicksort->measureTime<Quicksort_Hybrid2>(startSize, maxSteps, runs);
    #endif // QUICKSORT_TEST

    #if HEAPSORT_TEST
        maxSteps = 10;
        startSize = 16000;

        unique_ptr<TestSortAlgorithm> testHeapsort = make_unique <TestSortAlgorithm>();
        freopen("Heapsort.txt", "w", stdout);
        testHeapsort->measureTime<Heapsort>(startSize, maxSteps, runs);
        //testHeapsort->measureTime<Heapsort_BU>(startSize, maxSteps, runs);
    #endif // HEAPSORT_TEST

    return 0;
}
