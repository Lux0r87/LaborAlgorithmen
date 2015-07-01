#ifndef QUICKSORT_HYBRID2_H
#define QUICKSORT_HYBRID2_H

#ifndef INSERTION_SORT_v1_H
#include "InsertionSort_v1.h"
#endif // INSERTION_SORT_v1_H

#ifndef MERGER_H
#include "Merger.h"
#endif // MERGER_H

#define INSERTION_SORT_THRESHOLD 10

#define DEBUG 0

using namespace std;


class Quicksort_Hybrid2: public InsertionSort_v1, Mergesort_BU {
public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        sortArray(a, 0, n - 1);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, long left, long right) {
        quicksort(a, left, right);
    }

	template <typename T, size_t n>
	void quicksort(array<T, n> &a, long left, long right) {
	    #if DEBUG
            cout << "left: " << setw(5) << left << endl;
            cout << "right: " << setw(4) << right << endl;
            print(a);
        #endif // DEBUG

		if (right <= left + INSERTION_SORT_THRESHOLD) {
			insertionSort(a, left, right);
			return;
		}

		long i = left - 1;
		long j = right;
		long p = left - 1;
		long q = right;

		swap(a[(left + right) / 2], a[right]);
		T pivot = a[right];

		for (;;) {
			while (a[++i] < pivot);
			while (pivot < a[--j]) if (j == left) break;
			if (i >= j) break;
			swap(a[i], a[j]);

			if (a[i] == pivot) {
				p++;
				swap(a[p], a[i]);
			}

			if (pivot == a[j]) {
				q--;
				swap(a[j], a[q]);
			}
		}

		swap(a[i], a[right]);
		j = i - 1;
		i = i + 1;

		for (long k = left; k < p; k++, j--) {
			swap(a[k], a[j]);
		}

		for (long k = right - 1; k > q; k--, i++) {
			swap(a[i], a[k]);
		}

		long leftLength = i - left;
        long rightLength = right - j;

		if ((leftLength >= (rightLength * 10)) || (rightLength >= (leftLength * 10))) {
			size_t middle = left + ((right - left) / 2);
			quicksort(a, left, middle);
			quicksort(a, middle + 1, right);

			unique_ptr<array<T, n>> aux = make_unique <array<T, n>>();
			mergeArrays(a, *aux, left, middle, right);
		} else {
            quicksort(a, left, j);
            quicksort(a, i, right);
		}
	}
};

#endif // QUICKSORT_HYBRID2_H

