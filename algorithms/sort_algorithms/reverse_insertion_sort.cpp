#include <iostream>

void show_array(int n, int number_array[]) {
    for(int i = 0; i < n; i++) {
        std::cout << number_array[i] << " ";
    }
    std::cout << std::endl;
}

void reverse_insertion_sort(int n, int *number_array) {
    for(int i = 1; i < n; i++) {
        int key = number_array[i];
        int j = i - 1;

        while(j >= 0 && number_array[j] < key) {
            number_array[j + 1] = number_array[j];
            j--;
        }
        number_array[j + 1] = key;
    }
}

int main() {

    int number_array[] = {31, 41, 59, 26, 41, 58};
    int array_size = sizeof(number_array) / sizeof(*number_array);

    show_array(array_size, number_array);
    reverse_insertion_sort(array_size, number_array);
    show_array(array_size, number_array);

    return 0;
}