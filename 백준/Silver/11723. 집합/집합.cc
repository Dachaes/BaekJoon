#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0;
    cin >> n;
    cin.ignore();

    // 입력 2, 계산
    vector<int> numbers(21, 0);

    string command;
    for (int i = 0; i < n; ++i) {
        getline(cin, command);

        // 'add' command 확인
        if (command.find("add") == 0) {
            int number = stoi(command.substr(4));
            numbers[number] = 1;
        }
        // 'remove' command 확인
        else if (command.find("remove") == 0) {
            int number = stoi(command.substr(7));
            numbers[number] = 0;
        }
        // 'check' command 확인
        else if (command.find("check") == 0) {
            int number = stoi(command.substr(6));
            cout << numbers[number] << '\n';
        }
        // 'toggle' command 확인
        else if (command.find("toggle") == 0) {
            int number = stoi(command.substr(7));
            numbers[number] ^= 1;
        }
        // 'all' command 확인
        else if (command.find("all") == 0) {
            fill(numbers.begin(), numbers.end(), 1);
        }
        // 'empty' command 확인
        else if (command.find("empty") == 0) {
            fill(numbers.begin(), numbers.end(), 0);
        }
    }

    return 0;
}