#ifndef MERGESORT_BU_H
#define MERGESORT_BU_H

#ifndef MERGER_H
#include "Merger.h"
#endif

using namespace std;


class Mergesort_BU: public Merger {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        sortArray(a, 0, n - 1);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, size_t left, size_t right) {
        mergeSort_BU(a);
    }

protected:
    template <typename T, size_t n>
    void mergeSort_BU(array<T, n> &a) {
        // Do lg N passes of pairwise merges.
        unique_ptr<array<T, n>> aux = make_unique <array<T, n>>();

        for (size_t sz = 1; sz < n; sz = sz + sz) {             // sz: subarray size
            //cout << "sz: " << setw(5) << sz << endl;
            for (size_t lo = 0; lo < n - sz; lo += sz + sz) {   // lo: subarray index
                mergeArrays(a, *aux, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
            }
        }
    }

};

#endif // MERGESORT_BU_H
