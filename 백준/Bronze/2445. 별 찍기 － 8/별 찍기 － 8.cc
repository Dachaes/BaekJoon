// BOJ_2445 : 별 찍기 8
#include <iostream>
using namespace std;

int i, j, Star, Space, N, N_MAX;
void Print_star8();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    N_MAX = 2*N - 1;
    Star = 1;
    Space = N_MAX - 1;
    Print_star8();
    return 0;
}

void Print_star8(){
    for(i = 0; i < N_MAX; i++){
        if(i >= 0 && i < N-1){
            for(j = 0; j < Star; j++)
                cout << "*";
            for(j = 0; j < Space; j++)
                cout << " ";
            for(j = 0; j < Star; j++)
                cout << "*";
            Star++;
            Space -= 2;
        }
        else if(i == N-1){
             for(j = 0; j <= N_MAX; j++)
                    cout << "*";
        }
        else{
            Star--;
            Space += 2;
            for(j = 0; j < Star; j++)
                cout << "*";
            for(j = 0; j < Space; j++)
                cout << " ";
            for(j = 0; j < Star; j++)
                cout << "*";
        }
        cout << endl;
    }
}