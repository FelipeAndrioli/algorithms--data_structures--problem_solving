#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void calcArea(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int &area) {
    visited[i][j] = 1; 

    if (i + 1 >= 0 && i + 1 < grid.size() && j >= 0 && j < grid[0].size() && grid[i + 1][j] == 1 && visited[i + 1][j] == 0) {
        area++;
        calcArea(grid, visited, i + 1, j, area);
    }

    if (i - 1 >= 0 && i - 1 < grid.size() && j >= 0 && j < grid[0].size() && grid[i - 1][j] == 1 && visited[i - 1][j] == 0) {
        area++;
        calcArea(grid, visited, i - 1, j, area);
    }

    if (j + 1 >= 0 && j + 1 < grid[0].size() && i >= 0 && i < grid.size() && grid[i][j + 1] == 1 && visited[i][j + 1] == 0) {
        area++;
        calcArea(grid, visited, i, j + 1, area);
    }

    if (j - 1 >= 0 && j - 1 < grid[0].size() && i >= 0 && i < grid.size() && grid[i][j - 1] == 1 && visited[i][j - 1] == 0) {
        area++;
        calcArea(grid, visited, i, j - 1, area);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    int maxArea = 0;
    int tempArea;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (visited[i][j] == 0 && grid[i][j] == 1) {
                tempArea = 1; 
                calcArea(grid, visited, i, j, tempArea);
                maxArea = max(tempArea, maxArea);
            }
        }
    }

    return maxArea;
}

int main() {

    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    cout << maxAreaOfIsland(grid) << endl;

    return 0;
}