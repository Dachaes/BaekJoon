// BOJ_17952 : 과제는 끝나지 않아!
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
stack<vector<int>> assignment;
int N;          // 이번 학기는 N분 (이후 N번의 입력을 받는다.)
int score;
int assign0;    // 해당 과제를 위해 사용할 수 있는 시간

void in1(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
}

void in2(){
    vector<int> abc;
    int a, b, c;        // a : 0-과제없음, 1-과제있음
                        // b : 해당 과제의 만점 점수
                        // c : 해당 과제의 소요 시간
    ios::sync_with_stdio(false); cin.tie(0);
    // int a, b, c 에 입력 받기
    cin >> a;
    if(a){
        cin >> b >> c;
        abc.push_back(a); abc.push_back(b); abc.push_back(c);
    }
    else {
        abc.push_back(a); abc.push_back(0); abc.push_back(0);
    }
    // vector<int> abc 에 저장
    assignment.push(abc);
}

void solve(){
    // 재귀 종료 조건
    if(assignment.empty())
        return;
    
    assign0++;
    // 제일 최근에 받은 문제가 있다면
    if(assignment.top().at(0)){
        // 시간 딱 맞음
        if(assignment.top().at(2) == assign0){
            assign0 = 0;
            score += assignment.top().at(1);
        }
        // 시간 부족
        else if(assignment.top().at(2) > assign0){
            assign0 = 0;
        }
        // 시간 남음
        else{
            assign0 -= assignment.top().at(2);
            score += assignment.top().at(1);         
        }
    }
    assignment.pop();
    solve();
}

void out(){
    cout << score << endl;
}

int main() {
    in1();
    for (int i = 0; i < N; i++)
        in2();
    solve();
    out();
    return 0;
}