#ifndef BASICTEST_H
#define BASICTEST_H

#define CACHE_SIZE 20   // in megabytes
#define DOUBLE_PRECISION 8
#define INSERTION_SORT 0
#define MERGESORT 0
#define QUICKSORT 0
#define HEAPSORT 1

//#define ARRAY_SIZE     1000
//#define ARRAY_SIZE     2000
//#define ARRAY_SIZE     4000
//#define ARRAY_SIZE     8000
//#define ARRAY_SIZE    10000
//#define ARRAY_SIZE    16000
//#define ARRAY_SIZE    32000
//#define ARRAY_SIZE    64000
//#define ARRAY_SIZE   100000
//#define ARRAY_SIZE   128000
//#define ARRAY_SIZE   256000
//#define ARRAY_SIZE   512000
//#define ARRAY_SIZE   1024000
//#define ARRAY_SIZE   2048000
//#define ARRAY_SIZE   4096000
#define ARRAY_SIZE   8192000
//#define ARRAY_SIZE 10240000
//#define ARRAY_SIZE 20480000
//#define ARRAY_SIZE 40960000
//#define ARRAY_SIZE 81920000
//#define ARRAY_SIZE 163840000
//#define ARRAY_SIZE 327680000

using namespace std;


class BasicTest {

private:

    // INTEGER:
    array<int, 8> myArray;

    // uniform distribution
    array<int, 8> exampleArray { {5, 3, 1, 6, 4, 0, 2, 7} };
    //array<int, 8> exampleArray { {3, 5, 1, 6, 4, 0, 2, 7} };
    //array<int, 10> exampleArray { {9, 5, 3, 1, 6, 4, 0, 8, 2, 7} };
    //array<int, 20> exampleArray { {1, 9, 3, 2, 6, 4, 6, 8, 5, 3, 6, 8, 5, 6, 9, 2, 1, 7, 0, 4} };

    // left shifted
    //array<int, 20> exampleArray { {4, 7, 1, 0, 5, 0, 1, 0, 0, 1, 4, 2, 0, 0, 2, 2, 2, 2, 5, 3} };

    // right shifted
    //array<int, 20> exampleArray { {6, 6, 5, 4, 5, 9, 0, 9, 6, 7, 8, 2, 2, 9, 9, 9, 0, 9, 4, 5} };

    //array<int, 20> exampleArray { {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9} };
    //array<int, 20> exampleArray { {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9} };

    //array<int, 20> exampleArray { {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0} };
    //array<int, 20> exampleArray { {9, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0} };

    // DOUBLE:
    //array<double, 20> myArray;

    // uniform distribution
    //array<double, 20> exampleArray { {7.6, 8.0, 0.8, 2.2, 4.0, 0.2, 1.4, 8.1, 3.4, 6.0, 7.4, 3.1, 8.3, 6.8, 6.0, 1.8, 6.6, 6.9, 5.4, 8.5} };

    // left shifted
    //array<double, 20> exampleArray { {1.5, 1.3, 7.5, 5.6, 8.4, 2.5, 2.7, 7.8, 4.8, 8.4, 0.7, 0.0, 4.3, 3.0, 5.3, 6.8, 7.7, 7.8, 4.0, 0.1} };

    // right shifted
    //array<double, 20> exampleArray { {6.3, 1.2, 9.0, 2.2, 2.9, 8.9, 5.4, 1.2, 3.2, 7.4, 7.3, 0.4, 4.6, 8.2, 7.5, 9.0, 9.0, 4.6, 3.6, 2.9} };

    //array<double, 20> exampleArray { {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0} };
    //array<double, 20> exampleArray { {0.0, 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0, 4.0, 5.0, 5.0, 6.0, 6.0, 7.0, 7.0, 8.0, 8.0, 9.0, 9.0} };

    //array<double, 20> exampleArray { {9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0} };
    //array<double, 20> exampleArray { {9.0, 9.0, 8.0, 8.0, 7.0, 7.0, 6.0, 6.0, 5.0, 5.0, 4.0, 4.0, 3.0, 3.0, 2.0, 2.0, 1.0, 1.0, 0.0, 0.0} };

    // BOOLEAN
    //array<bool, 20> myArray;
    //array<bool, 20> exampleArray { {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false} };
    //array<bool, 20> exampleArray { {true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false} };
    //array<bool, 20> exampleArray { {false, true, false, true, false, true, true, false, false, false, true, false, false, true, false, true, true, true, false, true} };

    // CHARACTER
    //array<char, 20> myArray;
    //array<char, 20> exampleArray { {'r', 'A', 'u', 'i', 'P', 'y', 'q', 'F', 'i', 'd', 'K', 'F', 'v', 'h', 't', 'M', 'z', 'g', 'E', 'c'} };

    // STRING
    //array<string, 20> myArray;
    //array<string, 20> exampleArray { {"r", "A", "u", "i", "P", "y", "q", "F", "i", "d", "K", "F", "v", "h", "t", "M", "z", "g", "E", "c"} };

public:
    //array<double, ARRAY_SIZE>* testArray = new array<double, ARRAY_SIZE>();
    //shared_ptr<array<double, ARRAY_SIZE>> testArray = make_shared <array<double, ARRAY_SIZE>>();
    unique_ptr<array<double, ARRAY_SIZE>> testArray = make_unique <array<double, ARRAY_SIZE>>();
    Timer timer;
    double measuredTime = 0;

    template <typename T, size_t n>
    void fillArray(array<T, n> &arrayReference) {
        for(size_t i = 0; i < n; i++){
            arrayReference[i] = exampleArray[i];
        }
    }

