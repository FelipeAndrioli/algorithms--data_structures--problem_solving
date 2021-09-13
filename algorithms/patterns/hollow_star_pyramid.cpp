#include <iostream>

void hollow_star_pyramid(int number_of_rows) {
    for (int i = 1; i <= number_of_rows; i++) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 1; j <= (2 * number_of_rows - 1); j++) {
            if (i == number_of_rows || j == 1 || j == 2 * i - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void inverted_hollow_star_pyramid(int number_of_rows) {
    for (int i = number_of_rows; i >= 1; i--) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            if (i == number_of_rows || j == 1 || j == 2 * i - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }
}

void full_hollow_star_pyramid(int number_of_rows) {
    for (int i = 1; i <= number_of_rows; i++) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 1; j <= (2 * number_of_rows - 1); j++) {
            if (j == 1 || j == 2 * i - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = number_of_rows - 1; i >= 1; i--) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }
}

int main() {

    int number_of_rows = 0;

    std::cout << "Enter the number of rows: ";
    std::cin >> number_of_rows;

    hollow_star_pyramid(number_of_rows);
    inverted_hollow_star_pyramid(number_of_rows);
    full_hollow_star_pyramid(number_of_rows);

    return 0;
}