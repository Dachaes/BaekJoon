// BOJ_2822 : 점수 계산
#include <iostream>
#include <map>
#include <set>

using namespace std;
multimap<int, int> point;
multimap<int, int> :: iterator iter;
set<int> num;
set<int> :: iterator iter_num;
int datas, sum;

void in(){
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 0; i < 8; i++){
        cin >> datas;
        point.insert(pair<int, int>(datas, i + 1));
    }
}

void solve(){
    // 고득점 점수 합계 (5개)
    int i = 0;
    for (iter = point.end(); i < 5; i++){   
        iter--;
        sum += iter->first;
    }
    // 고득점 문제 번호 (5개)
    i = 0;
    for (iter = point.end(); i < 5; i++){   
        iter--;
        num.insert(iter->second);
    }
}
void out(){
    cout << sum << endl;
    
    int i = 0;
    for (iter_num = num.begin(); i < 5; i++){   
        cout << *iter_num;
        if(i != 4)     cout << " ";
        else           cout << endl;
        iter_num++;
    }
}

int main() {
    in();
    solve();
    out();
    return 0;
}