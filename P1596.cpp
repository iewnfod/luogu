//
// Created by 慕芸熙 on 2023/7/19.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[101][101];
int status[101][101];
string s;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(int x, int y) {
    // 尝试8个方向
    for (int i = 0; i <= 7; i++) {
        int new_x = x + dx[i], new_y = y + dy[i];
        // 如果下一个位子是水坑，并且没有走过，那就可以走
        if (
            0 < new_x && new_x <= m && 0 < new_y && new_y <= n &&
            grid[new_y][new_x] &&
            !status[new_y][new_x]
        ) {
            status[new_y][new_x] = 1;
            dfs(new_x, new_y);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            switch (s[j]) {
                case '.': grid[i][j+1] = 0; break;
                case 'W': grid[i][j+1] = 1; break;
            }
        }
    }

    // 尝试每一个位子
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 如果那里可以走并且没有走过
            if (grid[i][j] && !status[i][j]) {
                // 标记为走过
                status[i][j] = 1;
                // 走所有的位子
                dfs(j, i);
                // 结果加一
                res ++;
            }
        }
    }

    printf("%d", res);
}
