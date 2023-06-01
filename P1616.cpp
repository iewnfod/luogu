//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>
#define int long long

using namespace std;

int m, t;
int times[10001], values[10001];
int f[10000001];

signed main() {
    cin >> t >> m;

    for (int i = 1; i <= m; i++) {
        cin >> times[i] >> values[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = times[i]; j <= t; j++) {
            f[j] = max(f[j], f[j-times[i]] + values[i]);
        }
    }

    cout << f[t] << endl;
}
