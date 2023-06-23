//
// Created by 慕芸熙 on 2023/6/16.
//

#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int k[201], ans = INT_MAX, status[201];

struct a_floor {
    int floor;
    int times;
} current;
queue<a_floor> q;

int main() {
    scanf("%d %d %d", &n, &a, &b);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }

    q.push(a_floor {a, 0});

    while (!q.empty()) {
        current = q.front();
        q.pop();

        if (current.floor == b) ans = min(ans, current.times);

        // 尝试向上走
        if (current.floor + k[current.floor] <= n && !status[current.floor + k[current.floor]]) {
            status[current.floor + k[current.floor]] = 1;
            q.push(a_floor {current.floor + k[current.floor], current.times + 1});
        }

        // 尝试向下走
        if (current.floor - k[current.floor] >= 1 && !status[current.floor - k[current.floor]]) {
            status[current.floor - k[current.floor]] = 1;
            q.push(a_floor {current.floor - k[current.floor], current.times + 1});
        }
    }

    if (ans == INT_MAX) printf("-1");
    else printf("%d", ans);
}
