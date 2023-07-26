//
// Created by 慕芸熙 on 2023/7/23.
//

#include <bits/stdc++.h>

using namespace std;

int n, k;
int l[7];
int res;

// cur 表示当前的还要加起来是的数，num 表示已经分成多少分了
void dfs(int cur, int num) {
    if (num == k) {
        if (!cur) res ++;
        return ;
    }

    // 因为剩下的数都会大于等于 l[num]
    // 那么只要剩下需要的个数 * l[num] 大于了目标，那就不行了
    for (int i = l[num]; i * (k-num) <= cur; i++) {
        l[num+1] = i;
        dfs(cur-i, num+1);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    l[0] = 1;
    dfs(n, 0);
    printf("%d", res);
}
