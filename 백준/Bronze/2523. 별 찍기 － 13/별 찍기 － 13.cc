// BOJ_2523 : 별 찍기 13
#include <iostream>
using namespace std;

int i, j, Star, N, N_MAX;
void Print_star13();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Star = 1;
    Print_star13();
    return 0;
}

void Print_star13(){
    for(i = 0; i < N_MAX; i++){
        if(i >= 0 && i < N-1){
            for(j = 0; j < Star; j++)
                cout << "*";
            Star++;
        }
        else if(i == N-1){
            Star--;
            for(j = 0; j < N; j++)
                cout << "*";
        }
        else{
            for(j = 0; j < Star; j++)
                cout << "*";
            Star--;
        }
        cout << endl;
    }
}