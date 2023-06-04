//
// Created by 慕芸熙 on 2023/6/4.
//

#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    scanf("%lld", &n);

    double l = -1000000, r = 1000000;

    while(r - l >= 0.01) {
        double mid = (r + l) / 2;
        if (mid * mid * mid < n) {
            l = mid;
        } else {
            r = mid;
        }

    }

    int result = r;
    printf("%d\n", result);
}
