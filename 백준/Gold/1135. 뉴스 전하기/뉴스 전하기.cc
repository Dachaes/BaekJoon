#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Person {
    int time = 0;
    int parent = -1;
    vector<int> child;
    vector<int> child_time;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_people;
    cin >> n_people;

    // 사람에 대한 정보 저장
    vector<Person> people(n_people);
    for (int i = 0; i < n_people; ++i) {
        int parent_number;
        cin >> parent_number;

        Person person;
        person.parent = parent_number;
        people[i] = person;

        if (parent_number != -1) {
            people[parent_number].child.push_back(i);
        }
    }

    // 탐색
    queue<int> q;
    for (int i = 0; i < n_people; ++i) {
        // 리프 노드 저장
        if (people[i].child.empty()) {
            q.emplace(i);
        }
    }

    // 리프 노드에서 탐색 시작
    while(!q.empty()) {
        int person_number = q.front();
        q.pop();

        // 0. 본인의 자식 노드들의 시간을 체크하여 본인의 시간을 갱신
        Person &person = people[person_number];
        for (int i = 0; i < person.child_time.size(); ++i) {
            person.time = max(person.time, person.child_time[i] + i + 1);
        }

        // parent: person 의 부모 노드
        int parent_number = person.parent;
        // 루트 노드까지 탐색이 끝나면 종료
        if (parent_number == -1) {
            continue;
        }
        
        Person &parent = people[parent_number];
        // 1. 본인 부모의 자식 시간 모음에, 본인의 시간 넣기
        parent.child_time.emplace_back(person.time);
        // 2. 만약 부모의 자식 시간 모음 크기가 자식 노드 개수와 같다면 q 에 넣음
        if (parent.child_time.size() == parent.child.size()) {
            sort(parent.child_time.rbegin(), parent.child_time.rend());
            q.emplace(parent_number);
        }
    }

    cout << people[0].time << '\n';

    return 0;
}