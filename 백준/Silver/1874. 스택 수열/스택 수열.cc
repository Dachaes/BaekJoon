#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    // num_stack: 1 ~ n 까지의 숫자를 조작할 stack<int>
    // num_sequence: 원하는 수열이 들어있는 vector<int>
    // res: push, pop 정보를 저장할 vector<char>
    stack<int> num_stack;    vector<int> num_sequence(n);
    vector<char> res;

    // 1. 수열 채우기
    for (int i = 0; i < n; ++i) {
        cin >> num_sequence[i];
    }

    // 2. 1~n 의 숫자를 가지고 수열을 만들 수 있는지 확인하기
    int num_sta = 0, idx_seq = 0, num_seq = 0;
    for (int i = 1; i <= n; ++i) {
        // push
        num_stack.push(i);
        res.push_back('+');

        num_seq = num_sequence[idx_seq];
        num_sta = num_stack.top();

        // pop
        while (num_sta == num_seq) {
            num_stack.pop();
            res.push_back('-');
            idx_seq++;

            num_seq = num_sequence[idx_seq];
            if (!num_stack.empty()) {
                num_sta = num_stack.top();
            }
        }
    }

    // 3. 결과보기
    if (idx_seq == n) {
        for (char r : res) {
            cout << r << '\n';
        }
    }
    else
        cout << "NO" << '\n';

    return 0;
}