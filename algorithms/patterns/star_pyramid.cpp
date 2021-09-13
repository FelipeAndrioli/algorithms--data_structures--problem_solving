#include <iostream>

int main() {

    int number_of_rows;

    std::cout << "Enter the number of rows: ";
    std::cin >> number_of_rows;

    for (int i = 1; i <= number_of_rows; i++) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 1; j <= (2 * i - 1); j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}