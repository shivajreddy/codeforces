// https://codeforces.com/problemset/problem/4/A
#include <iostream>
using namespace std;

void readInput() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
}

int main() {
    readInput();

    int weight;
    cin >> weight;

    cout << "weight:" << weight << "\n";

    if (weight > 2 && weight % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
