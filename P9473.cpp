//
// Created by 慕芸熙 on 2023/7/24.
//

#include <bits/stdc++.h>

using namespace std;

int T;

vector<int> prime(int n) {
    vector<int> result;
    result.push_back(2);

    for (int i = 3; i < n; i++) {
        bool flag = true;
        int jStop = sqrt(i);
        for (int j = 3; j <= jStop; j+=2) {
            if (!(i % j)) {
                flag = false;
                break;
            }
        }

        if (flag) {
            result.push_back(i);
            printf("%d\n", i);
        }
    }

    return result;
}

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
