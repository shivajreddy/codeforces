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

    // n is odd, then there is only 1 contiguous divisor
    if (n < 3) {
        cout << n << "\n";
        return;
    }

    // x is the smallest_num_that_doesnt_divide_n
    int x = -1;
    for (int num = 1; num <= n; num++) {
        if (n % num != 0) {
            x = num;
            break;
        }
    }

    int res = x == -1 ? 2 : x - 1;
    cout << res << endl;

    /*
    long long max_divisor = sqrt(n);
    // cout << "max_divisor: " << max_divisor << endl;

    int max_len = 1, curr_len = 1;
    int prev = 1;
    for (int i = 2; i < max_divisor; i++) {
        if (n % i == 0) {
            if (i == prev + 1) {
                curr_len++;
            } else {
                curr_len = 1;
            }
            prev = i; // update prev
        }
        max_len = max(max_len, curr_len);
    }
    cout << max_len << "\n";
    */

    /*
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
    */
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
