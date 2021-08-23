#include <iostream>

#include "../Algorithms.h"

using namespace Algorithms;

class Algorithms::SortAlgorithms {
    public:
        void selectionSort();
};

void SortAlgorithms::selectionSort(int *array, int array_size) {

    for (int i = 0; i < array_size; i++) {
        int smallest = i;

        for (int j = i + 1; j < array_size; j++) {
            if (array[j] < array[smallest]) {
                smallest = j;
            }
        }

        int temp = array[i];

        array[i] = array[smallest];
        array[smallest] = temp;
    }
}
