#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    stack<int> idx;
    vector<pair<int, int>> symbol;
    set<string> answers;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            idx.emplace(i);
        }
        else if (str[i] == ')') {
            int pair_idx = idx.top();
            idx.pop();
            symbol.emplace_back(pair_idx, i);
        }
    }

    // bit masking
    int n_symbol = symbol.size();
    for (int mask = 1; mask < (1 << n_symbol); ++mask) {
        string tmp_str = str;
        vector<int> remove_symbols;

        for (int j = 0; j < n_symbol; ++j) {
            if (mask & (1 << j)) {
                remove_symbols.emplace_back(symbol[j].first);
                remove_symbols.emplace_back(symbol[j].second);
            }
        }

        sort(remove_symbols.begin(), remove_symbols.end(), greater<>());

        for (int remove_symbol : remove_symbols) {
            tmp_str.erase(remove_symbol, 1);
        }

        answers.insert(tmp_str);
    }

    // 정리
    vector<string> sorted_answers(answers.begin(), answers.end());
    sort(sorted_answers.begin(), sorted_answers.end());

    for (string answer : sorted_answers) {
        cout << answer << endl;
    }
    
    return 0;
}