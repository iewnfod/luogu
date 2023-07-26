//
// Created by 慕芸熙 on 2023/7/25.
//

#include <bits/stdc++.h>

using namespace std;

int start_x, end_x, start_y, end_y;
int n;
bool grid[1001][1001], used[1001][1001];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int res;
struct pos {
    int x, y, num;
};
queue<pos> q;

int main() {
    scanf("%d", &n);
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            switch (s[j-1]) {
                case '0': grid[i][j] = false; break;
                case '1': grid[i][j] = true; break;
            }
        }
    }

    scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);

    used[start_x][start_y] = true;
    q.push({start_x, start_y, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        if (front.x == end_x && front.y == end_y) {
            res = front.num;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (grid[nx][ny]) continue;
            if (used[nx][ny]) continue;

            used[nx][ny] = true;
            q.push({nx, ny, front.num+1});
        }
    }

    printf("%d", res);
}
