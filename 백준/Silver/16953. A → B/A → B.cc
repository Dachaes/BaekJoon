#include <iostream>
#include <stack>
#include <unordered_map>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    unordered_map<long long, int> mem;
    mem[a] = 1;

    stack<int> s;
    s.emplace(a);
    long long num, new_num;

    while(!s.empty()) {
        num = s.top();
        s.pop();

        // 1
        new_num = num * 2;
        if (new_num <= b) {
            if (mem.find(new_num) != mem.end())
                continue;

            mem[new_num] = mem[num] + 1;
            if (new_num == b)
                break;

            s.emplace(new_num);
        }

        // 2
        new_num = num * 10 + 1;
        if (new_num <= b) {
            if (mem.find(new_num) != mem.end())
                continue;

            mem[new_num] = mem[num] + 1;
            if (new_num == b)
                break;

            s.emplace(new_num);
        }
    }

    if (mem.find(b) == mem.end())
        mem[b] = -1;
    cout << mem[b] << endl;

    return 0;
}