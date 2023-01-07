// BOJ_2441 : 별 찍기 4
#include <iostream>
using namespace std;

int i, j, N;
void Print_star4();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    Print_star4();
    return 0;
}

void Print_star4(){
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if (j < i)
                cout << " ";
            else
                cout << "*";
        }
        cout << endl;
    }
}