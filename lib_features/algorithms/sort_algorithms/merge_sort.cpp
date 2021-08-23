#include <iostream>

#include "../Algorithms.h"

using namespace Algorithms;

class Algorithms::SortAlgorithms {
    public:
        void merge(int *array, int begin, int middle, int end);
        void mergeSort(int *array, int begin, int end);
};

void merge(int* array, int begin, int middle, int end) {

    //Calculate sub arrays size
    int left_array_size = middle - begin + 1;
    int right_array_size = end - middle;

    //Create sub arrays
    int left_array[left_array_size]; 
    int right_array[right_array_size];

    //Fill sub arrays
    //left array is filled from beginning to middle
    for (int i = 0; i < left_array_size; i++) {
        left_array[i] = array[begin + i];
    }

    //right array is filled from middle to end
    for (int j = 0; j < right_array_size; j++) {
        right_array[j] = array[middle + 1 + j];
    }

    //create index to run through arrays
    int i = 0;
    int j = 0;
    int k = begin;

    //run subarrays, see what value is smaller and fill main array with it
    while (i < left_array_size && j < right_array_size) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    //Take remainings values, if there some, and add to the main array
    while (i < left_array_size) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    //Take remainings values, if there some, and add to the main array
    while (j < right_array_size) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void SortAlgorithms::mergeSort(int* array, int begin, int end) {

    /*
        Split array in half until remain only one value and then
        start to merge it in a ordered way
    */

    if (begin < end) {
        int middle = begin + (end - begin) / 2;

        mergeSort(array, begin, middle);
        mergeSort(array, middle + 1, end);

        merge(array, begin, middle, end);
    }
}