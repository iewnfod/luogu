//
// Created by 慕芸熙 on 2023/9/3.
//

#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;
int n, t_c, t_m;
int a[101], b[101], c[101];

bool check(int m) {
    int l=max(0LL, m - t_m + 1), r=min(t_c - 1, m);
    for (int i = 1; i <= n; i++) {
        int k = c[i] - b[i] * t_m - a[i] * t_c + b[i] * m;
        int left = b[i] - a[i];
        if (left < 0)
            l = max(l, (int)ceil(k * 1.0 / left));
        else if (left > 0)
            r = min(r, (int)floor(k * 1.0 / left));
        else
            if (k < 0) return false;
    }
    return r >= l;
}

signed main() {
    scanf("%lld", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%lld %lld %lld", &n, &t_c, &t_m);
        for (int j = 1; j <= n; j++) {
            scanf("%lld %lld %lld", &a[j], &b[j], &c[j]);
        }

        int l = -1, r = t_c + t_m - 1;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid;
        }

        printf("%lld\n", r);
    }
}
