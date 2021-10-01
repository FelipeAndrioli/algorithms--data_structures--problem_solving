#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nextRound(int participants, int min_score_participant, int scores[]) {

    int next_round = 0;

    for (int i = 0; i < participants; i++) {
        if (scores[i] > 0 && scores[i] >= scores[min_score_participant - 1]) {
            next_round++;
        }
    }

    return next_round;
}

int main() {

    int n, k;

    cin >> n >> k;

    int scores[n];

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    cout << nextRound(n, k, scores) << endl;

    return 0;
}