// BOJ_10997 : 별 찍기 22
#include <iostream>
using namespace std;
// 1-1, 7-5, 11-9, 15-13
// 4n-1행, 4n-3열
int N, N_side_col, N_side_row;
char Star[400][400];

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    if(N != 1) N_side_col = 4 * N - 1;
    else N_side_col = 1;
    N_side_row = 4 * N - 3;
    for(int i = 0; i < N_side_col; i++){
        for(int j = 0; j < N_side_row; j++){
            Star[i][j] = ' ';
        }
    }
}

void star22(int x, int y, int col, int row){
// Base case
    if(col == 1){
        Star[x][y] = '*';
        return;
    }

// Exceptional case
    if(col == 7){
        Star[x + 2][y + 2] = Star[x + 4][y + 2] = '*';
    }
// Recursive case
    for(int i = 0; i < row; i++) Star[x][y + i] = '*';
    for(int i = 0; i < col; i++) Star[x + i][y] = '*';
    for(int i = 0; i < row; i++) Star[x + col - 1][y + i] = '*';
    for(int i = 2; i < col; i++) Star[x + i][y + row - 1] = '*';
    Star[x + 2][y + row - 2] = '*';
    y += 2;     row -= 4;
    if(col == 7)   {col -= 6; x += 3;}
    else                {col -= 4; x += 2;}

    star22(x, y, col, row);
}

void out(){
    for(int i = 0; i < N_side_col; i++){
        if (i == 1)     cout << Star[i][0];
        else {        
            for(int j = 0; j < N_side_row; j++)
                cout << Star[i][j];
        }
        cout << endl;
    }
}

int main() {
    in();
    star22(0, 0, N_side_col, N_side_row);
    out();
    return 0;
}