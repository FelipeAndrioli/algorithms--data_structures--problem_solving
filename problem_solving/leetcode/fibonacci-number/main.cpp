#include <iostream>

int fib(int n) {
    if (n == 0 || n == 1) {
        return  n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {

    int n = 0;

    std::cout << "Enter the number to calculate F(n): ";
    std::cin >> n;

    std::cout << fib(n) << std::endl;

    return 0;
}