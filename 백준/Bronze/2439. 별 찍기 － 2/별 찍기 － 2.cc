// BOJ_2439 : 별 찍기 2
#include <iostream>
using namespace std;

int i, j, k, N;
void Print_star2();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    Print_star2();
    return 0;
}

void Print_star2(){
    for(i = 0; i < N; i++){
        for(k = 0; k < N-i-1; k++)
            cout << " ";
        for(j = 0; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}