//
// Created by 慕芸熙 on 2023/7/28.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int grid[501][501];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int x, y;

struct Pos {
    int x, y;
};
queue<Pos> q;

int main() {
    scanf("%d %d %d %d", &n, &m, &a, &b);

    memset(grid, -1, sizeof(grid));

    for (int i = 1; i <= a; i++) {
        scanf("%d %d", &x, &y);
        grid[x][y] = 0;
        q.push({x, y});
    }

    // bfs
    while (!q.empty()) {
        Pos front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = front.x + dx[i], ny = front.y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (grid[nx][ny] >= 0) continue;

            grid[nx][ny] = grid[front.x][front.y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= b; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", grid[x][y]);
    }
}
