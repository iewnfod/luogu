//
// Created by 慕芸熙 on 2023/6/9.
//

#include <bits/stdc++.h>

using namespace std;

// l: 公路总长度
// n: 原有路标数量
// k：最多可增加的路标数量
int l, n, k;
int arr[100002];

// 获取最少需要添加的路标数量，以达到x的空旷指数
// 空旷指数表示公路上相邻路标间的最大距离
int get_min_number(int x) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        // 如果两个之间距离大于x，那就说明需要添加路标
        // 路标一个个添加，直到距离小于等于要求的，那就不用加了
        int dis = arr[i] - arr[i-1];
        if (dis > x) {
            count += dis / x;
            // 如果是整除的，那就减去重复的一个
            if (dis % x == 0) count --;
        }
    }
    return count;
}

int main() {
    scanf("%d %d %d", &l, &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = l+1;
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        // 如果最少需要插入的路标大于最多可增加的路标数量，说明可能的空旷指数更大
        if (get_min_number(mid) > k)
            left = mid;
        else
            right = mid;
    }

    if (get_min_number(left) > k)
        printf("%d", right);
    else
        printf("%d", left);
}
