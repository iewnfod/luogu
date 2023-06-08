//
// Created by 慕芸熙 on 2023/6/4.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1000001];

long long get_wood(int height) {
    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += max(0, arr[i] - height);
    }
    return result;
}

int main() {
    scanf("%d %d", &n, &m);

    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        r = max(r, arr[i]);
    }

    while (l + 1 != r) {
        int mid = (l + r) / 2;
        // 如果你拿到的木头要比要求的多
        if (get_wood(mid) >= m)
            l = mid;
        else
            r = mid;
    }

    printf("%d\n", l);
}
