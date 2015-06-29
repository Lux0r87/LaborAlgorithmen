#ifndef INSERTION_SORT_v2_H
#define INSERTION_SORT_v2_H

using namespace std;

class InsertionSort_v2: public InsertionSort {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        sortArray(a, 0, n - 1);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, size_t left, size_t right) {
        insertionSort(a, left, right);
    }

protected:
    template <typename T, size_t n>
    void insertionSort(array<T, n> &a, size_t left, size_t right) {
        T minimum = a[right];

        // Find the minimum
        for (size_t k = right; k > left; k--) {
            //cout << "k-1: " << (k-1) << setw(10) << "a[k-1]: " << a[k-1] << setw(10) << "minimum: " << minimum << endl;
            if (a[k-1] < minimum) {
                minimum = a[k-1];
            }
        }

        // Swap the minimum with the most left element
        if (a[left] != minimum) {
            swap(a[left], minimum);
        }

        // Iterate over the elements from left to right
        for (size_t i = left + 1; i <= right; i++) {
            // Save current position
            T t = a[i];

            // Search a smaller value than t. Start at the current position and iterates from right to left.
            for (size_t j = i; a[j - 1] > t; j--) {
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
        }
    }

};

#endif // INSERTION_SORT_v2_H
