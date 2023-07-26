//
// Created by 慕芸熙 on 2023/6/16.
//

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int w, h;
int grid[21][21], used[21][21];
int ans = 1;

void dfs(int x, int y) {
    // 查看四周四个点，是不是可行的，可行就走，或者不走，不行就不走
    for (int i = 0; i < 4; i ++) {
        int new_x = x + dx[i], new_y = y + dy[i];
        if (
            1 <= new_x && new_x <= w
            && 1 <= new_y && new_y <= h
            && grid[new_y][new_x]
            && !used[new_y][new_x]
        ) {
            used[new_y][new_x] = 1;
            ans ++;
            dfs(new_x, new_y);
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
                case '#':
                    grid[i][j] = 0;
                    break;
                case '.':
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
    dfs(start_x, start_y);

    printf("%d", ans);
}
