// BOJ_1024 : 수열의 합
#include <iostream>
#include <vector>
using namespace std;

int N, L;
int num, mid;

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> L;
}

void solve(){
    int temp = 0;
    int N_ = 0;
    // N이 짝수인 경우
    if(N % 2 == 0){
        for(int i = L; i <= 100; i++){
            temp = i;
            if(temp % 2 == 1){
                if((N % temp == 0) && (N / temp - temp / 2 >= 0)){
                    num = temp;
                    mid = N / temp;
                    break;
                }
            }
            else{
                N_ = N + temp / 2;
                if((N_ % temp == 0) && ((N_ / temp - temp / 2) >= 0)){
                    num = temp;
                    mid = N_ / temp;
                    break;
                }
            }
        }
    }
    // N이 홀수인 경우
    else{
        for(int i = L; i <= 100; i++){
            temp = i;
            if(temp % 2 == 0){
                N_ = N + temp / 2;
                if((N_ % temp == 0) && ((N_ / temp - temp / 2) >= 0)){
                    num = temp;
                    mid = N_ / temp;
                    break;
                }
            }
            else{
                if((N % temp == 0) && (N / temp - temp / 2 >= 0)){
                    num = temp;
                    mid = N / temp;
                    break;
                }
            }


        }
    }
}

void print(){
    if(num == 0)
        cout << "-1" << endl;
    else if(num % 2 == 1){
        for(int i = mid - num / 2; i <= mid + num / 2; i++){
            cout << i;
            if(i == mid + num / 2)  cout << endl;
            else                    cout << " ";
        }
    }
    else{
        for(int i = mid - num / 2; i < mid + num / 2; i++){
            cout << i;
            if(i == mid + num / 2 - 1)  cout << endl;
            else                    cout << " ";
        }
    }
}

int main() {
    in();
    solve();
    print();
    return 0;
}