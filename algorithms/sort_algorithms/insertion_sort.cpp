#include <iostream>

void show_array(int number_array[], int array_size) {
	for(int i = 0; i < array_size; i++) {
		std::cout << number_array[i] << " ";
	}

	std::cout << std::endl;
}

void insertion_sort(int *number_array, int array_size) {
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

int main() {

	int number_array[] = {21, 42, 2, 5, 2, 4, 6, 1, 3};
	int array_size = sizeof(number_array) / sizeof(*number_array);

	show_array(number_array, array_size);
	insertion_sort(number_array, array_size);
	show_array(number_array, array_size);

	return 0;
}