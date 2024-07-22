#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 - 카드 덱
    int n_cards = 0;
    cin >> n_cards;

    unordered_map<int, int> cards;
    int card = 0;
    for (int i = 0; i < n_cards; ++i) {
        cin >> card;
        cards[card]++;
    }

    // 입력 - 개수 세기
    int n_checks = 0;
    cin >> n_checks;

    int check = 0;
    for (int i = 0; i < n_checks; ++i) {
        cin >> check;
        cout << cards[check] << ' ';
    }

    return 0;
}