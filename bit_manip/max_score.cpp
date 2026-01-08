#include<bits/stdc++.h>
using namespace std;

void swapValues(vector<vector<int>> &grid, int row, int column, int r){
    for(int j=0; j<column; j++) {
        if(grid[r][j] == 0) {
            grid[r][j] = 1;
        } else {
            grid[r][j] = 0;
        }
    }
    
}

void maximizeOnesColumn(vector<vector<int>> &grid, int colNum, int totalRows) {
    int count = 0;

    for(int i=0; i<totalRows; i++){
        if(grid[i][colNum] == 1){
            count++;
        }
    }

    if(count > (totalRows-count)){
        return ;
    } else {
        for(int i=0; i<totalRows; i++){
            grid[i][colNum] ^= 1;
         }
    }
}

int matrixScore(vector<vector<int>> &grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    
    for(int i=0; i<rowSize; i++) {
        if(grid[i][0] == 1){
            continue;
        } else {
            swapValues(grid,rowSize, colSize, i);
        }
    }
    
    // Make column 1's as maximum
    for(int j=1; j<colSize; j++){
        maximizeOnesColumn(grid, j, rowSize);
    }
    
    
    int totalSum = 0;
    for(int i=0;i<rowSize; i++){
        int rowSum = 0;
        int pow = 0;
        for(int j=0; j<colSize; j++) {
            cout << grid[i][j] << " ";
            rowSum += grid[i][j] * (1<<pow);
            pow++;
        }
        totalSum += rowSum;
        cout << endl;
    }

    return totalSum;
}

int main() {
    vector<vector<int>>grid = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};

    cout << matrixScore(grid);
    return 0;
}