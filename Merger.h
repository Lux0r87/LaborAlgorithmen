#ifndef MERGER_H
#define MERGER_H

#define DEBUG 0

using namespace std;

class Merger{

protected:
	template <typename T, size_t n>
    void mergeArrays(array<T, n> &a, array<T, n> &aux, size_t lo, size_t mid, size_t hi) {
        #if DEBUG
            cout << "lo: " << setw(5) << lo << endl;
            cout << "mid: " << setw(4) << mid << endl;
            cout << "hi: " << setw(5) << hi << endl;
            print(a);
        #endif // DEBUG

        // Merge a[lo..mid] with a[mid+1..hi].
        size_t i = lo;
        size_t j = mid + 1;

        // Copy a[lo..hi] to aux[lo..hi].
        for (size_t k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }

        // Merge back to a[lo..hi].
        for (size_t k = lo; k <= hi; k++) {
            if (i > mid) {                 // left half exhausted (take from the right)
                a[k] = aux[j++];
            }
            else if (j > hi ) {            // right half exhausted (take from the left)
                a[k] = aux[i++];
            }
            else if (aux[j] < aux[i]) {    // current key on right less than current key on left (take from the right)
                a[k] = aux[j++];
            }
            else {                         // current key on right greater than or equal to current key on left (take from the left)
                a[k] = aux[i++];
            }
        }

        #if DEBUG
            print(a);
            cout << "-------------------------------------------------------------" << endl;
        #endif // DEBUG
    }

    template <typename T, size_t n>
    void print(array<T, n> &arrayReference) {
        for(size_t i = 0; i < n; i++) {
            cout << arrayReference[i] << " ";
        }
        cout << endl;
    }
};

#endif //MERGER_H
