// BOJ_10992 : 별 찍기 17
#include <iostream>
using namespace std;

int i, j, Space_L, Space_M, Star, N, N_MAX;
void Print_star17();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Star = 1;
    Space_L = N-1;
    Space_M = 1;
    Print_star17();
    return 0;
}

void Print_star17(){
    for(i = 0; i < N; i++){
        if(i == 0){
            for(j = 0; j < Space_L; j++){
                cout << " ";
            }
            cout << "*";
            Space_L--;
        }
        else if(i == N-1){
            for(j = 0; j < N_MAX; j++){
                cout << "*";
            }
        }
        else{
            for(j = 0; j < Space_L; j++){
                cout << " ";
            }
            cout << "*";
            for(j = 0; j < Space_M; j++){
                cout << " ";
            }
            cout << "*";
            Space_L--;  Space_M += 2;
        }
        cout << endl;
    }
}