#include <iostream>
#include <vector>
// #define endl '\n'
using namespace std;


void post_order(vector<int>&, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> pre_order;
    int value;
    while (cin >> value) {
        pre_order.emplace_back(value);
    }

    // 후위 순회 출력
    post_order(pre_order, 0, pre_order.size());

    return 0;
}


void post_order(vector<int>& pre_order, int start, int end) {
    if (start >= end) return;

    int root = pre_order[start];

    int split = start + 1;
    while (split < end && pre_order[split] < root) {
        split++;
    }

    post_order(pre_order, start + 1, split);
    post_order(pre_order, split, end);
    cout << root << endl;
}