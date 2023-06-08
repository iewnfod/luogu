//
// Created by 慕芸熙 on 2023/6/5.
//

#include <bits/stdc++.h>

using namespace std;

int n, k;
int wood[100001];

// 每段 x 长，能拿到多少段
int get_wood(int x) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += wood[i] / x;
    }
    return result;
}

int main() {
    scanf("%d %d", &n, &k);

    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &wood[i]);
        r = max(r, wood[i]);
    }

    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (get_wood(mid) >= k)
            // 如果拿到的段数更多，那就上每段变长
            l = mid;
        else
            r = mid;
    }

    printf("%d\n", l);
}
