// BOJ_10990 : 별 찍기 15
#include <iostream>
using namespace std;

int i, j, Space_L, Space_M, N, N_MAX;
void Print_star15();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Space_L = N-1;
    Space_M = 1;
    Print_star15();
    return 0;
}

void Print_star15(){
    for(i = 0; i < N; i++){
        if(i == 0){
            for(j = 0; j < Space_L; j++){
                cout << " ";
            }
            cout << "*";
            Space_L--;
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