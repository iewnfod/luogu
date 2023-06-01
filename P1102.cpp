#include "bits/stdc++.h"

using namespace std;

int n, c;
int num[200001];
long int result, rightValue, target;
map<int, int> num_number;

int main() {
    cin >> n >> c;
    // 输入
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        // 记录每个数字的个数
        if (num_number[num[i]]) num_number[num[i]] ++;
        else num_number[num[i]] = 1;
    }
    // 排序
    sort(num, num + n, less<>());
    // 遍历
    for (int i = 0; i < n; i++) {
        target = num[i] + c;
        rightValue = lower_bound(num, num + n, target) - num;
        if (num[rightValue] - num[i] == c) {
            // cout << num[i] << "(" << i << ")" << " " << target << "(" << rightValue << ")" << " " << num_number[num[rightValue]] << endl;
            result += num_number[num[rightValue]];
        }
    }
    cout << result << endl;
    return 0;
}
