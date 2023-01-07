#include <bits/stdc++.h>

#define FOR(i, n, m) for (int i=(n); i<=(m); i++)
#define si(n) fscanf(IN, "%d", &n)

using namespace std;

typedef long long ll;
FILE *IN = stdin, *OUT = stdout;

int a, b, c;

void in() {
    ios::sync_with_stdio(false); cin.tie(0);
    si(a), si(b);
}

void solve() {
    c = a + b;
}

void out() {
    printf("%d\n", c);
}

int main() {
    in();
    solve();
    out();
}