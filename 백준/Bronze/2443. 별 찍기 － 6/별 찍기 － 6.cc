// BOJ_2443 : 별 찍기 6
#include <iostream>
using namespace std;

int i, j, N, N_MAX;
void Print_star6();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Print_star6();
    return 0;
}

void Print_star6(){
    for(i = 0; i < N; i++){
        for(j = 0; j < N_MAX - i; j++){
            if (j >= i && j <= N_MAX - i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}