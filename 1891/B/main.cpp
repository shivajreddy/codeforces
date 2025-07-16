// B. Deja Vu
// https://codeforces.com/problemset/problem/1891/B

#include <bits/stdc++.h>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void solve();

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--) solve();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    vi q(m);
    loop(i, 0, m) cin >> q[i];

    vi max_divisors(n);
    // go over a and check for all [1..30] the highest divisor
    loop(i, 0, n) { // 10^5
        int max_d = -1;
        for (int d = 30; d >= 1; d--) { // 30
            if (a[i] % (int)pow(2, d) == 0) {
                max_d = d;
                break;
            }
        }
        max_divisors[i] = max_d;
    }
    loop(i, 0, n) cout << max_divisors[i] << " ";
    cout << endl;

    vector<ll> res(n);
    loop(i, 0, n) res[i] = a[i];

    unordered_map<int, int> q_map; // { power : count}
    loop(d, 1, 31) q_map[d] = 0;

    loop(i, 0, m) { // 10^5
        int curr_q = q[i];
        for (int curr_d = 1; curr_d <= curr_q; curr_d++) { // 30
            q_map[curr_d] += (int)pow(2, curr_d - 1);
        }
    }

    vi final_adds(n, 0); // holds the final numbers that will be added
    loop(i, 0, n) {
        if (max_divisors[i] == -1) continue;
        int max_divisor = max_divisors[i];
        final_adds[i] = q_map[max_divisor];
    }

    loop(i, 0, n) { // 10^5
        res[i] = a[i] + final_adds[i];
    }

    /*
    loop(i, 0, m) {          // 10^5, xi=[1..30]
        ll d = pow(2, q[i]); // d=[2..2^30]
        ll add = pow(2, q[i] - 1);
        loop(j, 0, n) { // 10^5, ai=[1..10^9]
            if (res[j] % 2 == 1) continue;
            if (res[j] % d == 0) res[j] += add;
        }
    }
    */

    loop(i, 0, n) cout << res[i] << " ";
    cout << '\n';
}
