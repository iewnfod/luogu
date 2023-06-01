//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>

using namespace std;

const int mod = 1000007;

int m, n;
int a[101];
int mem[101][101];

int dfs(int x, int total) {
    if (total > m) return 0;
    if (total == m) return 1;
    if (x > n) return 0;
    if (mem[x][total]) return mem[x][total];

    // 从一朵都不放，到全都放
    for (int j = 0; j <= a[x]; j++) {
        (mem[x][total] += dfs(x+1, total + j)) %= mod;
    }

    return mem[x][total];
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = dfs(1, 0);

    printf("%d", ans);
}
