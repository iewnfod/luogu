//
// Created by 慕芸熙 on 2023/7/29.
//

#include <bits/stdc++.h>

using namespace std;

int bx1, by1, wx2, wy2;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1, 2, 2, -2, -2};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2, 2, -2, -2, 2};
struct Pos {
    int x, y;
};
int grid[21][21];

void bfs(int x, int y) {
    memset(grid, -1, sizeof grid);
    grid[x][y] = 0;

    queue<Pos> q;
    q.push({x, y});

    while (!q.empty()) {
        Pos front = q.front();
        q.pop();

        for (int i = 0; i < 12; i++) {
            int nx = dx[i] + front.x, ny = dy[i] + front.y;

            if (nx < 1 || nx > 20 || ny < 1 || ny > 20) continue;
            if (grid[nx][ny] >= 0) continue;

            grid[nx][ny] = grid[front.x][front.y] + 1;
            q.push({nx, ny});

            if (nx == 1 && ny == 1) {
                printf("%d\n", grid[nx][ny]);
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &bx1, &by1, &wx2, &wy2);

    bfs(bx1, by1);
    bfs(wx2, wy2);
}
