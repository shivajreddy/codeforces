// https://codeforces.com/contest/2123/problem/C

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
}

void solve(int n, vector<int>& v) {
    int mn = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());
    // cout << mn << " " << mx << "\n";
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> v;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            v.push_back(num);
        }

        solve(n, v);
    }
}
