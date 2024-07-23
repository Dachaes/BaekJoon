#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n_commands = 0;
    cin >> n_commands;
    cin.ignore();

    queue<int> numbers;
    for (int i = 0; i < n_commands; ++i) {
        string command;
        getline(cin, command);

        // empty
        if (command == "empty") {
            if (numbers.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        // size
        else if (command == "size") {
            cout << numbers.size() << '\n';
        }
        // front
        else if (command == "front") {
            if (numbers.empty())
                cout << -1 << '\n';
            else
                cout << numbers.front() << '\n';
        }
        // back
        else if (command == "back") {
            if (numbers.empty())
                cout << -1 << '\n';
            else
                cout << numbers.back() << '\n';
        }
        // pop
        else if (command == "pop") {
            if (numbers.empty())
                cout << -1 << '\n';
            else {
                cout << numbers.front() << '\n';
                numbers.pop();
            }
        }
        // push
        else {
            int number = stoi(command.substr(5));
            numbers.emplace(number);
        }
    }

    return 0;
}