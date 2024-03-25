#include <iostream>

using namespace std;

int main() {
    string words;
    int count = 0;

    getline(cin, words);

    for (char word : words) {
        if (word == ' ') {
            count += 1;
        }
    }

    if (words.front() == ' ')
        count -= 1;

    if (words.back() == ' ')
        count -= 1;

    cout << count + 1 << '\n';

    return 0;
}