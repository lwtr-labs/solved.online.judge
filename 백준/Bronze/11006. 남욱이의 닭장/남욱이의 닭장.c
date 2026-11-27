#include <stdio.h>

int main(void) {
    int t, n, m, r;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        r = 2 * m - n;
        m = m - r;
        printf("%d %d\n", r, m);
    }

    return 0;
}