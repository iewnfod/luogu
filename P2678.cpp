//
// Created by 慕芸熙 on 2023/6/5.
//

#include <bits/stdc++.h>

using namespace std;

// l 表示总距离
// n 表示总共的石头数
// m 表示可以移掉的石头的总数
int l, n, m;
// d[i] 表示第i块石头到起点的距离
int d[50002];

bool check(int x) {

}

int main() {
    scanf("%d %d %d", &l, &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    d[n+1] = 25;

    int left = 0, right = l + 1;

    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid;
    }
}
