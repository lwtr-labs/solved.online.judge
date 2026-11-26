#include <stdio.h>

long long fib(long long *list, int n) {
    if (n == 0) 
        return list[0];
    else if (n == 1)
        return list[1];
    else {
        if (list[n] == 0) {
            list[n] = fib(list, n -2) + fib(list, n - 1);
            return list[n];
        }
        else
            return list[n];
    }
}

int main(void) {
    long long fib_num[46] = { 0, 1 };
    int n;
    scanf("%d", &n);

    printf("%lld", fib(fib_num, n));

    return 0;
}


