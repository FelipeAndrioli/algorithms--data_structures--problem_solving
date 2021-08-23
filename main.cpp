#include <iostream>

#include "lib_features/algorithms/Algorithms.hpp"
#include "lib_features/utils/Utils.hpp"

int main() {

    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array_size = sizeof(array) / sizeof(*array);

    Algorithms::SortAlgorithms Sorting;
    Utils::Visualization Viweing;

    Viweing.showArray(array, array_size);
    //Sorting.mergeSort(array, 0, array_size);
    //Sorting.insertionSort(array, array_size);
    Sorting.selectionSort(array, array_size);
    Viweing.showArray(array, array_size);

    return 0;
}