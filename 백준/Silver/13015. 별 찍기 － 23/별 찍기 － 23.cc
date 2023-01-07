// BOJ_13015 : 별 찍기 23
#include <iostream>
using namespace std;

int i, j, N, mid, mmid, seq;
void Print_FE();
void Print_Md1();
void Print_Md2();
void Print_Md();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    mid = N + 3*(N-1) - 2*N;
    seq = N - 2;
    Print_FE();
    Print_Md1();
    Print_Md();
    Print_Md2();
    Print_FE();

    return 0;
}

void Print_FE(){
    for(i = 0; i < N; i++)
        cout << "*";
    for(i = 0; i < mid; i++)
        cout << " ";
    for(i = 0; i < N; i++)
        cout << "*";
    cout << endl;
}

void Print_Md1(){
    mmid = mid;
    for(i = 0; i < seq; i++){
        for(j = 0; j < i+1; j++)
            cout << " ";
        cout << "*";
        for(j = 0; j < N-2; j++)
            cout << " ";
            cout << "*";
        mmid -= 2;
        for(j = 0; j < mmid; j++)
            cout << " ";
        cout << "*";
        for(j = 0; j < N-2; j++)
            cout << " ";
        cout << "*" << endl;    
    }
    
}

void Print_Md2(){
    mmid = mid;
    for(i = 0; i < seq; i++){
        for(j = 0; j < N-(i+1)-1; j++)
            cout << " ";
        cout << "*";
        for(j = 0; j < N-2; j++)
            cout << " ";
            cout << "*";
        mmid -= 2;
        for(j = 0; j < mid-mmid-1; j++)
            cout << " ";
        cout << "*";
        for(j = 0; j < N-2; j++)
            cout << " ";
        cout << "*" << endl;    
    }
    
}

void Print_Md(){
    for(i = 0; i < N-1; i++)
        cout << " ";
    cout << "*";
    for(i = 0; i < N-2; i++)
        cout << " ";
    cout << "*";
    for(i = 0; i < N-2; i++)
        cout << " ";
    cout << "*" << endl;
}