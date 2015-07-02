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
    template <typename T, size_t n>
    void maxHeapify(array<T, n> &a, size_t rootIndex, size_t lastIndex) {
        size_t childIndex = 2*rootIndex+1;

        while (childIndex <= lastIndex) {
            if (childIndex < lastIndex && a[childIndex+1] > a[childIndex]) {
                childIndex++;
            }

            if (a[childIndex] > a[rootIndex]) {
                swap(a[childIndex], a[rootIndex]);
            }

            rootIndex = childIndex;
            childIndex = 2*childIndex+1;
        }
    }

    template <typename T, size_t n>
    void sortHeap(array<T, n> &a, size_t lastIndex) {
        for (size_t i = lastIndex; i >= 1;) {
            swap(a[0], a[i--]);
            maxHeapify(a, 0, i);
        }
    }

    template <typename T, size_t n>
    void buildMaxHeap(array<T, n> &a, size_t lastIndex) {
        for(size_t i = (lastIndex-1)/2; i >= 0; i--) {
            maxHeapify(a, i, lastIndex);

            if (i == 0) {
                break;
            }
        }
    }

    template<typename T, size_t n>
    void heapsort(array<T, n> &a) {
        buildMaxHeap(a, n-1);
        sortHeap(a, n-1);
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

