#ifndef TESTINSERTIONSORT_H
#define TESTINSERTIONSORT_H

using namespace std;

class TestInsertionSort: public BasicTest {

public:
    template<class T>
    void measureTime_InsertionSort(size_t startSize, size_t maxSteps, size_t runs) {
        unique_ptr<T> insertionSort = make_unique <T>();

        clearCache();
        size_t sizeOfArray = startSize;
        size_t steps = calculateSteps(startSize, maxSteps);

        cout << "Insertion Sort (" << typeid(T).name() << ")" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        cout << setiosflags(ios::fixed) << setprecision(DOUBLE_PRECISION) << left;
        cout << setw(8) << "steps: " << steps << endl;
        cout << setw(8) << "runs: " << runs << endl << endl;
        cout << setw(15) << "elements" << "| " << setw(15) << "random" << "| " << setw(15) << "ascending" << "| " << setw(15) << "descending" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for(size_t step = 1; step <= steps; step++) {
            cout << setw(15) << sizeOfArray;

            for(int mode = 0; mode < 3; mode++) {
                measuredTime = 0;

                for(size_t run = 0; run < runs; run++) {
                    init(mode, sizeOfArray);

                    try {
                        timer.reset();
                        insertionSort->sortArray(*testArray, 0, sizeOfArray);
                        measuredTime += timer.elapsed();
                    } catch(exception& ex) {
                        cerr << "Exception: " << ex.what() << " " << endl;
                        step = steps;
                        mode = 3;
                        break;
                    }

                    if(!isAscending(*testArray, 0, sizeOfArray)) {
                        cout << "| " << setw(15) << "Not ascending!";
                        step = steps;
                        mode = 3;
                        break;
                    }
                }

                cout << "| " << setw(15) << measuredTime / runs;
            }

            cout << endl;
            sizeOfArray = sizeOfArray * 2;
        }

        cout << endl << endl << endl;
        //delete insertionSort;
    }

};

#endif // TESTINSERTIONSORT_H
