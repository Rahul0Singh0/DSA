// Bitmasking with Backtracking
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<char>> grid;
int mask; // column check
int RDMask; // right diagonal check
int LDMask; // left diagonal check

bool canPlaceQueen(int row, int col, int n) {
    // column check
    int bit_pos_c = n-col-1; // this position check column is visited or not
    if(((1<<bit_pos_c) & mask) == 0) { // visited
        return false;
    }

    // left diagonal check
    int bit_pos_l = (row - col) + (n - 1); // this bit pos check left diagonal vis or not
    if(((1<<bit_pos_l) & LDMask) == 0) { // visited
        return false;
    }

    // right diagonal check
    int bit_pos_r = (row + col); // this bit pos check right diagonal vis or not
    if(((1<<bit_pos_r) & RDMask) > 0) { // visited
        return false;
    }

    return true;
}

void makeVis(int bit_pos_c, int bit_pos_l, int bit_pos_r) {
    mask = (mask ^ (1<<bit_pos_c)); 
    LDMask = (LDMask ^ (1<<bit_pos_l));
    RDMask = (RDMask ^ (1<<bit_pos_r));
}

void makeUnvis(int bit_pos_c, int bit_pos_l, int bit_pos_r) {
    mask = (mask | (1<<bit_pos_c)); 
    LDMask = (LDMask | (1<<bit_pos_l));
    RDMask = (RDMask | (1<<bit_pos_r));
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
        cout<<endl;
        return;
    }
    for(int col = 0; col < n; col++) {
        if(canPlaceQueen(row, col, n)) {
            makeVis(n-col-1, (row-col)+(n-1), (row+col));
            grid[row][col] = 'Q';
            f(row+1, n);
            grid[row][col] = '.'; // revert
            makeUnvis(n-col-1, (row-col)+(n-1), (row+col));
        }
    }
}

vector<vector<string>> nqueen(int n) {
    grid.clear();
    grid.resize(n, vector<char>(n, '.'));
    f(0, n);
}

int main() {
    int n;
    cin>>n;
    int t = 2*n-1; // total diagonals
    mask = (1<<n)-1;
    LDMask = (1<<t)-1;
    RDMask = (1<<t)-1;
    nqueen(n);
    return 0;
}