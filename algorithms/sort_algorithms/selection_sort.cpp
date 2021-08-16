#include <iostream>

void show_array(int array_size, int array[]) {
    for(int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void selection_sort(int array_size, int *array) {

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

int main() {

    int number_array[] = {3, 4, 1, 5, 2};
    int array_size = sizeof(number_array) / sizeof(*number_array);

    show_array(array_size, number_array);
    selection_sort(array_size, number_array);
    show_array(array_size, number_array);

    return 0;
}