#include <iostream>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;
    cin >> n;

    // 카드 덱 채워놓기
    queue<int> cards;
    for (int i = 1; i <= n; ++i) {
        cards.emplace(i);
    }

    // 카드 재배치 중
    int cards_top = 0;
    while (cards.size() != 1) {
        cards.pop();
        cards_top = cards.front();
        cards.pop();
        cards.emplace(cards_top);
    }

    cout << cards.front() << endl;
    return 0;
}
