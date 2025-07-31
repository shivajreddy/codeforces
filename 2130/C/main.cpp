// C. Double Perspective
// https : // codeforces.com/contest/2130/problem/C

// { Imports, TypeNames, Macros
#include <bits/stdc++.h>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)
// }

void solve() {
    int n;
    cin >> n;

    vector<vi> edges(n, vector<int>(3));
    loop(i, 0, n) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][2] = i; // original index
    }

    // maximize f(s), minimize g(s)
    // for triangle of points a,b,c where a-c is straight,
    // then a-b + b-c >= a-c, also eliminating a-c will reduce g(s)
    // line sweep maybe
    sort(edges.begin(), edges.end());
    vi idx_but_sorted = { 0 };

    for (int i = 1; i < edges.size(); i++) {
        int prev_end = edges[idx_but_sorted.back()][1];
        if (prev_end <= edges[i][0]) {
            idx_but_sorted.push_back(i);
        }
    }

    cout << idx_but_sorted.size() << endl;
    for (int idx : idx_but_sorted) cout << edges[idx][2] + 1 << " ";
    cout << endl;
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
