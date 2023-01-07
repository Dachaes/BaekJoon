// BOJ_10994 : 별 찍기 19
#include <iostream>
using namespace std;

int N, N_side;
char Star[397][397];

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_side = 4 * N - 3;
    for(int i = 0; i < N_side; i++){
        for(int j = 0; j < N_side; j++){
            Star[i][j] = ' ';
        }
    }
}

void star19(int x, int y, int side){
// Base case
    if(side == 1){
        Star[x][y] = '*';
        return;
    }
    
// Recursive case
    for(int i = 0; i < side; i++) Star[x][y + i] = '*';
    for(int i = 0; i < side; i++) Star[x + i][y] = '*';
    for(int i = 0; i < side; i++) Star[x + side - 1][y + i] = '*';
    for(int i = 0; i < side; i++) Star[x + i][y + side - 1] = '*';
    x += 2;    y += 2;  side -= 4;
    star19(x, y, side);
}

void out(){
    for(int i = 0; i < N_side; i++){
        for(int j = 0; j < N_side; j++){
            cout << Star[i][j];
        }
        cout << endl;
    }
}

int main() {
    in();
    star19(0, 0, N_side);
    out();
    return 0;
}