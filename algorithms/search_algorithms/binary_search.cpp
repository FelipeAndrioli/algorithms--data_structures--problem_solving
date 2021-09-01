#include <iostream>

int binary_search(int *array, int array_size, int value) {
    int index = -1;

    return index;
}

int main() {

    int numbers_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array_size = sizeof(numbers_array) / sizeof(*numbers_array);
    int value = 3;

    std::cout << "Looking for value " << value << std::endl;
    int result = binary_search(numbers_array, array_size, value);

    if (result == -1) {
        std::cout << "Value does not exist in the array" << std::endl;
    } else {
        std::cout << "Value in position " << result << " of the array" << std::endl;
    }

    return 0;
}