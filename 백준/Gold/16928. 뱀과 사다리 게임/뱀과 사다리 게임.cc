#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;


int bfs(int[101]);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_ladders, n_snakes;
    cin >> n_ladders >> n_snakes;
    int ladders_and_snakes[101] = {0};
    while (n_ladders--) {
        int num1, num2;
        cin >> num1 >> num2;
        ladders_and_snakes[num1] = num2;
    }
    while (n_snakes--) {
        int num1, num2;
        cin >> num1 >> num2;
        ladders_and_snakes[num1] = -num2;
    }

    int answer = bfs(ladders_and_snakes);
    cout << answer << endl;

    return 0;

}


int bfs(int ladders_and_snakes[101]) {
    vector<int> visited(101, -1);
    visited[1] = 0;
    queue<int> q;
    q.emplace(1);

    while(!q.empty()) {
        int x = q.front();
        int n_dice = visited[x];
        q.pop();

        for (int d = 1; d < 7; ++d) {
            int nx = x + d;

            // 100 초과면 break
            if (nx > 100)
                break;

            while (true) {
                // 1. 다음 위치 nx 가 이미 들린 곳이면 break
                if (visited[nx] != -1)
                    break;

                // 2. 다음 위치 nx 의 주사위 값 저장
                visited[nx] = n_dice + 1;

                // 3. 다음 위치 nx 를 들렀을 때, 사다리나 뱀이 있는지 확인
                int nnx = ladders_and_snakes[nx];

                // 4. 다다음 위치 nnx 가 사다리인지 뱀인지 확인
                // 4-1. 사다리
                if (nnx > 0) {
                    nx = nnx;
                }
                // 4-2. 뱀
                else if (nnx < 0) {
                    nx = -nnx;
                }
                // 4-3. 아무것도 없음
                else {
                    q.emplace(nx);
                    break;
                }
            }
        }
    }

    return visited[100];
}