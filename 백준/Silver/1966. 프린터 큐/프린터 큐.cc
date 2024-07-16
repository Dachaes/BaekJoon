#include <iostream>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int num_tests = 0;
    cin >> num_tests;

    // 테스트 케이스별 계산
    for (int i = 0; i < num_tests; ++i) {

        // n 개의 문서 중 m 번째의 출력 순서가 궁금함
        int n = 0, m = 0;
        // docs 는 <인덱스, 우선 순위> 를 가짐
        queue<pair<int, int>> docs;
        priority_queue<int> pq_docs;
        int doc = 0;

        // 입력
        cin >> n >> m;
        for (int j = 0; j < n; ++j) {
            cin >> doc;
            docs.emplace(j, doc);
            pq_docs.emplace(doc);
        }

        // 문서 m 의 출력 순서 찾는 중
        int count = 0;
        while (true) {
            int docs_index = docs.front().first;
            int docs_priority = docs.front().second;
            // 1. docs 의 가장 첫 번째 문서보다 높은 우선 순위의 문서가 있다면, docs의 뒤로 pop! push!
            if (docs_priority < pq_docs.top()) {
                docs.emplace(docs.front());
                docs.pop();
            }
            // 2. docs 의 가장 첫 번째 문서가 가장 높은 우선 순위의 문서고,
            else if (docs_priority == pq_docs.top()) {
                count++;
                // 2-1. 찾던 문서면 종료 (출력)
                if (docs_index == m)
                    break;
                // 2-2. 찾던 문서가 아니라면, pop! (출력)
                else {
                    docs.pop();
                    pq_docs.pop();
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}
