#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

using namespace std;

class InsertionSort {

public:
    //virtual ~InsertionSort();

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
    void insertionSort(array<T, n> &a, size_t left, size_t right) {};

};

#endif // INSERTION_SORT_H
