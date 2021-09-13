#include <iostream>

int main() {

    int number_of_rows = 0;

    std::cout << "Enter the number of rows: ";
    std::cin >> number_of_rows;

    for (int i = number_of_rows; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}