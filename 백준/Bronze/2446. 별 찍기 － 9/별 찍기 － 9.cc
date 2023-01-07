// BOJ_2446 : 별 찍기 9
#include <iostream>
using namespace std;

int i, j, Star, Space, N, N_MAX;
void Print_star9();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Star = N_MAX;
    Space = 0;
    Print_star9();
    return 0;
}

void Print_star9(){
    for(i = 0; i < N_MAX; i++){
        if(i >= 0 && i < N-1){
            for(j = 0; j < Space; j++)
                cout << " ";
            for(j = 0; j < Star; j++)
                cout << "*";
            Star -= 2;
            Space++;
        }
        else if(i == N-1){
            Star += 2;    Space--;
            for(j = 0; j < N-1; j++)
                cout << " ";
            cout << "*"; 
        }
        else{
            for(j = 0; j < Space; j++)
                cout << " ";
            for(j = 0; j < Star; j++)
                cout << "*";
            Star += 2;
            Space--;
        }
        cout << endl;
    }
}