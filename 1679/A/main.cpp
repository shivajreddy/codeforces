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
/*
x4+y6 = n

OBSERVATIONS:

x: min=0 max=n/4
y: min=0 max=n/6


while n > 0 :
    if n % 6 == 0:
        count6++
        n /= 6
    else:
        rem++
        n--
if rem % 4 != 0:

for min number of busses:
                all are 6,
                then mix with mostly 6 and other 4,
                then no 6 only 4
for max number of buses:
                all are 4
                mix of 4 and 6 - mostly 4
                no 4 all 6

*/

// 1:49
void solve() {
    ll n;
    cin >> n;

    ll mn = -1, mx = -1;

    ll curr6, curr4;
    // MAX
    curr6 = n, curr4 = 0;
    while (curr6 % 6 != 0 && curr4 % 4 != 0) {
        curr6--;
        curr4++;
    }
    if (curr6 % 6 == 0 && curr4 % 4 == 0) {
        mx = curr6 / 6 + curr4 / 4;
    }

    // MIN
    curr6 = 0, curr4 = n;
    while (curr6 % 6 != 0 && curr4 % 4 != 0) {
        curr6++;
        curr4--;
    }
    if (curr6 % 6 == 0 && curr4 % 4 == 0) {
        mn = curr6 / 6 + curr4 / 4;
    }

    /*
    ll count6, count4, rem;


    // Max
    count6 = 0;
    count4 = 0;
    rem = 0;
    if (n % 6 == 0) {
        count6 = n / 6;
    } else {
        rem = n % 6;
        count6 = (n - rem) / 6;
    }
    if (rem % 4 == 0) {
        count4 = rem / 4;
        mn = count6 + count4;
    }
    // 548 : 540 8
    // mn:92 mx:137

    // Min
    count6 = 0;
    count4 = 0;
    rem = 0;
    if (n % 4 == 0) {
        count4 = n / 4;
    } else {
        rem = n % 4;
        count4 = (n - rem) / 4;
    }
    if (rem % 6 == 0) {
        count6 = rem / 6;
        mx = count6 + count4;
    }
    cout << "mn:" << mn << " mx:" << mx << endl;
    */

    // Couldnt form x6+y4=n
    if (mn == -1 && mx == -1) {
        cout << "-1\n";
    } else if (mn != -1 && mx == -1) {
        cout << mn << " " << mn << endl;
    } else if (mx != -1 && mn == -1) {
        cout << mx << " " << mx << endl;
    } else {
        cout << mn << " " << mx << endl;
    }
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--) solve();
}
