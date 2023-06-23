//
// Created by 慕芸熙 on 2023/6/16.
//

#include <bits/stdc++.h>

using namespace std;

int n, s[11], b[11], diff = INT_MAX;
int sour = 1, bitter = 0;

void dfs(int x, int use) {
    if (x > n) {
        if (use) diff = min(abs(sour - bitter), diff);
    } else {
        // 不选，直接下一层
        dfs(x+1, use);
        // 加上并选
        sour *= s[x];
        bitter += b[x];
        dfs(x+1, use+1);
        // 还原
        sour /= s[x];
        bitter -= b[x];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &s[i], &b[i]);
    }

    dfs(1, 0);
    printf("%lld", diff);
}
