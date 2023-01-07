// BOJ_2164 : 카드2
/*
1                       1개
2                       1개 (2^0)
2 4                     2개 (2^1)
2 4 6 8                 4개 (2^2)
2 4 6 8 10 12 14 16     8개 (2^3)
카드의 개수 : 1 / 2 / 3 4 / 5 6 7 8 / 9 10 11 12 13 14 15 16 / 17 18 ...
           : 1 / 2 / 2 4 / 2 4 6 8 / 2  4  6  8 10 12 14 16 /  2  4 ...
*/

#include <iostream>

using namespace std;
int n;              // 입력받을 card 개수
int comp = 2;       // 카드 개수와 비교할 숫자 (2,4,8,16...)

void in(int &data){
    cin >> data;
}

void card_res(int num){
    if(num == 1){
        cout << 1 << endl;
    }
    else{
        while(1){
            if(num <= comp){
                for(int i=0; i<(comp/2); i++){
                    if(num == comp-i){
                        cout << comp-(i*2) << endl;
                        break;
                    }
                    
                }
                break;               
            }
            else
                comp += comp;
        }
    }    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    in(n);
    card_res(n);

    return 0;
}