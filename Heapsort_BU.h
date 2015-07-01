#ifndef HEAPSORT_BU_H
#define HEAPSORT_BU_H

#define DEBUG 0

using namespace std;


class Heapsort_BU {

public:
    template <typename T, size_t n>
    void sortArray(array<T, n> &a) {
        heapsort_BU(a);
    }

    template <typename T, size_t n>
    void sortArray(array<T, n> &a, long left, long right) {
        heapsort_BU(a);
    }

protected:
    template<typename T, size_t n>
    void heapsort_BU(array<T, n> &a) {
        int val, parent, child;
        int newN = n;
        int root = newN >> 1;                           // erstes Blatt im Baum

        for (;;) {
            if (root) {                                 // Teil 1: Konstruktion des Heaps
                parent = --root;
                val = a[root];                          // zu versickernder Wert
            } else if (--newN) {                        // Teil 2: eigentliche Sortierung
                val = a[newN];                          // zu versickernder Wert vom Heap-Ende
                a[newN]= a[0];                          // Spitze des Heaps hinter den Heap in
                parent= 0;                              // den sortierten Bereich verschieben
            } else {                                    // Heap ist leer; Sortierung beendet
                break;
            }

            while ((child = (parent + 1) << 1) < newN) {    // zweites (!) Kind; Abbruch am Ende des Heaps
                if (a[child-1] > a[child]) {                // gr��eres Kind w�hlen
                    --child;
                }

                a[parent]= a[child];                    // gr��eres Kind nach oben r�cken
                parent= child;                          // in der Ebene darunter weitersuchen
            }

            if (child == newN) {                        // ein einzelnes Kind am Heap-Ende ist �bersprungen worden
                if (a[--child] >= val) {                // gr��er als der zu versick-
                    a[parent]= a[child];                // ernde Wert, also noch nach oben
                    a[child]= val;                      // versickerten Wert eintragen
                    continue;
                }

                child = parent;                         // 1 Ebene nach oben zur�ck
            } else {
                if (a[parent] >= val) {                 // das Blatt ist gr��er als der
                    a[parent]= val;                     // zu versickernde Wert, der damit
                    continue;                           // direkt eingetragen werden kann
                }

                child = (parent - 1) >> 1;              // 2 Ebenen nach oben zur�ck
            }

            while (child != root) {                     // maximal zum Ausgangspunkt zur�ck
                parent= (child - 1) >> 1;               // den Vergleichswert haben wir bereits nach oben verschoben
                if (a[parent] >= val) {                 // gr��er als der zu versickernde
                    break;                              // Wert, also Position gefunden
                }

                a[child] = a[parent];                   // R�ckverschiebung n�tig
                child = parent;                         // 1 Ebene nach oben zur�ck
            }

            a[child]= val;                              // versickerten Wert eintragen
        }
    }

    template <typename T, size_t n>
    void print(array<T, n> &arrayReference) {
        for(size_t i = 0; i < n; i++) {
            cout << arrayReference[i] << " ";
        }
        cout << endl;
    }

};

#endif // HEAPSORT_BU_H
