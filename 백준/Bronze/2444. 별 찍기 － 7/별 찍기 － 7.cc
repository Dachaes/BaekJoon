// BOJ_2444 : 별 찍기 7
#include <iostream>
using namespace std;

int i, j, N, N_MAX;
void Print_star7();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Print_star7();
    return 0;
}

void Print_star7(){
    for(i = 0; i < N_MAX; i++){
        if(i >= 0 && i < N-1){
            for(j = 0; j < (N_MAX+1)/2 + i; j++){
                if(j < N-(i+1))
                    cout << " ";
                else
                    cout << "*";
            }
        }
        else if(i == N-1){
             for(j = 0; j < N_MAX; j++)
                    cout << "*";
        }

        else{
            for(j = 0; j < N_MAX - (i - N + 1); j++){
                if (j >= i - N + 1)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}