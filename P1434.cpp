//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>

using namespace std;

int row, column;
int grid[201][201];

int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int mem[201][201];

int dfs(int x, int y) {
    if (mem[x][y]) return mem[x][y];

    mem[x][y] = 1;
    for (auto & direction : directions) {
        int i = x + direction[0];
        int j = y + direction[1];

        if (0 < i && i <= row && 0 < j && j <= column && grid[i][j] < grid[x][y]) {
            mem[x][y] = max(mem[x][y], dfs(i, j) + 1);
        }
    }

    return mem[x][y];
}

int main() {
    scanf("%i %i", &row, &column);

    for (int i = 1; i <= row ; i++) {
        for (int j = 1; j <= column; j++) {
            scanf("%i", &grid[i][j]);
        }
    }

    int result = 0;
    for (int i = 1; i <= row ; i++) {
        for (int j = 1; j <= column; j++) {
            result = max(result, dfs(i, j));
        }
    }

    printf("%i", result);
    return 0;
}
