#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<string>> result;
vector<vector<char>> grid;

bool canPlaceQueen(int row, int col, int n) {
    // column check
    for(int i = row-1; i >= 0; i--) {
        if(grid[i][col] == 'Q') // we are attacked
            return false;
    }
    // left diagonal check
    for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--, j--) {
        if(grid[i][j] == 'Q') // we are attacked
            return false;
    }
    // right diagonal check
    for(int i = row-1, j = col+1; i >= 0 and j < n; i--, j++) {
        if(grid[i][j] == 'Q') // we are attacked
            return false;
    }
    return true;
}

void f(int row, int n) {
    if(row == n) {
        // we got one possible answer
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<grid[i][j];
            }
            cout<<"\n";
        }
        return;
    }
    for(int col = 0; col < n; col++) {
        if(canPlaceQueen(row, col, n)) {
            grid[row][col] = 'Q';
            f(row+1, n);
            grid[row][col] = '.'; // revert
        }
    }
}

vector<vector<string>> nqueen(int n) {
    grid.clear();
    result.clear();
    grid.resize(n, vector<char>(n, '.'));
    f(0, n);
}

int main() {
    int n;
    cin>>n;
    nqueen(n);
    return 0;
}