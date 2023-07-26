//
// Created by 慕芸熙 on 2023/7/24.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
struct arr {
    int index;
    long long value;
} a[100002];

bool arr_comp(arr a1, arr a2) {
    if (a1.value == a2.value)
        return a1.value * a1.index < a2.value * a2.index;

    return a1.value < a2.value;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].value);
        a[i].index = i;
    }

    sort(a+1, a+n+1, arr_comp);

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i].index);
    }
}
