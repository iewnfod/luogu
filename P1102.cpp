#include "bits/stdc++.h"

using namespace std;

int n, c;
int num[200001];
long long result;
int target;
map<int, int> num_number;

int main() {
    scanf("%d %d", &n, &c);
    // 输入
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        // 记录每个数字的个数
        num_number[num[i]] ++;
    }
    // 遍历
    for (int i = 0; i < n; i++) {
        target = num[i] + c;
        if (num_number[target])
            result += num_number[target];
    }

    printf("%lld", result);
    return 0;
}
