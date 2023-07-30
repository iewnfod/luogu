//
// Created by 慕芸熙 on 2023/7/23.
//

#include <bits/stdc++.h>

using namespace std;

int n;
string start;
string s[25];
int use[25];
int res = 0;

// 尝试接龙两个字符串，如果成功，返回连接的字符串，后者返回 0
int connect(const string& s1, const string& s2) {
    int s1_len = s1.size();
    int s2_len = s2.size();
    int len = max(0, min(s1_len - 1,  s2_len - 1));

    if (len) {
        int index = 0;
        // 找到可以拼接的位置
        for (int i = 1; i <= len; i++) {
            string _s1 = s1.substr(s1_len-(len-i+1));
            string _s2 = s2.substr(0, len-i+1);
            if (_s1 == _s2) {
                index = i;
            }
        }
        if (!index) return 0;
        // 拿到重复的，将s1去掉重复部分加上s2
        return len-index+1;
    }

    return 0;
}

void dfs(const string& str, int length) {
    res = max(res, length);

    for (int i = 1; i <= n; i++) {
        if (use[i] >= 2) continue;
        int c = connect(str, s[i]);
        if (c) {
            use[i] ++;
            dfs(s[i], length+s[i].size()-c);
            use[i] --;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    cin >> start;

    // start 前加一个空格，否则只有一位长的 start 无法被连接
    dfs(" " + start, 1);

    printf("%d", res);
}
