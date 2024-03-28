#include <iostream>
using namespace std;

int main() {
    int testNo = 0;
    cin >> testNo;
    cin.ignore();

    string problems;
    for (int t = 0; t < testNo; t++) {
        getline(cin, problems);

        int points = 0, point = 1;
        for (char problem : problems) {
            if (problem == 'O') {
                points += point;
                point += 1;
            }
            else    point = 1;
        }
        cout << points << '\n';
    }

    return 0;
}