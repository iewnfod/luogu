//
// Created by 慕芸熙 on 2023/7/30.
//

#include <bits/stdc++.h>

using namespace std;

int t;
struct Pos {
    int x, y;
};
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};;
int block[1001][1001];
int grid[1001][1001];

int main() {
    scanf("%d", &t);

    for (int _ = 1; _ <= t; _++) {
        int n;
        scanf("%d", &n);

        // 特殊处理，如果是1，那就直接可以
        if (n == 1) {
            printf("Yes\n");
            continue;
        }

        // 初始化数据
        memset(block, 0x3f, sizeof block);
        memset(grid, -1, sizeof grid);

        // 读取数据
        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            block[x][y] = i;
        }

        // bfs
        queue<Pos> q;
        q.push({1, 1});
        grid[1][1] = 0;

        bool flag = false;
        while (!q.empty()) {
            Pos front = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = front.x + dx[i], ny = front.y + dy[i];

                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if (grid[nx][ny] != -1) continue;
                if (grid[front.x][front.y] + 1 > block[nx][ny]) continue;

                grid[nx][ny] = grid[front.x][front.y] + 1;
                q.push({nx, ny});

                if (nx == n && ny == n) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) printf("Yes\n");
        else printf("No\n");
    }
}
