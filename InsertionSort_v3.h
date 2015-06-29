#ifndef INSERTION_SORT_v3_H
#define INSERTION_SORT_v3_H

using namespace std;

class InsertionSort_v3: public InsertionSort {

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
        T minimum = a[left];

        // Find the minimum
        for (size_t k = left + 1; k <= right; k++) {
            //cout << "k: " << k << setw(10) << "a[k]: " << a[k] << setw(10) << "minimum: " << minimum << endl;
            if (a[k] < minimum) {
                minimum = a[k];
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

#endif // INSERTION_SORT_v3_H
