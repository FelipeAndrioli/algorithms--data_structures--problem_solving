#include <iostream>

#include "../Algorithms.h"

using namespace Algorithms;

class Algorithms::SortAlgorithms {
	public:
		void insertionSort(int *number_array, int array_size);
};

void SortAlgorithms::insertionSort(int *number_array, int array_size) {
	for(int i = 1; i < array_size; i++) {
		int key = number_array[i];
		int j = i - 1;

		while(j >= 0 && number_array[j] > key) {
			number_array[j + 1] = number_array[j];
			j--;
		}
		number_array[j + 1] = key;
	}
}
