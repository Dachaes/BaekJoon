// BOJ_10995 : 별 찍기 20
#include <iostream>
using namespace std;

int i, j, N, N_MAX;
void Print_star20();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N;
    Print_star20();
    return 0;
}

void Print_star20(){
    for(i = 0; i < N; i++){
        if(i % 2 == 0) {
            for(j = 0; j < N_MAX - 1; j++){
                if(j % 2 == 0)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        else{
            for(j = 0; j < N_MAX; j++){
                if(j % 2 == 0)
                    cout << " ";
                else
                    cout << "*";
            }
        }
        cout << endl;
    }
}