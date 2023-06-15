//
// Created by 慕芸熙 on 2023/6/14.
//

#include <bits/stdc++.h>

using namespace std;

int n;
int spices[11];
int ans = 0;
string result;

int dfs(int x) {
    if (x > 10) {
        int sum = 0;
        string value;
        for (int i = 1; i <= 10; i++) {
            sum += spices[i];
            value += to_string(spices[i]);
            if (i != 10) value += ' ';
        }
        if (sum == n) {
            ans ++;
            result += value + '\n';
        }
    } else {
        for (int i = 1; i <= 3; i++) {
            spices[x] = i;
            dfs(x+1);
            spices[x] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", ans);
    printf("%s", result.c_str());
}
