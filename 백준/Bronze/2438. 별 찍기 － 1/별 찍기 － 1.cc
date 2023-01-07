// BOJ_2438 : 별 찍기 1
#include <iostream>
using namespace std;

int i, j, N;
void Print_star();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    Print_star();
    return 0;
}

void Print_star(){
    for(i = 0; i < N; i++){
        for(j = 0; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}