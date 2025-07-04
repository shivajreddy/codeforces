// https://codeforces.com/contest/2119/problem/B

#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

// Euclidean distance
double get_dist(double x1, double y1, double x2, double y2) {
    int x = x1 - x2;
    int y = y1 - y2;
    return sqrt(x * x + y * y);
}

void solve() {
    int n;
    cin >> n;

    int px, py, qx, qy;
    cin >> px >> py >> qx >> qy;

    vector<int> v;
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
