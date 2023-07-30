//
// Created by 慕芸熙 on 2023/7/29.
//

#include <bits/stdc++.h>

using namespace std;

int m, n, m1, m2;
bool grid[31][31];
int dis[31][31];
int end_x, end_y;

struct Pos {
    int x, y;
};
queue<Pos> q;

int main() {
    scanf("%d %d %d %d", &m, &n, &m1, &m2);
    memset(dis, -1, sizeof dis);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            scanf("%d", &a);
            switch (a) {
                case 0: grid[i][j] = false; break;
                case 1: grid[i][j] = true; break;
                case 2: grid[i][j] = false; break;
                case 3: {
                    grid[i][j] = true;
                    q.push({i, j});
                    dis[i][j] = 0;
                    break;
                }
                case 4: {
                    grid[i][j] = true;
                    end_x = i;
                    end_y = j;
                    break;
                }
            }
        }
    }

    int dx[] = {m1, m1, m2, m2, -m1, -m1, -m2, -m2};
    int dy[] = {m2,  -m2, m1, -m1, m2, -m2, m1, -m1};

    while (!q.empty()) {
        Pos front = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = front.x + dx[i], ny = front.y + dy[i];

            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (!grid[nx][ny]) continue;
            if (dis[nx][ny] != -1) continue;

            dis[nx][ny] = dis[front.x][front.y] + 1;
            q.push({nx, ny});

            if (nx == end_x && ny == end_y) {
                printf("%d", dis[nx][ny]);
                break;
            }
        }
    }
}
