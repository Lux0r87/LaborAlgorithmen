#ifndef QUICKSORT_3WAY_PARTITIONING_H
#define QUICKSORT_3WAY_PARTITIONING_H

#define DEBUG 0

using namespace std;


class Quicksort_3WayPartitioning {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        sortArray(a, 0, n - 1);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, long left, long right) {
        quicksort_3WP(a, left, right);
    }

protected:
    template <typename T, size_t n>
    void quicksort_3WP(array<T, n> &a, long left, long right) {
        #if DEBUG
            cout << "left: " << setw(5) << left << endl;
            cout << "right: " << setw(4) << right << endl;
            print(a);
        #endif // DEBUG

        if (right <= left) {
            #if DEBUG
                cout << "-------------------------------------------------------------" << endl;
            #endif // DEBUG

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

        for (long k = left; k < p; k++, j--){
            swap(a[k], a[j]);
        }

        for (long k = right - 1; k > q; k--, i++){
            swap(a[i], a[k]);
        }

        #if DEBUG
            print(a);
            cout << "-------------------------------------------------------------" << endl;
        #endif // DEBUG

        quicksort_3WP(a, left, j);
        quicksort_3WP(a, i, right);
    }

    template <typename T, size_t n>
    void print(array<T, n> &arrayReference) {
        for(size_t i = 0; i < n; i++) {
            cout << arrayReference[i] << " ";
        }
        cout << endl;
    }

};

#endif // QUICKSORT_3WAY_PARTITIONING_H
