// BOJ_1541 : 잃어버린 괄호
#include <iostream>
#include <string>

using namespace std;
string in;
string temp="";         // 임시 저장값
int res=0;              // 계산한 결과값
int order = 1;          // 1 = 2번째 숫자, 2 = 2번째 숫자 ~ (-)부호가 나오기 전까지, 3 = (-)부호가 나오고부터
int sign = 1;           // + = 1, - = 0

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin, in);
    for(int i=0; i<=in.length(); i++){                          // 입력값(string) 하나하나 체크
        if(in[i] != '+' && in[i] != '-' && in[i] != '\0'){      // 입력값이 숫자일 때
            temp.push_back(in[i]);                              // 반복하며 temp에 공간 맨 뒤에 저장
        }
        else {
            if(order == 1){             // 1) 첫번째 숫자일 때
                res = stoi(temp);       // res=temp 저장 후
                order = 2;              // 다음 숫자(2번째) 받을 준비를 한다.
                if(in[i] == '-')        // -> A-B(= 1번째 숫자 - 2번째 숫자) 일 경우, 부호 저장 (defalt = +)
                    sign = 0;
            }
            else if (order == 2){       // 2) 두번째 숫자일 때
                if (sign == 1){         // i) A+B일 경우
                    res += stoi(temp);  //    A+B를 한다.
                }
                else{                   // ii) A-B일 경우
                    res -= stoi(temp);  //     A-B를 한다.

                }    
                if(in[i] == '-')
                    order = 3;                   
            }
            else{                       // 3번째 혹은 그 이상일 경우
                res -= stoi(temp);      // res-C(=기존 결과값 - 새로운 숫자)를 한다.
            }
            temp.clear();               // temp 초기화
        }
    }
    cout << res << endl;

    return 0;
}