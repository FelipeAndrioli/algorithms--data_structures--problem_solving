#include <iostream>

void show_array(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(int *array, int array_size) {
    for (int i = 1; i < array_size; i++) {
        for (int j = 0; j < array_size - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {

    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array_size = sizeof(array) / sizeof(*array);

    show_array(array, array_size);
    bubble_sort(array, array_size);
    show_array(array, array_size);

    return 0;
}