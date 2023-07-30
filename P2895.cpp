//
// Created by 慕芸熙 on 2023/7/30.
//

#include <bits/stdc++.h>

using namespace std;

int m;
int grid[302][302], meteor[302][302];
struct Pos {
    int x, y;
};
queue<Pos> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
    scanf("%d", &m);

    memset(meteor, 0x3f, sizeof meteor);

    for (int i = 1; i <= m; i++) {
        int t, x, y;
        scanf("%d %d %d", &x, &y, &t);
        meteor[x][y] = min(meteor[x][y], t);

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];

            if (nx < 0 || ny < 0) continue;

            meteor[nx][ny] = min(meteor[nx][ny], t);
        }
    }

    memset(grid, -1, sizeof grid);

    q.push({0, 0});
    grid[0][0] = 0;

    while (!q.empty()) {
        Pos front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = front.x + dx[i], ny = front.y + dy[i];

            if (nx < 0 || ny < 0) continue;
            if (grid[front.x][front.y] + 1 >= meteor[nx][ny]) continue;
            if (grid[nx][ny] != -1) continue;

            grid[nx][ny] = grid[front.x][front.y] + 1;
            q.push({nx, ny});

            if (meteor[nx][ny] > 1e9) {
                printf("%d", grid[nx][ny]);
                return 0;
            }
        }
    }

    printf("-1");
}
