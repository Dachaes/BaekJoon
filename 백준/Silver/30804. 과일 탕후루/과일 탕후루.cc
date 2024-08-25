#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_fruits;
    cin >> n_fruits;

    vector<int> fruits(n_fruits);
    for (int i = 0; i < n_fruits; ++i) {
        cin >> fruits[i];
    }

    unordered_map<int, int> fruits_map;
    int left = 0, answer = 0;
    for (int right = 0; right < n_fruits; ++right) {
        fruits_map[fruits[right]]++;

        // 윈도우 내 과일 종류가 3개 이상이면, 윈도우를 축소
        while (fruits_map.size() > 2) {
            fruits_map[fruits[left]]--;
            if (fruits_map[fruits[left]] == 0) {
                fruits_map.erase(fruits[left]);
            }
            left++;
        }

        // 최대 길이 갱신
        answer = max(answer, right - left + 1);
    }

    cout << answer << '\n';
    return 0;
}