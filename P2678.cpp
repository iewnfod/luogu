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

// 要达到这个距离，最少拿掉几块石头
int get_min_rock(int x) {
    int count = 0;
    int i = 0, now = 0;
    while (i <= n) {
        i ++;
        // 如果两者相减小于目标距离 x
        // 那就要拿掉，否则就说明这段距离已经够了，就将 now 修改为这个位置，等待下一次计算
        if (d[i] - d[now] < x)
            count ++;
        else
            now = i;
    }
    return count;
}

int main() {
    scanf("%d %d %d", &l, &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    d[n+1] = l;

    int left = 0, right = l + 1;

    while (left + 1 != right) {
        int mid = (left + right) / 2;
        // 如果最少拿掉的石头小于等于目标，代表可以再大一点
        if (get_min_rock(mid) <= m)
            left = mid;
        else
            right = mid;
    }

    if (get_min_rock(right) <= m)
        printf("%d", right);
    else
        printf("%d", left);
}
