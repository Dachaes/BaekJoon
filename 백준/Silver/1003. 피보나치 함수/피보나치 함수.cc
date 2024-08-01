#include <iostream>
#include <vector>
using namespace std;


int fibonacci(int);


vector<pair<int, int>> counts(41, {0, 0});
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 테스트 케이스 입력
    int n_tests = 0;
    cin >> n_tests;

    // counts 초기값 설정
    counts[0] = {1, 0};
    counts[1] = {0, 1};
    for (int j = 2; j < 41; ++j)
        counts[j] = {counts[j - 1].first + counts[j - 2].first, counts[j - 1].second + counts[j - 2].second};

    // 테스트 케이스 별 계산
    int number = 0;
    for (int i = 0; i < n_tests; ++i) {
        cin >> number;
        cout << counts[number].first << ' ' << counts[number].second << '\n';
    }

    return 0;
}