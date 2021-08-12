#include <iostream>

void show_array(int array_size, int number_array[]) {
    for(int i = 0; i < array_size; i++) {
        std::cout << number_array[i] << " ";
    }
    std::cout << std::endl;
}

int linear_search(int array_size, int *number_array, int value) {
    int index = -1;

    for(int i = 0; i < array_size; i++) {
        if(number_array[i] == value) {
            index = i;
            return index;
        }
    }
    
    return index;
}

int main() {

    int number_array[] = {1, 2 , 3, 4, 5, 6, 7, 8, 9};
    int array_size = sizeof(number_array) / sizeof(*number_array);

    show_array(array_size, number_array);
    std::cout << linear_search(array_size, number_array, 7) << std::endl;

    return 0;
}