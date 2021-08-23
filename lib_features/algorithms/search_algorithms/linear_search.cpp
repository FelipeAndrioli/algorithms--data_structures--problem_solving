#include <iostream>

#include "../Algorithms.h"

using namespace Algorithms;

int SearchAlgorithms::linearSearch(int *number_array, int array_size, int value) {
    int index = -1;

    for(int i = 0; i < array_size; i++) {
        if(number_array[i] == value) {
            index = i;
            return index;
        }
    }
    
    return index;
}