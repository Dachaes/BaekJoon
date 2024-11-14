#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;     cin >> tc;
    while (tc--) {
        bool cout_flag = true;

        string commands;        cin >> commands;
        int n_numbers;          cin >> n_numbers;
        string numbers;     cin >> numbers;
        numbers = numbers.substr(1, numbers.size() - 2);
        deque<int> dq_numbers;

        // 0. deque 에 정리
        stringstream ss(numbers);
        string number;
        while (getline(ss, number, ',')) {
            if (!number.empty()) {
                dq_numbers.emplace_back(stoi(number));
            }
        }

        // 1. commands 처리
        bool reverse = false;
        for (char command : commands) {
            if (command == 'R') {
                reverse = !reverse;
            }
            else if (command == 'D') {
                if (n_numbers == 0) {
                    cout << "error" << endl;
                    cout_flag = false;
                    break;
                }
                else {
                    n_numbers--;
                    if (!reverse)
                        dq_numbers.pop_front();
                    else
                        dq_numbers.pop_back();
                }
            }
        }

        // 2. 출력
        if (cout_flag) {
            cout << '[';
            if (!reverse) {
                for (int i = 0; i < n_numbers; i++) {
                    if (i < n_numbers - 1)
                        cout << dq_numbers[i] << ',';
                    else
                        cout << dq_numbers[i];
                }
            }
            else {
                for (int i = 0; i < n_numbers; i++) {
                    if (i < n_numbers - 1)
                        cout << dq_numbers[n_numbers - 1 - i] << ',';
                    else
                        cout << dq_numbers[n_numbers - 1 - i];
                }
            }
            cout << ']' << endl;
        }
    }

    return 0;
}