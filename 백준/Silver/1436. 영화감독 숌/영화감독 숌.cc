// BOJ_1436 : 영화감독 숌
#include <iostream>

// N: 입력, title: 출력(영화 제목)
// cnt: 임시 title값이 몇 번째 영화 제목인가.
// flag: loof 종료 기점
using namespace std;
int N, title;
string title_;

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
}

void solve(){
    int cnt = 0;
    int flag = 1;
    title = 665;
    while(flag){
        title++;
        title_ = to_string(title);
        for(int i = 2; i < title_.length(); i++){            
            if(title_[i - 2] == '6' && title_[i - 1] == '6' && title_[i] == '6'){
                cnt++;
                break;
            }
        }
        if(cnt == N)    flag = 0;
    }
}

void out(){
    cout << title << endl;
}

int main() {
    in();
    solve();
    out();
    return 0;
}