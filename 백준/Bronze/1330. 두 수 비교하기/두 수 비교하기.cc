#include <iostream>
using namespace std;

int main() {
    int word1, word2;
    cin >> word1 >> word2;

    if (word1 - word2 == 0)
        cout << "==" << '\n';
    else if (word1 - word2 > 0)
        cout << '>' << '\n';
    else
        cout << '<' << '\n';

    return 0;
}