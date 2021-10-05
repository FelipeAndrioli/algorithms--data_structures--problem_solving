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

int fib_bottom_up(int n) {

    int memo[n] = {};

    if (n == 0 || n == 1) {
        return n;
    }

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

int main() {

    int n = 0;
    int memo[] = {};

    cout << "Enter the number to calculate F(n): ";
    cin >> n;

    cout << fib_bottom_up(n) << endl;

    return 0;
}