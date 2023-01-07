// BOJ_10991 : 별 찍기 16
#include <iostream>
using namespace std;

int i, j, Space, Star, N, N_MAX;
void Print_star16();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Star = 1;
    Space = N-1;
    Print_star16();
    return 0;
}

void Print_star16(){
    for(i = 0; i < N; i++){
        for(j = 0; j < Space; j++){
            cout << " ";
        }
        for(j = 0; j < Star; j++){
            if(j % 2 == 0)
                cout << "*";
            else
                cout << " ";
        }
        Space--;
        Star += 2;
        cout << endl;
    }
}