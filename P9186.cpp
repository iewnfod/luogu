//
// Created by 慕芸熙 on 2023/8/27.
//

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 150005;

int n, q, x, y, pos, oldPos, ans2;
int a[N], b[N], sum[N];

int getPos(int target) {
    int l = 0, r = n+1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;

        if (b[mid] < target)
            l = mid;
        else
            r = mid;
    }
    return r;
}

signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }

    // 预处理
    sort(b + 1, b + n + 1);
    sum[1] = b[1];
    int ans1 = b[1];
    map<int, int> position;
    position[b[1]] = 1;
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + b[i];
        ans1 += i * b[i];
        position[b[i]] = i;
    }

    scanf("%lld", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%lld %lld", &x, &y);
        if (a[x] == y) {
            printf("%lld\n", ans1);
        } else if (a[x] > y) {
            pos = getPos(y);
            oldPos = position[a[x]];
            ans2 = ans1 + (sum[oldPos-1] - sum[pos-1]) - (oldPos * a[x]) + (y * pos);
            printf("%lld\n", ans2);
        } else {
            pos = getPos(y) - 1;
            oldPos = position[a[x]];
            ans2 = ans1 - (oldPos * a[x]) - (sum[pos] - sum[oldPos]) + (y * pos);
            printf("%lld\n", ans2);
        }
    }
}
