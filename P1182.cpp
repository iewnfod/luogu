//
// Created by 慕芸熙 on 2023/6/10.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100002];

// 为了使得每段的和的最大值达到x，最少需要多少段
int min_section_number(int x) {
    int count = 0, total = 0;
    for (int i = 1; i <= n; i++) {
        if (total + arr[i] <= x) total += arr[i];
        else {
            total = arr[i];
            count ++;
        }
    }
    return count;
}

int main() {
    int l = 0, r = 0;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        r += arr[i];
    }

    while (l + 1 != r) {
        int mid = (l + r) / 2;
        // 如果所需的段数小于m，说明可以再增大
        if (min_section_number(mid) < m)
            r = mid;
        else
            l = mid;
    }

    if (min_section_number(r) < m)
        printf("%d", r);
    else
        printf("%d", l);
}
