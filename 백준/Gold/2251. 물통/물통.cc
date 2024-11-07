#include <iostream>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;


bool visited[201][201][201] = {false};
void dfs(int, int, int, vector<int> &, set<int> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> bowls(3);
    for (int i = 0; i < 3; ++i) {
        cin >> bowls[i];
    }

    set<int> bowl_c;
    visited[0][0][bowls[2]] = true;
    bowl_c.insert(bowls[2]);
    dfs(0, 0, bowls[2], bowls, bowl_c);

    for (int it : bowl_c) {
        cout << it << ' ';
    }
    cout << endl;

    return 0;
}


void dfs(int a, int b, int c, vector<int> &bowls, set<int> &bowl_c) {
    int na, nb, nc;

    // a -> b
    if (a + b <= bowls[1]) {
        na = 0;
        nb = a + b;
        nc = c;
    }
    else {
        na = a - (bowls[1] - b);
        nb = bowls[1];
        nc = c;
    }
    if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        if (na == 0)
            bowl_c.insert(nc);
        dfs(na, nb, nc, bowls, bowl_c);
    }

    // a -> c
    if (a + c <= bowls[2]) {
        na = 0;
        nb = b;
        nc = a + c;
    }
    else {
        na = a - (bowls[2] - c);
        nb = b;
        nc = bowls[2];
    }
    if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        if (na == 0)
            bowl_c.insert(nc);
        dfs(na, nb, nc, bowls, bowl_c);
    }

    // b -> a
    if (a + b <= bowls[0]) {
        na = a + b;
        nb = 0;
        nc = c;
    }
    else {
        na = bowls[0];
        nb = b - (bowls[0] - a);
        nc = c;
    }
    if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        if (na == 0)
            bowl_c.insert(nc);
        dfs(na, nb, nc, bowls, bowl_c);
    }

    // b -> c
    if (b + c <= bowls[2]) {
        na = a;
        nb = 0;
        nc = b + c;
    }
    else {
        na = a;
        nb = b - (bowls[2] - c);
        nc = bowls[2];
    }
    if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        if (na == 0)
            bowl_c.insert(nc);
        dfs(na, nb, nc, bowls, bowl_c);
    }

    // c -> a
    if (a + c <= bowls[0]) {
        na = a + c;
        nb = b;
        nc = 0;
    }
    else {
        na = bowls[0];
        nb = b;
        nc = c - (bowls[0] - a);
    }
    if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        if (na == 0)
            bowl_c.insert(nc);
        dfs(na, nb, nc, bowls, bowl_c);
    }

    // c -> b
    if (b + c <= bowls[1]) {
        na = a;
        nb = b + c;
        nc = 0;
    }
    else {
        na = a;
        nb = bowls[1];
        nc = c - (bowls[1] - b);
    }
    if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        if (na == 0)
            bowl_c.insert(nc);
        dfs(na, nb, nc, bowls, bowl_c);
    }
}