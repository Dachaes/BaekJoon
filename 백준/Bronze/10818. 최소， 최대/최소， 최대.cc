#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int min = *min_element(numbers.begin(), numbers.end());
    int max = *max_element(numbers.begin(), numbers.end());

    cout << min << ' ' << max << '\n';

    return 0;
}