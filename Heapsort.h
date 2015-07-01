#ifndef HEAPSORT_H
#define HEAPSORT_H

#define DEBUG 0

using namespace std;


class Heapsort {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        heapsort(a);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, long left, long right) {
        heapsort(a);
    }

protected:
    template<typename T>
    void maxHeapify(T *a, ptrdiff_t rootIndex, ptrdiff_t n) {
        ptrdiff_t childIndex = 2*rootIndex+1;
        while (childIndex <= n) {
            if (childIndex < n && a[childIndex+1] > a[childIndex]) {
                childIndex++;
            }

            if (a[childIndex] > a[rootIndex]) {
                swap(a[childIndex], a[rootIndex]);
            }

            rootIndex = childIndex;
            childIndex = 2*childIndex+1;
        }
    }

    template<typename T>
    void sortHeap(T *a, ptrdiff_t lastIndex) {
        for (ptrdiff_t i = lastIndex; i >= 1;) {
            swap(a[0], a[i--]);
            maxHeapify(a, 0, i);
        }
    }

    template<typename T>
    void buildMaxHeap(T *a, ptrdiff_t lastIndex) {
        for(ptrdiff_t i = (lastIndex-1)/2; i >= 0; i--) {
            maxHeapify(a, i, lastIndex);
        }
    }

    template<typename T, size_t n>
    void heapsort(array<T, n> &a) {
        buildMaxHeap(&a[0], n-1);
        sortHeap(&a[0], n-1);
    }

    template <typename T, size_t n>
    void print(array<T, n> &arrayReference) {
        for(size_t i = 0; i < n; i++) {
            cout << arrayReference[i] << " ";
        }
        cout << endl;
    }

};

#endif // HEAPSORT_H

