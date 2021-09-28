#include <iostream>
 #include <limits.h>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int find_crossing_sum(int array[], int begin, int mid, int end) {
    
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = mid; i >= begin; i--) {
        sum += array[i];

        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;

    for (int i = mid + 1; i <= end; i++) {
        sum += array[i];

        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return max(left_sum + right_sum, left_sum, right_sum);
}

int find_max_subarray_sum(int array[], int begin, int end) {
    if (begin == end) {
        return array[begin];
    }

    int mid = (begin + end) / 2;

    /*
        Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum that the subarray crosses the midpoint
    */

   return max(  find_max_subarray_sum(array, begin, mid),
                find_max_subarray_sum(array, mid + 1, end),
                find_crossing_sum(array, begin, mid, end));
}

int main() {

    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int array_size = sizeof(array) / sizeof(*array);
    int max_sum = find_max_subarray_sum(array, 0, array_size - 1);

    cout << "Maximum contiguous sum is " << max_sum << endl;

    return 0;
}