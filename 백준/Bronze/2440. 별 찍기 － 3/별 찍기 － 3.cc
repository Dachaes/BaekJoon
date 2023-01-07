// BOJ_2440 : 별 찍기 3
#include <iostream>
using namespace std;

int i, j, N;
void Print_star3();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    Print_star3();
    return 0;
}

void Print_star3(){
    for(i = 0; i < N; i++){
        for(j = 0; j < N-i; j++)
            cout << "*";
        cout << endl;
    }
}