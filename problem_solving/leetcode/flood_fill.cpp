#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc, int currentColor, int newColor) {
    if (image[sr][sc] == currentColor) {
        image[sr][sc] = newColor;

        if (sr >= 1) {
            dfs(image, sr - 1, sc, currentColor, newColor);
        }
        
        if (sc >= 1) {
            dfs(image, sr, sc - 1, currentColor, newColor);
        }

        if (sr + 1 < image.size()) {
            dfs(image, sr + 1, sc, currentColor, newColor);
        }

        if (sc + 1 < image[0].size()) {
            dfs(image, sr, sc + 1, currentColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int currentColor = image[sr][sc];

    if (currentColor != newColor) {
        dfs(image, sr, sc, currentColor, newColor);
    }

    return image;
}

int main() {

    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    vector<vector<int>> new_image = floodFill(image, 1, 1, 2);


    for (int i = 0; i < new_image.size(); i++) {
        for (int j = 0; j < new_image[0].size(); j++) {
            cout << new_image[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}