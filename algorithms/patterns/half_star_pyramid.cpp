#include <iostream>

int main() {

    int number_of_rows = 0;

    std::cout << "Enter the number of rows: ";
    std::cin >> number_of_rows;

    for (int i = 1; i <= number_of_rows; i++) {
        for (int j = 1; j <= i; j ++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}