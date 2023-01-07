// BOJ_14425 : 문자열 집합
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int N, M, i;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    unordered_set<string> s;
    string word;
    int result = 0;
    cin >> N >> M;

    for(i = 0; i < N; i++){
        cin >> word;
        s.insert(word);
    }

    for(i = 0; i < M; i++){
        cin >> word;
        if(s.find(word) != s.end())
            result++;
    }

    cout << result << endl;

    return 0;
}