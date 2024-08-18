#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;    cin >> n;
    vector<int> numbers(n);
    vector<int> numbers_sort(n);
    for (int i = 0; i < n; ++i) {
        int number;     cin >> number;
        numbers[i] = number;
        numbers_sort[i] = number;
    }

    sort(numbers_sort.begin(), numbers_sort.end());
    numbers_sort.erase(unique(numbers_sort.begin(), numbers_sort.end()), numbers_sort.end());

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(numbers_sort.begin(), numbers_sort.end(), numbers[i]);
        cout << distance(numbers_sort.begin(), it) << ' ';
    }

    return 0;
}