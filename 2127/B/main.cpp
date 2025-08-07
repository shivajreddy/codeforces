// B. Hamiiid, Haaamid... Hamid?
// https://codeforces.com/contest/2127/problem/B

#include <bits/stdc++.h>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)

void solve() {
    int n, x;
    cin >> n >> x;
    x--; // 0 index

    string s;
    cin >> s;

    int left_dist = x, right_dist = n - 1 - x;
    int left_wall_count = 0, right_wall_count = 0;

    const char WALL = '#';
    const char EMPTY = '.';

    loop(i, 0, x) {
        if (s[i] == WALL) left_wall_count++;
    }
    loop(i, x, n) {
        if (s[i] == WALL) right_wall_count++;
    }

    if (left_dist == 0 || right_dist == 0) {
        cout << 1 << endl;
        return;
    }
    if (left_wall_count == 0 && right_wall_count == 0) {
        cout << 1 << endl;
        return;
    }

    // closest left wall
    int left_wall_idx;
    loop(i, 0, x) {
        if (s[i] == WALL) left_wall_idx = i;
    }
    // closest right wall
    int right_wall_idx;
    loop(i, x, n) {
        if (s[i] == WALL) right_wall_idx = i;
    }
    s[x] = 'x';
    // cout << s << endl;
    // cout << "left_wall_idx: " << left_wall_idx << endl;
    // cout << "right_wall_idx: " << right_wall_idx << endl;
    int left_solid_wall = left_wall_idx + 1;       // days break out left
    int right_solid_wall = n - right_wall_idx + 1; // days break out right

    // int smartest_dist = max(left_solid_wall, right_solid_wall);
    // cout << smartest_dist << endl;
    // int shortest_dist = min(left_dist, right_dist) + 1;
    // cout << shortest_dist << endl;
    // cout << max(smartest_dist, shortest_dist) << endl;
    cout << "left_dist: " << left_dist << endl;
    cout << "right_solid_wall: " << right_solid_wall << endl;
    cout << "right_dist: " << right_dist << endl;
    cout << "left_solid_wall: " << left_solid_wall << endl;
    int L = max(left_dist, right_solid_wall);
    int R = max(right_dist, left_solid_wall);
    cout << min(L, R) + 1 << endl;

    // int shortest_dist = min(left_dist, right_dist) + 1;
    // int smartest_dist = min(left_wall_idx + 1, n - right_wall_idx + 1);
    // cout << max(shortest_dist, smartest_dist) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--) solve();
}
