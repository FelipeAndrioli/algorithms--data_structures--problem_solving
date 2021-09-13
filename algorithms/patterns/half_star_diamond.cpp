#include <iostream>

void righ_half_star_diamond(int number_of_rows) {
    for (int i = 1; i <= number_of_rows; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = number_of_rows; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void left_half_star_diamond(int number_of_rows) {
    for (int i = 1; i <= number_of_rows; i++) {
        for (int s = number_of_rows; s > i; s--) {
            std::cout << " ";
        }

        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = number_of_rows; i > 0; i--) {
        for (int s = number_of_rows; s > i; s--) {
            std::cout << " ";
        }

        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {

    int number_of_rows = 0;

    std::cout << "Enter the number of rows: ";
    std::cin >> number_of_rows;

    //righ_half_star_diamond(number_of_rows);    
    left_half_star_diamond(number_of_rows);    

    return 0;
}