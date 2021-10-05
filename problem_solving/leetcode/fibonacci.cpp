#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) {
        return  n;
    }

    return fib(n - 1) + fib(n - 2);
}

int fib_memoize() {
    return 0;
}

int fib_bottom_up() {
    return 0;
}

int main() {

    int n = 0;

    cout << "Enter the number to calculate F(n): ";
    cin >> n;

    return 0;
}