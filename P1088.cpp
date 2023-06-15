//
// Created by 慕芸熙 on 2023/6/14.
//

#include <bits/stdc++.h>

using namespace std;

const int N = 10002;

int n, m;
int arr[N], r[N];
bool status[N], first_reach[N];
int num, target = -1;

bool permutation(int x) {
    if (x > n) {
        num ++;
        // 如果这个数字和目标相同，那么就输出
        if (num == m + 1) {
            for (int i = 1; i <= n; i++) {
                printf("%d", r[i]);
                if (i != n) printf(" ");
            }
            return true;
        }
        return false;
    }

    // 从火星人给的这个数开始往下枚举
    int start = 1;
    if (first_reach[x]) {
        start = arr[x];
        first_reach[x] = false;
    }
    for (int i = start; i <= n; i++) {
        if (!status[i]) {
            r[x] = i;
            status[i] = true;
            if (permutation(x+1)) return true;
            r[x] = 0;
            status[i] = false;
        }
    }

    return false;
}


int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    fill_n(first_reach, n+1, true);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    permutation(1);
}
