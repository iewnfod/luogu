//
// Created by 慕芸熙 on 2023/7/24.
//

#include <bits/stdc++.h>

using namespace std;

char s[8];
int n1, n2, n3;

int main() {
    for (int i = 0; i < 8; i++) {
        scanf("%c", &s[i]);
    }

    for (int i = 0; i < 8; i++) {
        char _s = s[i];

        if ('0' <= _s && _s <= '9') n1 ++;
        else if ('a' <= _s && _s <= 'z') n2 ++;
        else if ('A' <= _s && _s <= 'Z') n3 ++;
    }

    printf("%d %d %d", n1, n2, n3);
}
