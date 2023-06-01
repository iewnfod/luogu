//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>

using namespace std;

int r;
int grid[1002][1002];

int main() {
    scanf("%d", &r);

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    for (int i = r-1; i > 0; i --) {
        for (int j = 1; j <= i; j++) {
            grid[i][j] += max(grid[i+1][j], grid[i+1][j+1]);
        }
    }

    printf("%d", grid[1][1]);
}
