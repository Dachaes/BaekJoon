#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, n_words;
    cin >> n >> n_words;
    string words;
    cin >> words;

    string answer_words;
    for (int i = 0; i < 2 * n + 1; ++i) {
        if (i % 2 == 0)
            answer_words += 'I';
        else
            answer_words += 'O';
    }

    int answer = 0;
    for (int i = 0; i < n_words - 2 * n; ++i) {
        if (words.substr(i, 2 * n + 1) == answer_words)
            answer++;
    }

    cout << answer << '\n';

    return 0;
}