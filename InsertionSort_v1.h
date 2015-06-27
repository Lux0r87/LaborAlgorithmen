#ifndef INSERTION_SORT_v1_H
#define INSERTION_SORT_v1_H

using namespace std;

class InsertionSort_v1: public InsertionSort {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        sortArray(a, 0, n - 1);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, size_t left, size_t right) {
        runSortAlgorithm(a, left, right);
    }

protected:
    template <typename T, size_t n>
    void runSortAlgorithm(array<T, n> &a, size_t left, size_t right) {
        // Iterate over the elements from left to right
        for (size_t i = left + 1; i <= right; i++) {
            // Save current position
            T t = a[i];

            // Search a smaller value than t. Start at the current position and iterates from right to left.
            for (size_t j = i; j > left && a[j - 1] > t; j--) {
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
        }
    }

};

#endif // INSERTION_SORT_v1_H
