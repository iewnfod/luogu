//
// Created by 慕芸熙 on 2023/7/29.
//

#include <bits/stdc++.h>

using namespace std;

int n;
int grid[32][32], state[32][32];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
struct Pos {
    int x, y;
};
queue<Pos> q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // 从 0 0 开始搜索，那么，遍历完后剩下的还是 0 的就一定是被包围的
    q.push({0, 0});
    state[0][0] = 1;

    while (!q.empty()) {
        Pos front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = front.x + dx[i], ny = front.y + dy[i];

            if (nx < 0 || nx > n+1 || ny < 0 || ny > n+1) continue;
            if (state[nx][ny]) continue;
            if (grid[nx][ny]) continue;

            state[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 如果这里没有走过，并且是0，那就是封闭的部分，就输出2
            if (!grid[i][j] && !state[i][j])
                printf("2 ");
            else
                printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
