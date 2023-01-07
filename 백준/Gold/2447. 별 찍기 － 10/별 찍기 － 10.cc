// BOJ_2447 : 별 찍기 10
#include <iostream>
using namespace std;
// N: 입력 받은 3^k의 값
// N_side: k값, 즉 빈 사각형 공간의 한 변의 길이
int N, N_side;
char Star[6565][6565];

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_side = N / 3;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Star[i][j] = ' ';
        }
    }
}

void star10(int x, int y, int side){
bool exit = 0;
// Base case
    if(side == 1){
        exit = 1;
    }

// Exceptional case -> none
// Recursive case
    for(int i = 0; i < side + 2; i++)  {
        Star[x][y + i] = '*';
        Star[x + side + 1][y + i] = '*';
        Star[x + i][y] = '*';
        Star[x + i][y + side + 1] = '*';
    }
    x = (x + 1) / 3 - 1;
    y = (y + 1) / 3 - 1;
    side /= 3;
    
    if(exit == 0){
        for(int i = 0; i < 3; i++) {
            star10(x + i * N_side, y, side);
            star10(x, y + i * N_side, side); 
            star10(x + N_side * i, y + 2 * N_side, side);
            star10(x + 2 *N_side, y + N_side * i, side);
        }
    }   
    else
        return;
}

void out(){
    for(int i = 0; i < N; i++){      
        for(int j = 0; j < N; j++)
            cout << Star[i][j];
        cout << endl;
    }
}

int main() {
    in();
    star10(N_side - 1, N_side - 1, N_side);
    out();
    return 0;
}