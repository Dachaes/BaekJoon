#include <iostream>

using namespace std;

/*
  - 문제의 규칙 -
  1 :: 1(1), 2 :: 6(2~7), 3 :: 12(8~19), 4 :: 18(20~37), 5 :: 24(38~61)
  1 :: 1, 2 :: (6x0+1)~(6x1+1), 3 :: (6x1+2)~(6x3+1), 4 :: (6x3+2)~(6x6+1), 5 :: (6x6+2)~(6x10+1)
  나열 : 1 / 2,3,4,5,6,7 / 8,9,10,11,12,13,14,15,16,17,18,19 / 20,21,23 ...
  묶이는 갯수 : 1-6-12-18-24

*/

void in(int&);
void out(int);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int Room;
    in(Room);
    out(Room);

    return 0;
}

void in(int& a){
    int temp_a;
    cin >> temp_a;
    if (temp_a>=1 && temp_a<=1000000000)
        a = temp_a;
    else
        return;
}

void out(int a){
    int i = 1;                      // i = depth : 방의 깊이
    int b = 0; int c = 1;           // b = 6의 배수, c = 가장 큰 방
    
    while(1) {                      // i = 1,2, 3, 4, 5
        b = 6 * (i - 1);            // b = 0,6,12,18,24
        c += b;                     // c = 1,7,19,37,61
        if (a <= c) {
            cout << i << "\n";
            break;
        } else {
            i++;
        }
    }
}