    void setTestArray(array<double, ARRAY_SIZE> &a) {
        *testArray = a;
    }

    void clearCache() {
        try{
            unsigned int number = (CACHE_SIZE * 1024 * 1024) / sizeof(int);
            //cout << "number: " << number << " " << endl;

            //int* cache = new int[number];
            //unique_ptr<int[]> cache(new int[number]);
            unique_ptr<int[]> cache = make_unique <int[]>(number);
            //cout << "size of cache: " << (sizeof(cache) / sizeof(cache[0])) << endl;

            // Initialize the pseudo-random number generator
            srand (time(NULL));

            for (size_t i = 0; i < number; i++) {
                //int old = b[i];
                cache[i] =  rand();
                //cout << i << ": " << old << " --> " << b[i] << endl;
            }

            //delete[] cache;
        }catch(exception& ex){
            cerr << "Exception: " << ex.what() << " " << endl;
        }
    }

    template <typename T, size_t n>
    void print(array<T, n> &arrayReference) {
        for(size_t i = 0; i < n; i++) {
            cout << arrayReference[i] << " ";
        }
        cout << endl;
    }

    template <size_t n>
    void randomDouble(array<double, n> &arrayReference, size_t sizeOfArray) {
		default_random_engine generator;
		uniform_real_distribution<double> dist(-999999999, 999999999);

		for (size_t i = 0; i < sizeOfArray; i++) {
			arrayReference[i] = dist(generator);
		}
    }

    template <size_t n>
    void descendingDouble(array<double, n> &arrayReference, size_t sizeOfArray) {
        for(size_t i = sizeOfArray; i > 0; i--) {
            arrayReference[i] = sizeOfArray - i;
        }
    }

    template <size_t n>
    void ascendingDouble(array<double, n> &arrayReference, size_t sizeOfArray) {
        for(size_t i = 0; i < sizeOfArray; i++) {
            arrayReference[i] = i;
        }
    }

    template <typename T, size_t n>
    bool isAscending(array<T, n> &arrayReference) {
        return isAscending(arrayReference, 0, n);
    }

    template <typename T, size_t n>
    bool isAscending(array<T, n> &arrayReference, size_t left, size_t right) {
        for(size_t i = left + 1; i < right; i++) {
            if(arrayReference[i-1] > arrayReference[i]) {
                return false;
            }
        }

        return true;
    }

    size_t calculateSteps(size_t startSize, size_t maxSteps) {
        size_t steps = 0;
        size_t value = startSize;

        while(steps < maxSteps && value <= ARRAY_SIZE) {
            steps++;
            value = value * 2;
        }

        return steps;
    }

    void init(unsigned int mode, size_t sizeOfArray) {
        switch(mode) {
            case 0:
                ascendingDouble(*testArray, sizeOfArray);
                break;
            case 1:
                descendingDouble(*testArray, sizeOfArray);
                break;
            case 2:
                randomDouble(*testArray, sizeOfArray);
                break;
        }
    }

    void run() {
        #if INSERTION_SORT
        {
            cout << "Insertion Sort v1" << endl;
            InsertionSort_v1 insertionSort_v1;
            fillArray(myArray);
            print(myArray);
            insertionSort_v1.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;

            cout << "Insertion Sort v2" << endl;
            InsertionSort_v2 insertionSort_v2;
            fillArray(myArray);
            print(myArray);
            insertionSort_v2.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;

            cout << "Insertion Sort v3" << endl;
            InsertionSort_v3 insertionSort_v3;
            fillArray(myArray);
            print(myArray);
            insertionSort_v3.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;
        }
        #endif // INSERTION_SORT

        #if MERGESORT
        {
            cout << "Mergesort: Buttom-up" << endl;
            Mergesort_BU mergesort_BU;
            fillArray(myArray);
            print(myArray);
            mergesort_BU.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;

            cout << "Mergesort: Natural" << endl;
            Mergesort_Natural mergesort_Natural;
            fillArray(myArray);
            print(myArray);
            mergesort_Natural.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;
        }
        #endif // MERGESORT

        #if QUICKSORT
        {
            cout << "Quicksort: 3-way partitioning" << endl;
            Quicksort_3WayPartitioning quicksort_3wp;
            fillArray(myArray);
            print(myArray);
            quicksort_3wp.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;

            cout << "Quicksort: Hybrid 1" << endl;
            Quicksort_Hybrid1 quicksort_hybrid1;
            fillArray(myArray);
            print(myArray);
            quicksort_hybrid1.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;

            cout << "Quicksort: Hybrid 2" << endl;
            Quicksort_Hybrid2 quicksort_hybrid2;
            fillArray(myArray);
            print(myArray);
            quicksort_hybrid2.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;
        }
        #endif // QUICKSORT

        #if HEAPSORT
        {
            cout << "Heapsort" << endl;
            Heapsort heapsort;
            fillArray(myArray);
            print(myArray);
            heapsort.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;

            /*cout << "Heapsort: Buttom-up" << endl;
            Heapsort_BU heapsort_BU;
            fillArray(myArray);
            print(myArray);
            heapsort_BU.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;

            cout << "Heapsort: Buttom-up v2" << endl;
            Heapsort_BU_v2 heapsort_BU_v2;
            fillArray(myArray);
            print(myArray);
            heapsort_BU_v2.sortArray(myArray);
            print(myArray);
            if(!isAscending(myArray)) {
                cout << "Not ascending!" << endl;
            }
            cout << endl;*/
        }
        #endif // HEAPSORT
    }

};

#endif // BASICTEST_H
