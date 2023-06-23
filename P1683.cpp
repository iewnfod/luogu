//
// Created by 慕芸熙 on 2023/6/16.
//

#include <bits/stdc++.h>

using namespace std;

const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int w, h;
int grid[21][21], used[21][21];
int ans;

void dfs(int x, int y, int n) {
    printf("Move to: %d %d\n", x, y);
    ans = max(ans, n);
    // 查看四周四个点，是不是可行的，可行就走，或者不走，不行就不走
    for (auto direction : directions) {
        int new_x = x + direction[0], new_y = y + direction[1];
        if (
                1 <= new_x && new_x <= w
                && 1 <= new_y && new_y <= h
                && grid[new_y][new_x]
                && !used[new_y][new_x]
        ) {
            used[new_y][new_x] = 1;
            dfs(new_x, new_y, n+1);
            used[new_y][new_x] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &w, &h);
    int start_x, start_y;
    for (int i = 1; i <= h; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; j++) {
            switch (s[j-1]) {
                case '.':
                    grid[i][j] = 0;
                    break;
                case '#':
                    grid[i][j] = 1;
                    break;
                case '@':
                    grid[i][j] = 1;
                    start_x = j;
                    start_y = i;
                    break;
                default:
                    break;
            }
        }
    }

    used[start_y][start_x] = 1;
    dfs(start_x, start_y, 1);

    printf("%d", ans);
}
