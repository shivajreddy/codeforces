// https://codeforces.com/problemset/problem/1855/B

#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void solve() {
    long long n;
    cin >> n;

    if (n & 1) {
        cout << "1\n";
        return;
    }

    // Find all the divisors
    unordered_set<long long> all_divisors;

    long long max_divisor = sqrt(n);
    for (int num = 1; num <= max_divisor; num++) {
        if (n % num == 0) {
            all_divisors.insert(num);
            all_divisors.insert(n / num); // its pair
        }
    }

    long long res = 0;
    for (long long num : all_divisors) {
        // this number could be the start of a continuos sequence
        if (all_divisors.find(num - 1) == all_divisors.end()) {
            long long curr_len = 0;
            long long curr_num = num;
            while (all_divisors.find(curr_num) != all_divisors.end()) {
                curr_num++;
                curr_len++;
                res = max(res, curr_len);
            }
        }
    }

    cout << res << "\n";
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
