//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[101];
int f[101][100001];  // f[i][j] 表示看过 i 个菜，花掉 j 元的方法有多少种

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 如果刚好钱相同，那就点上，也就是方法数 + 1
            if (j == a[i]) f[i][j] = f[i - 1][j] + 1;
            // 如果钱不够，那就不点，那就是不吃这道菜的方法
            if (j < a[i]) f[i][j] = f[i - 1][j];
            // 如果钱多，那也可以点，那就是吃这道菜的方法，加上不吃这道菜的方法
            if (j > a[i]) f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
        }
    }

    cout << f[n][m] << endl;
}
