#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
double solution(int numbers[], size_t numbers_len) {
    int sum = 0;
    int i;
    
    for (i = 0; i < numbers_len; i++)
    {
        sum += numbers[i];
    } 
    
    double lf_sum = (double)sum;
    
    double answer = lf_sum/numbers_len;
    return answer;
}