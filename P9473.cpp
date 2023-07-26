//
// Created by 慕芸熙 on 2023/7/24.
//

#include <bits/stdc++.h>

using namespace std;

int T;

int gcd(int a, int b) {
    int temp = b;
    while (a % b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return temp;
}

bool solve() {
    int arr[500010];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 2) return true;

    // 如果所有数，两两互质，那么就是成立的
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (gcd(arr[i], arr[j]) != 1) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        if (solve()) printf("Yes\n");
        else printf("No\n");
    }
}
