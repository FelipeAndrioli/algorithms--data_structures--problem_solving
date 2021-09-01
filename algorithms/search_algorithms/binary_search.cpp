#include <iostream>

int binary_search(int *array, int value, int left, int right) {

    int not_exist = -1;

    if (left > right) {
        return not_exist;
    }

    int mid = left + ((right - left) / 2);

    if (array[mid] == value) {
        return mid;
    } else if (array[mid] > value) {
        return binary_search(array, value, left, mid - 1);
    } else if (array[mid] < value) {
        return binary_search(array, value, mid + 1, right);
    }

    return not_exist;
}

int main() {

    int numbers_array[] = {1, 3, 4, 5, 13, 20, 25, 40, 42, 44, 53};
    int array_size = sizeof(numbers_array) / sizeof(*numbers_array);
    int value = 13;

    std::cout << array_size << std::endl;
    std::cout << "Looking for value " << value << std::endl;
    int result = binary_search(numbers_array, value, 0, array_size);

    if (result == -1) {
        std::cout << "Value does not exist in the array" << std::endl;
    } else {
        std::cout << "Value in position " << result << " of the array" << std::endl;
        std::cout << "Printing value " << result << " of the array => " << numbers_array[result] << std::endl;
    }

    return 0;
}