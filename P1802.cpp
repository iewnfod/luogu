//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>

using namespace std;

// x 表示总共有的药的数量
int n, x;
long long lose[1002], win[1002], use[1002];
long long f[1002];

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &lose[i], &win[i], &use[i]);
    }

    // 只有两个选择，要么嗑药，要么不嗑药，嗑一半是没有意义的
    for (int i = 1; i <= n; i ++) {
        // 需要倒序，否则会先把前面的值覆盖掉导致错误，比如 f[j-use[i]] 这个值如果先计算了，那后面依赖他的值就会出错，导致结果错误
        for (int j = x; j >= 0; j --) {
            // 如果要用的药比 j 少
            // 选择嗑药或者不嗑药
            // 否则只能不嗑药
            if (use[i] <= j)
                f[j] = max(f[j], max(f[j] + lose[i], f[j-use[i]] + win[i]));
            else
                f[j] += lose[i];
        }
    }

    printf("%lld", f[x] * 5);
}
