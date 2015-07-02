#ifndef HEAPSORT_BU_v2_H
#define HEAPSORT_BU_v2_H

#define DEBUG 0

using namespace std;


class Heapsort_BU_v2 {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        heapsort_BU_v2(a);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, long left, long right) {
        heapsort_BU_v2(a);
    }

protected:
    /*-----------------------------------------------------------------------*/
    /* The sift-up procedure sinks a hole from v[i] to leaf and then sifts   */
    /* the original v[i] element from the leaf level up. This is the main    */
    /* idea of bottom-up heapsort.                                           */
    /*-----------------------------------------------------------------------*/
    template<typename T, size_t n>
    void siftup(array<T, n> &a, size_t i, size_t nSize) {
        size_t start = i;
        T x = a[i];
        size_t j = i<<1;

        while (j <= nSize) {
            if (j < nSize && a[j] < a[j+1]) {
                j++;
            }

            a[i] = a[j];
            i = j;
            j = i<<1;
        }

        j = i>>1;

        while (j >= start) {
            if (a[j] < x) {
                a[i] = a[j];
                i = j;
                j = i>>1;
            } else {
                break;
            }
        }

        a[i] = x;
    }   /* End of siftup */

    /*----------------------------------------------------------------------*/
    /* The heapsort procedure; the original array is r[0..n-1], but here    */
    /* it is shifted to vector v[1..n], for convenience.                     */
    /*----------------------------------------------------------------------*/
    template <typename T, size_t n>
    void heapsort_BU_v2(array<T, n> &a) {
        /* Build the heap bottom-up, using siftup. */
        //for (size_t k = n>>1; k > 1; k--) {
        for (size_t k = (n-1); k > 0; k--) {
            siftup(a, k, n);
        }

        /* The main loop of sorting follows. The root is swapped with the last  */
        /* leaf after each sift-up. */
        //for (size_t k = n; k > 1; k--) {
        for (size_t k = (n-1); k > 0; k--) {
            siftup(a, 0, k);
            swap(a[0], a[k]);
          //x = v[k]; v[k] = v[1]; v[1] = x;
        }
    }   /* End of bottom_up_heapsort */

    template <typename T, size_t n>
    void print(array<T, n> &arrayReference) {
        for(size_t i = 0; i < n; i++) {
            cout << arrayReference[i] << " ";
        }
        cout << endl;
    }

};

#endif // HEAPSORT_BU_v2_H
