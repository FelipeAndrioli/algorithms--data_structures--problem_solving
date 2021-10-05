#include <iostream>
#include <vector>

using namespace std;

void initialize_array(int n, int memo[]) {
    for (int i = 0; i < n; i++) {
        memo[i] = -1;
    }
}

void show_array(int n, int memo[]) {
    for (int i = 0; i < n; i++) {
        cout << memo[i] << " ";
    }

    cout << endl;
}

int fib(int n) {
    if (n == 0 || n == 1) {
        return  n;
    }

    return fib(n - 1) + fib(n - 2);
}

int fib_memoize(int n, int memo[]) {

    if (memo[n] != -1) {
        return memo[n];
    }

    if (n == 0 || n == 1) {
        memo[n] = n;
    } else {
        memo[n] = fib_memoize(n - 1, memo) + fib_memoize(n - 2, memo);
    }

    return memo[n];
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

    cout << "Enter the number to calculate F(n): ";
    cin >> n;

    int memo[n + 1] = {};

    initialize_array(n + 1, memo);
    cout << fib_memoize(n, memo) << endl;

    return 0;
}