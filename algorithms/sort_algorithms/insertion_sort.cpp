#include <iostream>

void show_array(int number_array[], int array_size) {
	for(int i = 0; i < array_size; i++) {
		std::cout << number_array[i] << " ";
	}

	std::cout << std::endl;
}

void insertion_sort(int *number_array, int array_size) {
	for(int j = 1; j < array_size; j++) {
		int key = number_array[j];
		int i = j - 1;

		while(i >= 0 && number_array[i] > key) {
			number_array[i + 1] = number_array[i];
			i--;
		}

		number_array[i + 1] = key;
	}
}

int main() {

	int number_array[] = {21, 42, 2, 5, 2, 4, 6, 1, 3};
	int array_size = sizeof(number_array) / sizeof(*number_array);

	show_array(number_array, array_size);
	insertion_sort(number_array, array_size);
	show_array(number_array, array_size);

	return 0;
}