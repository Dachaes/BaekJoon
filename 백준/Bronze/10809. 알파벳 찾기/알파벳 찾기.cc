#include <iostream>
using namespace std;

int main() {
    int count[26];
    fill_n(count, 26, -1);
    string word;
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        if (count[word[i] - 'a'] == -1) {
            count[word[i] - 'a'] = i;
        }
    }

    for (int c : count) {
        cout << c << " ";
    }
    
    return 0;
}