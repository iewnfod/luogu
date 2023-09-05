//
// Created by 慕芸熙 on 2023/8/28.
//

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int num = 0, sum = 0;
int n, m, k, ans[N];
struct node {
    int value=0, index=0;
    int usedTime = 0;
    friend bool operator<(node a, node b) {
        if (a.value == b.value)
            return a.index < b.index;
        return a.value < b.value;
    }
} nums[N];


int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i].value);
        nums[i].index = i;
    }

    sort(nums+1, nums+n+1);

    for (int i = 1; i <= n; i++) {
        if (nums[i].usedTime) {
            ans[nums[i].index] = nums[i].usedTime;
            continue;
        }

        num ++;
        ans[nums[i].index] = num;
        nums[i].usedTime = num;

    }

}
