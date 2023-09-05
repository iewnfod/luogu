//
// Created by 慕芸熙 on 2023/8/26.
//

#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    int c[N];  // 房间颜色
    int s[N];  // 拥有的钥匙颜色
    int f[N];  // 需要的钥匙颜色
    int grid[N][N];  // 可通行的地图 grid[i][j] 表示 i 可以到 j，j 也可以到 i
    int u, v;
    // input
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &u, &v);
        grid[u][v] = 1;
        grid[v][u] = 1;
    }

    map<int, bool> haveKey;
    queue<int> q;
    bool walked[100001];

    q.push(1);
    haveKey[1] = true;
    walked[1] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (grid[front][i]) {
                if (haveKey[i]) {
                    // 如果可以走，那就走
                    q.push(i);
                    walked[i] = true;
                }
            }
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!walked[i]) {
            flag = false;
            break;
        }
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        solve();
    }
}
