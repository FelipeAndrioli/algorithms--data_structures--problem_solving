#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int minSteps(int piles_size, int piles[]) {
    int steps = 0;

    sort(piles, piles_size + piles);

    if (piles_size == 0 || piles_size == 1 || piles[0] == piles[piles_size - 1]) {
        return 0;
    }

    for (int i = 1; i < piles_size; i++) {
        if (piles[piles_size - i - 1] != piles[piles_size - i]) {
            steps += i;
        }
    }
    
    return steps;;
}

int main() {

    /*
        Problem:

            Alexa is given n piles of equal or unequal heights. In one step, Alexa can remove 
            any number of boxes from the pile which has the maximum height and try to make it 
            equal to the one which is just lower than the maximum height of the stack. Determine 
            the minimum number of steps required to make all of the piles equal in height.

        Input: piles = [5, 2, 1]
        Output: 3
        Explanation:
        Step 1: reducing 5 -> 2 [2, 2, 1]
        Step 2: reducing 2 -> 1 [2, 1, 1]
        Step 3: reducing 2 -> 1 [1, 1, 1]
        So final number of steps required is 3.

        Solution:

            My first approach was a brute force, with the array sorted in a reverse way.

            A for loop were going to verify if the next number is smaller than the current one. If 
            it were smaller, then a while loop will loop through the array to remove units and add
            steps in the final result.

            This solution were not much efficient.

            The second approach was to compare if the last and highest element is different from the 
            previous element, if it was, than we sum the steps with the iterator, which is basically
            the number of steps we need to make the elements equal.

            The time complexity of this solution is O(N log N)
            
    */

    //int piles[] = {4, 4, 3, 3, 3, 2, 2, 2, 1, 1};
    int piles[] = {5, 2, 1};

    int piles_size = sizeof(piles) / sizeof(*piles);

    cout << minSteps(piles_size, piles) << endl;

    return 0;
}