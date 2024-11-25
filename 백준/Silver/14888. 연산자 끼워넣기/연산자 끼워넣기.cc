#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;


int min_answer = INT_MAX;
int max_answer = INT_MIN;
void cal(int, int[], int[], int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;              cin >> n;
    int nums[n];
    int operators[4];       // +, -, x, / 개수
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }

    cal(n, nums, operators, 1, nums[0]);

    cout << max_answer << '\n' << min_answer << endl;
    return 0;
}


void cal(int size, int nums[], int operators[], int cnt, int answer) {
    if (cnt >= size) {
        min_answer = min(min_answer, answer);
        max_answer = max(max_answer, answer);
        return;
    }

    int new_answer = 0;
    // 덧셈
    if (operators[0] > 0) {
        new_answer = answer + nums[cnt];
        operators[0]--;
        cal(size, nums, operators, cnt + 1, new_answer);
        operators[0]++;
    }
    // 뺄셈
    if (operators[1] > 0) {
        new_answer = answer - nums[cnt];
        operators[1]--;
        cal(size, nums, operators, cnt + 1, new_answer);
        operators[1]++;
    }
    // 곱셈
    if (operators[2] > 0) {
        new_answer = answer * nums[cnt];
        operators[2]--;
        cal(size, nums, operators, cnt + 1, new_answer);
        operators[2]++;
    }
    // 나눗셈
    if (operators[3] > 0) {
        new_answer = answer / nums[cnt];
        operators[3]--;
        cal(size, nums, operators, cnt + 1, new_answer);
        operators[3]++;
    }
}