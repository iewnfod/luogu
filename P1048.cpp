//
// Created by 慕芸熙 on 2023/5/31.
//

#include <bits/stdc++.h>

using namespace std;

int T, M;
int times[101], values[101];
int mem[101][1001];
int f[101][1001];

int dfs(int x, int used_time) {
    if (x > M) return 0;
    if (mem[x][used_time]) return mem[x][used_time];

    int sum = 0;
    if (used_time + times[x] > T) return 0;
    else sum = max(dfs(x+1, used_time), dfs(x+1, used_time + times[x]) + values[x]);

    return sum;
}

int main() {
    cin >> T >> M;

    for (int i = 1; i <= M; i++) {
        cin >> times[i] >> values[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = T; j > 0; j--) {
            if (j < times[i])
                f[i][j] = f[i-1][j];
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - times[i]] + values[i]);
        }
    }

    cout << f[M][T] << endl;
}
