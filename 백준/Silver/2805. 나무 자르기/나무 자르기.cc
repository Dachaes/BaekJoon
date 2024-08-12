#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int answer = 0;
void binary_search(vector<int>&, int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n_trees = 0;        cin >> n_trees;
    int target = 0;         cin >> target;

    vector<int> trees(n_trees);

    for (int i = 0; i < n_trees; ++i) {
        cin >> trees[i];
    }
    int max_tree = *max_element(trees.begin(), trees.end());

    binary_search(trees, 0, max_tree, target);

    cout << answer << '\n';
    return 0;
}


void binary_search(vector<int>& list, int start, int end, int target) {
    int mid = (start + end) / 2;
    long long sum = 0;

    while (start <= end) {
        for (int element : list)
            if (element > mid)
                sum += element - mid;

        // 딱 맞게 잘렸으면
        if (target == sum) {
            answer = mid;
            return;
        }
        // 많이 잘렸으면 자르는 길이를 늘려서 적게 자르자
        else if (target < sum) {
            answer = mid;
            start = mid + 1;
            mid = (start + end) / 2;
            sum = 0;
        }
        // 적게 잘렸으면 자르는 길이를 줄여서 많이 자르자
        else {
            end = mid - 1;
            mid = (start + end) / 2;
            sum = 0;
        }
    }
}