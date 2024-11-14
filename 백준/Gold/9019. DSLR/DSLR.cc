#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;


string bfs(int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;     cin >> tc;
    while (tc--) {
        int number1, number2;
        cin >> number1 >> number2;

        string command;
        if (number1 != number2) {
            command = bfs(number1, number2);
        }

        cout << command << endl;
    }

    return 0;
}


string bfs(int num1, int num2) {
    bool visited[10000] = {false};
    visited[num1] = true;
    queue<pair<int, string>> q;
    q.emplace(num1, "");

    while (!q.empty()) {
        num1 = q.front().first;
        string command = q.front().second;

        if (num1 == num2) {
            return command;
        }
        q.pop();

        // 1. D
        int new_num1 = (num1 * 2) % 10000;
        if (!visited[new_num1]) {
            visited[new_num1] = true;
            q.emplace(new_num1, command + 'D');
        }

        // 2. S
        new_num1 = (num1 != 0)? (num1 - 1):9999;
        if (!visited[new_num1]) {
            visited[new_num1] = true;
            q.emplace(new_num1, command + 'S');
        }

        int d1 = int(num1 / 1000);
        int d2 = int((num1 % 1000) / 100);
        int d3 = int((num1 % 100) / 10);
        int d4 = num1 % 10;

        // 3. L
        new_num1 = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
        if (!visited[new_num1]) {
            visited[new_num1] = true;
            q.emplace(new_num1, command + 'L');
        }

        // 4. R
        new_num1 = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
        if (!visited[new_num1]) {
            visited[new_num1] = true;
            q.emplace(new_num1, command + 'R');
        }
    }

    return "None";
}