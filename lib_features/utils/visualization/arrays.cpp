#include <iostream>

#include "../Utils.h"

using namespace Utils;

void Visualization::showArray(int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i];
        std::cout << " ";
    }
    std::cout << std::endl;
}