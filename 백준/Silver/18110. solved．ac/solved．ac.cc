#include <iostream>
#include <deque>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // n_excluded_opinion: 양 옆으로 제외할 사람 수
    // n_opinion: 의견 개수
    int n_excluded_opinion = round(float(n) * 0.15);
    int n_opinion = 0;

    // 입력 2
    deque<int> numbers;
    int number = 0, sum = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> number;
        numbers.emplace_back(number);
    }

    // 정렬
    sort(numbers.begin(), numbers.end());

    // 양 끝 값 삭제
    numbers.erase(numbers.begin(), numbers.begin() + n_excluded_opinion);     // 앞쪽 제외
    numbers.erase(numbers.end() - n_excluded_opinion, numbers.end());         // 뒤쪽 제외
    n_opinion = numbers.size();

    // 합계
    sum = accumulate(numbers.begin(), numbers.end(), 0) ;
    res = round(float(sum) / n_opinion);

    cout << res << endl;
    return 0;
}