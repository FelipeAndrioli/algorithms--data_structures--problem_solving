#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int largestK(vector<int> array) {

    vector<int> sorted_array = array;
    sort(sorted_array.begin(), sorted_array.end());

    int i = 0;
    int j = sorted_array.size() - 1;

    while (i < j) {
        if (sorted_array[i] + sorted_array[j] == 0) {
            return sorted_array[j];
        } else if (abs(sorted_array[i]) > sorted_array[j]) {
            i++;
        } else if (abs(sorted_array[i]) < sorted_array[j]) {
            j--;
        }
    }

    return 0;
}

int main() {

    /*
        Problem:
            Write a function that, given an array A of N integers, returns the 
            lagest integer K > 0 such that both values K and -K exist in array A. 
            If there is no such integer, the function should return 0.

        Solution:
            My first approach was a brute force that with the first loop, keep track of a number
            and with the second loop, verify each value in the array and try to find a negative
            of this number. It wasn't efficient once it need to verify all the numbers multiple times, 
            with a time complexity of O(n^2)

            The second approach is to transform the array into a set and loop through it,
            if the absolute value is bigger than the largest and exist the same element but negative
            we add it to the largest. The solution is more efficient than the first one with a time
            complexity of O(n)

            There is also a third solution, where we sort the array, and sum the first element with the last,
            if is 0, means that one is positive and the other is negative, so it returns. Otherwise if is not 
            equal to 0, then we check, to see each is bigger to keep and iterate the other. The solution
            have a time complexity of O(n log n)
    */

    vector<int> array = {3, 2, -2, 5, -3};

    cout << largestK(array);

    return 0;
}