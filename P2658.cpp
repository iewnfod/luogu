//
// Created by 慕芸熙 on 2023/7/31.
//

#include <bits/stdc++.h>

using namespace std;

int m, n;
int height[501][501];
int grid[501][501];
int startX, startY;
struct Pos {
    int x, y;
};
int signNum;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool bfs(int d) {
    int used[501][501];

    queue<Pos> q;
    q.push({startX, startY});
    used[startX][startY] = 1;

    int currentSignNum = 1;

    while (!q.empty()) {
        Pos front = q.front();
        q.pop();

        if (currentSignNum == signNum) return true;

        for (int i = 0; i < 4; i++) {
            int nx = front.x + dx[i], ny = front.y + dy[i];

            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (used[nx][ny]) continue;
            if (abs(height[nx][ny] - height[front.x][front.y]) > d) continue;

            used[nx][ny] = 1;
            q.push({nx, ny});
            if (grid[nx][ny]) currentSignNum ++;
        }
    }

    return false;
}

int main() {
    int left, right, mid;

    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &height[i][j]);
            right = max(right, height[i][j]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 1) {
                if (signNum == 0) {
                    startX = i;
                    startY = j;
                }
                signNum ++;
            }
        }
    }

    left = 0;

    while (left + 1 != right) {
        mid = (left + right) / 2;

        if (bfs(mid))
            left = mid;
        else
            right = mid;
    }

    printf("%d", mid);
}
