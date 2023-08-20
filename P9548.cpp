//
// Created by 慕芸熙 on 2023/8/16.
//

#include <bits/stdc++.h>

using namespace std;

long long n, m, x, y, k;

int main() {
    scanf("%lld %lld %lld %lld %lld", &n, &m, &x, &y, &k);

    long long result = (long long)((n-1)/x) + (long long)((m-1)/y) + (long long)(m/y - 1) * (long long)(n/x - 1);

    printf("%lld %lld", (long long)ceil(result * 1.0 / k), result);
}
