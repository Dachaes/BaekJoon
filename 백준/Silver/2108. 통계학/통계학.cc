#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    vector<int> counts(8001, 0);
    int num = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        numbers[i] = num;
        counts[num + 4000]++;
    }

    // numbers 를 sort 하기
    sort(numbers.begin(), numbers.end());

    // 최대값, 최소값 구하기
    int min_number = numbers[0];
    int max_number = numbers[n - 1];


    // arithmetic_mean: 산술평균, median: 중앙값, mode: 최빈값, range: 범위
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    int size = numbers.size();
    double arithmetic_mean = round(double(sum) / size);
    int median = numbers[size / 2];
    int mode = 0;
    int range = abs(max_number - min_number);

    // 최빈값 구하기
    int max_count_idx = max_element(counts.begin(), counts.end()) - counts.begin();
    int max_count = counts[max_count_idx];
    mode = max_count_idx - 4000;
    for (int i = max_count_idx + 1; i < 8001; ++i) {
        if (counts[i] == max_count) {
            mode = i - 4000;
            break;
        }
    }

    // arithmetic_mean 이 -0 일 때를 대비
    if (arithmetic_mean == -0)
        arithmetic_mean = 0;

    cout << arithmetic_mean << '\n' << median << '\n' << mode << '\n' << range << '\n';

    return 0;
}
