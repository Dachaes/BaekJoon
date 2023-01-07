// BOJ_2556 : 별 찍기 14
#include <iostream>
using namespace std;
int N;
char star[101][101];

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            star[i][j] = '*';
        }
    }
}

void out(){
    for(int i = 0; i < N; i++){      
        for(int j = 0; j < N; j++)
            cout << star[i][j];
        cout << endl;
    }
}

int main() {
    in();
    out();
    return 0;
}