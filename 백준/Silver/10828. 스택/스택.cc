// BOJ_10828 : 스택
#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<int> s;
int N, num, s_size;
string s_commend;

void in1(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
}

void in2(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s_commend;
}

void solve(){
    if(s_commend == "push"){
        cin >> num;
        s.push(num);
        s_size++;
    }
    else if(s_commend == "pop"){
        if(!s.empty()){
            cout << s.top() << endl;
            s.pop();
            s_size--;
        }
        else
            cout << "-1" << endl;
    }
    
    else if(s_commend == "size")
        cout << s_size << endl;

    else if(s_commend == "empty")
        cout << s.empty() << endl;

    else if(s_commend == "top"){
        if(!s.empty())
            cout << s.top() << endl;
        else
            cout << "-1" << endl;
    }
}

int main() {
    in1();
    for (int i = 0; i < N; i++){
        in2();
        solve();
    }
    return 0;
}