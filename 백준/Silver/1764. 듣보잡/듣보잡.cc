#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0, m = 0;
    cin >> n >> m;

    // 입력 2
    unordered_set<string> people1(n);
    string people2_person;
    set<string> common_people;
    for (int i = 0; i < n; ++i) {
        string people1_person;
        cin >> people1_person;
        people1.emplace(people1_person);
    }

    for (int i = 0; i < m; ++i) {
        cin >> people2_person;

        if (people1.find(people2_person) != people1.end()) {
            common_people.emplace(people2_person);
        }
    }

    cout << common_people.size() << '\n';
    for (string person:common_people) {
        cout << person << '\n';
    }
    return 0;
}