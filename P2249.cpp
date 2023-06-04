//
// Created by 慕芸熙 on 2023/6/3.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1000001];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < m; i ++) {
        int target;
        scanf("%d", &target);

        int l = 0, r = n+1;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (arr[mid] < target)
                l = mid;
            else
                r = mid;
        }

        if (arr[r] == target)
            printf("%d ", r);
        else
            printf("-1 ");
    }

    return 0;
}
