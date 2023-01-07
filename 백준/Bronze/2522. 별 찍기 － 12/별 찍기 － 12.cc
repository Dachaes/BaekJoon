// BOJ_2522 : 별 찍기 12
#include <iostream>
using namespace std;

int i, j, Star, Space, N, N_MAX;
void Print_star12();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Star = 1;
    Space = N - 1;
    Print_star12();
    return 0;
}

void Print_star12(){
    for(i = 0; i < N_MAX; i++){
        if(i >= 0 && i < N-1){
            for(j = 0; j < Space; j++)
                cout << " ";
            for(j = 0; j < Star; j++)
                cout << "*";
            Star++;
            Space--;
        }
        else if(i == N-1){
            Star--;    Space++;
            for(j = 0; j < N; j++)
                cout << "*";
        }
        else{
            for(j = 0; j < Space; j++)
                cout << " ";
            for(j = 0; j < Star; j++)
                cout << "*";
            Star--;
            Space++;
        }
        cout << endl;
    }
}