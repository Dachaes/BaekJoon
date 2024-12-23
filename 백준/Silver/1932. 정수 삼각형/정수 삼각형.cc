#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;  cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];

            if (i == 0)
                break;

            if (j == 0)
                arr[i][0] += arr[i - 1][0];
            else if (j == i)
                arr[i][i] += arr[i - 1][i - 1];
            else
                arr[i][j] = arr[i][j] + max(arr[i - 1][j - 1], arr[i - 1][j]);
        }
    }

    int answer = *max_element(arr[n - 1].begin(), arr[n - 1].end());
    cout << answer << endl;

    return 0;
}