// https://codeforces.com/problemset/problem/1034-2

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
}

bool is_same(const vector<int> arr) {
    if (arr.size() == 0) return false;
    int target = arr[0];
    for (int num : arr) {
        if (num != target) return false;
    }
    return true;
}

int main() {
    setupIO();

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int min = *min_element(arr.begin(), arr.end());
        int max = *max_element(arr.begin(), arr.end());
    }

    return 0;
}
