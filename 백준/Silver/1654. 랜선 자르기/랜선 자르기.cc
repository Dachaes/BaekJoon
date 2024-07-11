#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long bin_search(long long, long long, int, const vector<int>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> line(k);
    for (int i = 0; i < k; ++i) {
        cin >> line[i];
    }
    long long max_line = *max_element(line.begin(), line.end());

    long long cut_line = bin_search(1, max_line, n, line);

    cout << cut_line << endl;
    return 0;
}

long long bin_search(long long start, long long end, int target, const vector<int>& line) {
    long long result = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;

        long long count = 0;
        for (int l : line) {
            count += l / mid;
        }

        if (count >= target) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return result;
}
