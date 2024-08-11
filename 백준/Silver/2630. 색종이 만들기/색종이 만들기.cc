#include <iostream>
#include <vector>
using namespace std;


int white = 0, blue = 0;
void divide_conquer(vector<vector<int>>&, int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;         cin >> n;
    vector<vector<int>> paper(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> paper[i][j];
        }
    }

    divide_conquer(paper, 0, 0, n);
    cout << white << '\n' << blue << '\n';
    return 0;
}


void divide_conquer(vector<vector<int>>& arr, int x, int y, int size) {
    int color = arr[x][y];

    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (color != arr[i][j]) {
                divide_conquer(arr, x, y, size / 2);
                divide_conquer(arr, x + size / 2, y, size / 2);
                divide_conquer(arr, x, y + size / 2, size / 2);
                divide_conquer(arr, x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    }

    if (color == 1)
        blue++;
    else
        white++;
}