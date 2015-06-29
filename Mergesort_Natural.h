#ifndef MERGESORT_NATURAL_H
#define MERGESORT_NATURAL_H

#ifndef MERGER_H
#include "Merger.h"
#endif

using namespace std;


class Mergesort_Natural: public Merger {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        sortArray(a, 0, n - 1);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, size_t left, size_t right) {
        mergeSort_Natural(a, left, right);
    }

protected:
    template <typename T, size_t n>
    void mergeSort_Natural(array<T, n> &a, size_t left, size_t right) {
        bool sorted = false;
        size_t leftBound = left;
        size_t rightBound = right;
        size_t l = left;
        size_t r = right;
        unique_ptr<array<T, n>> aux = make_unique <array<T, n>>();

        do {
            sorted = true;
            leftBound = left;

            while (leftBound < rightBound) {
                l = leftBound;

                while ((l < rightBound) &&  (a[l] <= a[l + 1])) {
                    l++;
                }

                r = l + 1;

                while (((r == rightBound - 1) || (r < rightBound)) && (a[r] <= a[r + 1])) {
                    r++;
                }

                if (r <= rightBound) {
					mergeArrays(a, *aux, leftBound, l, r);
                    sorted = false;
                }

                leftBound = r + 1;
            }
        } while (!sorted);
    }

};

#endif // MERGESORT_NATURAL_H

