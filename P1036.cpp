//
// Created by 慕芸熙 on 2023/6/14.
//

#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[21];
int ans = 0, r = 0;

bool isPrime(int x) {
    if (x < 2) return false;
    else if (x == 2) return true;

    for (int i = 2; i < sqrt(x) + 1; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
}

void permutation(int x, int index) {
    if (x > k) {
        if (isPrime(r)) ans += 1;
        return ;
    }

    for (int i = index; i <= n; i++) {
        r += arr[i];
        permutation(x+1, i+1);
        r -= arr[i];
    }
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    permutation(1, 1);
    printf("%d", ans);
}
