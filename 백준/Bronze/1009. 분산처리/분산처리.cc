#include <iostream>
#include <cmath>
using namespace std;
int num_case, num_dataA, num_dataB;

void in(int &);

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    in(num_case);
    int number_of_com[num_case];            // 컴퓨터 번호
    
    // 입력받고 결과값 array에 저장
    for(int i=0; i<num_case; i++){
    in(num_dataA); in(num_dataB);
    num_dataA %= 10;                        // DATA_A의 간결화

        if(num_dataA == 1 || num_dataA == 5 || num_dataA == 6)
            number_of_com[i] = num_dataA;

        else if (num_dataA == 0)
            number_of_com[i] = 10;
    
        else if (num_dataA == 4 || num_dataA == 9) {
            num_dataB %= 2;
            if (num_dataB == 1)
                number_of_com[i] = num_dataA;
            else
                number_of_com[i] = (num_dataA*num_dataA)%10;
        }
        else {
            num_dataB %= 4;
            switch(num_dataB){
                case 1:
                    number_of_com[i] = num_dataA;
                    break;
                case 2:    
                    number_of_com[i] = (num_dataA*num_dataA)%10;
                    break;                    
                case 3:
                    number_of_com[i] = (num_dataA*num_dataA*num_dataA)%10;
                    break;                    
                case 0:
                    number_of_com[i] = (num_dataA*num_dataA*num_dataA*num_dataA)%10;
                    break;
            }
        }
    }
    // array 출력
    for(int i=0; i<num_case; i++){
    cout << number_of_com[i] << endl;
    }
    return 0;
}

void in(int& data){
    cin >> data;
}