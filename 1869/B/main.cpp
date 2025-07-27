// B. 2D Traveling
// https://codeforces.com/problemset/problem/1869/B

// { Imports, TypeNames, Macros
#include <bits/stdc++.h>
#include <climits>
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
    int n, k, s, t;
    cin >> n >> k >> s >> t;

    vector<ll> x(n + 1), y(n + 1);
    loop(i, 1, n + 1) cin >> x[i] >> y[i];

    ll ans = abs(x[s] - x[t]) + abs(y[s] - y[t]);
    ll mins = 1e17, mint = 1e17;
    loop(i, 1, k + 1) {
        mins = min(mins, abs(x[s] - x[i]) + abs(y[s] - y[i]));
        mint = min(mint, abs(x[t] - x[i]) + abs(y[t] - y[i]));
    }
    ans = min(ans, mins + mint);
    cout << ans << endl;
}

void solve2() {
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
    int prev = INT_MAX;
    while (!min_heap.empty()) {
        while (!min_heap.empty() && min_heap.top().first <= prev) {
            auto top = min_heap.top();
            cout << "picked: [" << top.first << "," << top.second << ",(";
            cout << mat[top.second][0] << "," << mat[top.second][1] << ")]\n";
            min_heap.pop();
            prev = top.first;
        }
        prev = INT_MAX;
        cout << "---" << endl;
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
