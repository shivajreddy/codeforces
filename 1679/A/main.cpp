// A. AvtoBus
// https://codeforces.com/problemset/problem/1679/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void solve() {
    ll N;
    cin >> N;

    if (N % 4 != 0 && N % 6 != 0) {
        cout << "-1\n";
    }

    ll mx = N / 2;
    ll mn = (N + 1) / 3;
    cout << mn * 2 << " " << mx * 2 << endl;
    return;

    /*
    ll mn = 0, mx = 0;

    ll n = N;
    while (n > 0) {
        // pick as my 6 wheelers
        while (n % 6 == 0) {
            mn++;
            n /= 6;
        }
        while (n % 4 == 0) {
            mn++;
            n /= 4;
        }
    }

    n = N;
    while (n > 0) {
        // pick as my 6 wheelers
        while (n % 4 == 0) {
            mx++;
            n /= 4;
        }
        while (n % 6 == 0) {
            mx++;
            n /= 6;
        }
    }
    cout << mn << " " << mx << endl;


    ll a, b, res = -1;
    for (int a = 0; a < n / 4; a++) {
        for (int b = 0; b < n / 6; b++) {
            cout << "a:" << a << " b:" << b << endl;
            res = 4 * a + 6 * b;
            if (res == n) break;
        }
    }

    cout << res << "\n";
    */
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
