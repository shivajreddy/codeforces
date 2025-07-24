// B. 2D Traveling
// https://codeforces.com/problemset/problem/1869/B

// { Imports, TypeNames, Macros
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
// template <typename T> using pq = priority_queue<T>;
// template <typename T>
// using min_pq = priority_queue<T, vector<pii>, greater<pii>>;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)
// }

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vector<vector<int>> mat(n, vector<int>(2));
    loop(i, 0, n) cin >> mat[i][0] >> mat[i][1];

    auto get_dist = [&](int city1_idx, int city2_idx) -> int {
        if (city1_idx < k && city2_idx < k) return 0; // both are major cities
        int ax = mat[city1_idx][0], ay = mat[city1_idx][1];
        int bx = mat[city2_idx][0], by = mat[city2_idx][1];
        return abs(bx - ax) + abs(by - ay);
    };

    // Dijkstra's Shortest Path
    int start = a - 1, target = b - 1;

    // min-heap where the smalelst pair.first comes to the top
    priority_queue<pii, vector<pii>, greater<pii>> min_heap;
    unordered_set<int> visited { start };

    loop(i, 0, n) {
        if (i == start) continue;
        auto d = get_dist(start, i);
        // cout << "d:" << d << " i:" << i << endl;
        min_heap.push({ d, i });
    }

    // test
    while (!min_heap.empty()) {
        auto top = min_heap.top();
        // cout << "picked: [" << top.first << "," << top.second << ",(";
        // cout << mat[top.second][0] << "," << mat[top.second][1] << ")]\n";
        // Relaxation: from this node
        min_heap.pop();
    }
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
