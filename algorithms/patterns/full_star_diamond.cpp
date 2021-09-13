#include <iostream>

int main() {

    int number_of_rows = 0;

    std::cout << "Enter the number of rows: ";
    std::cin >> number_of_rows;

    for (int i = 0; i <= number_of_rows; i++) {
        for (int s = number_of_rows; s > i; s--) {
            std::cout << " ";
        }

        for (int j = 0; j < i; j++) {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }

    for (int i = 1; i < number_of_rows; i++) {
        for (int s = 0; s < i; s++) {
            std::cout << " ";
        }

        for (int j = number_of_rows; j > i; j--) {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }

    return 0;
}