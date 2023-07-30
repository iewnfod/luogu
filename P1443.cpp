//
// Created by 慕芸熙 on 2023/7/27.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int grid[401][401];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
struct pos {
    int x, y;
};
queue<pos> q;

int main() {
    scanf("%d %d", &n, &m);
    // 填充 -1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            grid[i][j] = -1;
        }
    }
    // 读取起始位置
    scanf("%d %d", &x, &y);
    grid[x][y] = 0;
    q.push({x, y});

    // bfs
    while (!q.empty()) {
        pos front = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];

            // 如果超出边界，下一个
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            // 如果这个店已经走过了，下一个
            if (grid[nx][ny] != -1) continue;

            // 计数 & 进入队列
            grid[nx][ny] = grid[front.x][front.y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }
}
