#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0;
    cin >> n;
    // 입력 2
    vector<pair<int, int>> people(n);
    int weight = 0, height = 0;
    for (int i = 0; i < n; ++i) {
        cin >> weight >> height;
        people[i] = {weight, height};
    }

    vector<int> rank(n, 1);
    pair<int, int> person1, person2;
    for (int i = 0; i < n; ++i) {
        person1 = people[i];
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                person2 = people[j];
                if (person1.first < person2.first and person1.second < person2.second)
                    rank[i]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << rank[i] << ' ';
    }
    return 0;
}