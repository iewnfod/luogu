//
// Created by 慕芸熙 on 2023/6/1.
//

#include <bits/stdc++.h>

using namespace std;

int v, n;
int items[31];
int f[20001];

int main() {
    scanf("%d", &v);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &items[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v; j > 0; j--) {
            if (items[i] <= j)
                // 如果可以装，那就可以选择装或者不装
                f[j] = max(f[j], f[j - items[i]] + items[i]);
        }
    }

    printf("%d", v - f[v]);
}
