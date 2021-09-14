#include <iostream>

class StarPatterns {
    public:

        void half_star_pyramid(int number_of_rows);
        void inverted_half_star_pyramid(int number_of_rows);
        void full_star_diamond(int number_of_rows);
        void star_pyramid_pattern(int number_of_rows);
        void star_pyramid_pattern_variation(int number_of_rows);
        void inverted_star_pyramid_pattern(int number_of_rows);
        void inverted_star_pyramid_pattern_variation(int number_of_rows);
        void hollow_star_pyramid(int number_of_rows);
        void inverted_hollow_star_pyramid(int number_of_rows);
        void full_hollow_star_pyramid(int number_of_rows);        
        void right_half_star_diamond(int number_of_rows);
        void left_half_star_diamond(int number_of_rows);
};

void StarPatterns::half_star_pyramid(int number_of_rows) {
    for (int i = 1; i <= number_of_rows; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

void StarPatterns::inverted_half_star_pyramid(int number_of_rows) {
    for (int i = number_of_rows; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

void StarPatterns::full_star_diamond(int number_of_rows) {
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
}

void StarPatterns::star_pyramid_pattern(int number_of_rows) {
    for (int i = 1; i <= number_of_rows; i++) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 1; j <= (2 * i - 1); j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void StarPatterns::star_pyramid_pattern_variation(int number_of_rows) {
    for(int i = 1; i <= number_of_rows; i++) {
        for (int s = i; s < number_of_rows; s++) {
            std::cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }
}

void StarPatterns::inverted_star_pyramid_pattern(int number_of_rows) {
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

void StarPatterns::inverted_star_pyramid_pattern_variation(int number_of_rows) {
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

void StarPatterns::hollow_star_pyramid(int number_of_rows) {
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

void StarPatterns::inverted_hollow_star_pyramid(int number_of_rows) {
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

void StarPatterns::full_hollow_star_pyramid(int number_of_rows) {
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

void StarPatterns::right_half_star_diamond(int number_of_rows) {
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

void StarPatterns::left_half_star_diamond(int number_of_rows) {
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