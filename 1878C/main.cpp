// https://codeforces.com/problemset/problem/1878/C

#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

void setupIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
}

void solve() {
  int n, k, x;
  cin >> n >> k >> x;

  int min_sum = (k * (k + 1)) / 2;
  // int max_sum = (k * (2 * n - k + 1)) / 2;
  int max_sum = (n * (n + 1)) / 2;
  // int max_sum = ((n - k + 1) * (k + n)) / 2;
  if (x < min_sum || x > max_sum) {
    cout << "NO\n";
    return;
  }
  if (x == min_sum || x == max_sum) {
    cout << "YES\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  setupIO();
  int tc;
  cin >> tc;
  while (tc--)
    solve();
}
