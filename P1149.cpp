//
// Created by 慕芸熙 on 2023/6/15.
//

#include <bits/stdc++.h>

using namespace std;

const int NUMBERS[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int USED = 4;

int n, ans;

int getMatchNumber(int x) {
    if (x < 10) return NUMBERS[x];

    int sum = 0;
    while (x) {
        sum += NUMBERS[x % 10];
        x /= 10;
    }
    return sum;
}

int main() {
    scanf("%d", &n);
    n -= USED;

    for (int a = 0; a <= 999; a++) {
        int match_a = getMatchNumber(a);
        for (int b = a; b <= 999; b++) {
            int match_b = getMatchNumber(b);

            int c = a + b;
            int match_c = getMatchNumber(c);

            if ( match_a + match_b + match_c == n ) {
                // printf("%d(%d) + %d(%d) = %d(%d)\n", a, match_a, b, match_b, c, match_c);
                if (a == b) ans ++;
                else ans += 2;
            }
        }
    }

    printf("%d", ans);
}
