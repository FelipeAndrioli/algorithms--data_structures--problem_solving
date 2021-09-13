#include <iostream>

void inverted_star_pyramid_pattern(int number_of_rows) {
    for (int i = number_of_rows; i >= 0; i--) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 0; j < (2 * i - 1); j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}

void inverted_star_pyramid_pattern_variation(int number_of_rows) {
    for (int i = number_of_rows; i >= 0; i--) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 0; j < i; j++) {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }
}

int main() {

    int number_of_rows;

    std::cout << "Enter the number of lines: ";
    std::cin >> number_of_rows;

    inverted_star_pyramid_pattern(number_of_rows);
    inverted_star_pyramid_pattern_variation(number_of_rows);

    return 0;
}