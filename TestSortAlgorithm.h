#ifndef TESTSORTALGORITHM_H
#define TESTSORTALGORITHM_H

using namespace std;

class TestSortAlgorithm: public BasicTest {

public:
    template<class T>
    void measureTime(size_t startSize, size_t maxSteps, size_t runs) {
        unique_ptr<T> sortAlgorithm = make_unique <T>();

        clearCache();
        size_t sizeOfArray = startSize;
        size_t steps = calculateSteps(startSize, maxSteps);

        cout << typeid(T).name() << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        cout << "steps: " << setw(3) << steps << endl;
        cout << "runs: " << setw(4) << runs << endl << endl;
        cout << setw(15) << "elements" << "| " << setw(15) << "ascending" << "| " << setw(15) << "descending" << "| " << setw(15) << "random" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for(size_t step = 1; step <= steps; step++) {
            cout << setw(15) << sizeOfArray;

            for(int mode = 0; mode < 3; mode++) {
                measuredTime = 0;

                for(size_t run = 0; run < runs; run++) {
                    init(mode, sizeOfArray);

                    try {
                        timer.reset();
                        sortAlgorithm->sortArray(*testArray, 0, sizeOfArray);
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
    }

};

#endif // TESTSORTALGORITHM_H
