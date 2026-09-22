#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int slice, int n) {
    
    int div = n / slice;
    
    if (div*slice < n)
    {
        div += 1;
    }
    
    int answer = div;
    return answer;
}