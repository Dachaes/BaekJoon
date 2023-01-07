// BOJ_10996 : 별 찍기 21
#include <iostream>
using namespace std;

int i, j, N, N_MAX;
void Print_star21();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N;
    Print_star21();
    return 0;
}

void Print_star21(){
    if(N == 1)
        cout << "*" << endl;
    else if (N % 2 == 0){
        for(i = 0; i < N_MAX; i++){
            if(i % 2 == 0){
                for(j = 0; j < N - 1; j++){
                    if(j % 2 == 0)
                        cout << "*";
                    else
                        cout << " ";
                }
            }
            else{
                for(j = 0; j < N; j++){
                    if(j % 2 == 0)
                        cout << " ";
                    else
                        cout << "*";
                }
            }
            cout << endl;
        }
    }
    else{
        for(i = 0; i < N_MAX; i++){
            if(i % 2 == 0){
                for(j = 0; j < N; j++){
                    if(j % 2 == 0)
                        cout << "*";
                    else
                        cout << " ";
                }
            }
            else{
                for(j = 0; j < N - 1; j++){
                    if(j % 2 == 0)
                        cout << " ";
                    else
                        cout << "*";
                }
            }
            cout << endl;
        }
    }
}