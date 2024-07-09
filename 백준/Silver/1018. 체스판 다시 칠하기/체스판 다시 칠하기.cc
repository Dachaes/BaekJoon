#include <iostream>
#include <vector>
using namespace std;

int cmpBoard(const vector<vector<char>>&, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n = 0, m = 0, count = 0;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));

    // 1. board 채우기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    // 2. 비교하기
    for (int i = 0; i <= n - 8; ++i) {
        for (int j = 0; j <= m - 8; ++j) {
            if (i == 0 and j == 0)
                count = cmpBoard(board, i, j);
            else
                count = min(count, cmpBoard(board, i, j));
        }
    }

    cout << count << endl;
    return 0;
}


int cmpBoard(const vector<vector<char>>& board, int n, int m)
{
    char color;
    int count1 = 0, count2 = 0;

    for (int i = n; i < n + 8; ++i) {
        for (int j = m; j < m + 8; ++j) {
            color = board[i][j];
            // 1. 홀수면
            if ((i + j) % 2)
            {
                if (color == 'W')
                    count1 += 1;
                else
                    count2 += 1;
            }
            // 2. 짝수면
            else
            {
                if (color == 'B')
                    count1 += 1;
                else
                    count2 += 1;
            }
        }
    }

    return min(count1, count2);
}