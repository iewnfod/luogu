#include "bits/stdc++.h"

using namespace std;

long int m;
long int sumArr[2000001];

int main() {
    cin >> m;
    for (long int i = 1; i < m; i ++) sumArr[i] = sumArr[i - 1] + i;
    for (long int i = 1; i < m; i ++) {
        // 两个前缀和一减，就是这两个数字之间的和
        long int target = sumArr[i - 1] + m;  // 要找到的目标数字，也就是之前所有数字的和加上 m
        long int right = lower_bound(sumArr, sumArr + m + 1, target) - sumArr;  // 二分查找目标数字
        if (sumArr[right] - sumArr[i - 1] == m) {  // 判断两者的差是否是 m
            cout << i << " " << right << endl;
        }
    }
    return 0;
}
