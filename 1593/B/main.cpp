// B. Make it Divisible by 25
// https://codeforces.com/problemset/problem/1593/B

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
    string n;
    cin >> n;

    const vector<string> subseqs = { "00", "25", "50", "75" };
    const int INF = 100;

    auto getSolution = [&](const string& target) -> int {
        int sptr = n.length() - 1;
        int ans = 0;

        // Find rightmost occurrence of second digit
        while (sptr >= 0 && n[sptr] != target[1]) {
            sptr--;
            ans++;
        }

        if (sptr < 0) return INF;

        sptr--;

        // Find leftmost occurrence of first digit (to the left of second digit)
        while (sptr >= 0 && n[sptr] != target[0]) {
            sptr--;
            ans++;
        }

        return sptr < 0 ? INF : ans;
    };

    int result = INF;
    for (const string& subseq : subseqs) {
        result = min(result, getSolution(subseq));
    }

    cout << result << '\n';
}

void solve2() {
    ll x;
    cin >> x;
    string x_str = to_string(x);
    int n = x_str.size();

    vi a(n);
    int i = n - 1;
    while (x > 0) {
        a[i] = x % 10;
        x /= 10;
        i--;
    }
    // for (int num : a) cout << num << " ";
    // cout << endl;

    // 012345
    // 300077

    int res = n;
    for (int i = n - 1; i >= 0; i--) {
        int digit = a[i];

        if (digit == 0) {
            if (i >= 2 && a[i - 1] == 0) { // ending is 00
                int to_remove = n - 1 - i;
                res = min(res, to_remove);
            }
            // find idx of 5
            int idx = i - 1;
            while (idx >= 0) {
                if (a[idx] == 5) break;
                idx--;
            }
            if (idx >= 0) {
                int to_remove = i - idx - 1; // digits between 5 & 0
                to_remove += n - 1 - i;      // all digits after 0
                res = min(res, to_remove);
            }
        } else if (digit == 5) {
            int idx = i;
            while (idx >= 0) {
                if (a[idx] == 2 || a[idx] == 7) break;
                idx--;
            }
            if (idx >= 0) {
                int to_remove = i - idx - 1; // digits between 5 & 0
                to_remove += n - 1 - i;      // all digits after 0
                res = min(res, to_remove);
            }
        } else
            continue;
    }
    cout << res << endl;
}
