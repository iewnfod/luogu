//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>

using namespace std;

// 生物种类 n
// 关系数量 m
int n, m;
int mod = 80112002;
// s[i] 表示第 i 个动物是否被使用过，未使用为 0，使用为 1
int s[5001];
vector<vector<int>> f;

// eat[i] 表示第 i 个会不会吃别人，不会为 0，会为 1
int eat[5001];
// eaten[i] 表示第 i 个会不会被人吃，不会为 0，会为 1
int eaten[5001];
int a, b;
int mem[5001];

int dfs(int x) {
    // 如果没有被吃过，那就是一个食物链的结尾
    if (!eaten[x]) return 1;
    // 如果直接计算过了，直接返回
    if (mem[x]) return mem[x];

    int result = 0;
    for (auto i : f[x]) {
        if (!s[i]) {
            s[i] = 1;
            result += dfs(i);
            result %= mod;
            s[i] = 0;
        }
    }

    mem[x] = result;
    return result;
}

int main() {
    f.resize(5001);

    scanf("%i %i", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%i %i", &a, &b);
        f[a].push_back(b);
        eat[b] = 1;
        eaten[a] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n ; i++) {
        // 如果他不吃别人，那他可以是一个食物链的开头
        if (!eat[i]) {
            s[i] = 1;
            ans += dfs(i);
            ans %= mod;
            s[i] = 0;
        }
    }

    printf("%i", ans);
}
