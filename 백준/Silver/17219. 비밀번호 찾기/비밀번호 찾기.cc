#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n_passwords = 0, n_finds = 0;
    cin >> n_passwords >> n_finds;

    // 입력
    unordered_map<string, string> passwords;
    string address, password;
    for (int i = 0; i < n_passwords; ++i) {
        cin >> address >> password;
        passwords[address] = password;
    }

    for (int i = 0; i < n_finds; ++i) {
        cin >> address;
        cout << passwords[address] << '\n';
    }

    return 0;
}