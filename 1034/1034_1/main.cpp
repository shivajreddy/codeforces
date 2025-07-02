// https://codeforces.com/problemset/problem/1034

#include <iostream>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
}

// #define a alice
// #define b bob

void solution(int n) {
    if (n <= 2) {
        cout << "alice\n";
        return;
    }

    if (n % 4 == 0) {
        cout << "bob\n";
    } else {
        cout << "alice\n";
    }
}

int main() {
    setupIO();

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;

        solution(n);
    }
}
