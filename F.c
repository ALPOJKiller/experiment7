#include <stdio.h>
int main() {
    int n, a, b, c, d, e, f, x, y;
    int table[4] = {0, 5, 3, 1};
    while (1) {
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
            break;
        n = d + e + f + (c + 3) / 4;
        y = 5 * d + table[c % 4];
        if (b > y)
            n += (b - y + 8) / 9;
        x = 6 * 6 * n - 6 * 6 * f - 5 * 5 * e - 4 * 4 * d - 3 * 3 * c - 2 * 2 * b;
        if (a > x)
            n += (a - x + 35) / (6 * 6);
        printf("%d\n", n);
    }
    return 0;
}

