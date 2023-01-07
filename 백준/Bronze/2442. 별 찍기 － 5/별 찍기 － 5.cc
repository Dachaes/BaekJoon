// BOJ_2442 : 별 찍기 5
#include <iostream>
using namespace std;

int i, j, N, N_MAX;
void Print_star5();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Print_star5();
    return 0;
}

void Print_star5(){
    for(i = 0; i < N; i++){
        for(j = 0; j < (N_MAX+1)/2 + i; j++){
            if (j >= N-i-1 && j <= N+i-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}