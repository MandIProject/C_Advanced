#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int add(int count, ...);

int main(void){
    printf("Addition result = %d\n", add(4, 10, 20, 30, 40));

    return 0;
}

int add(int count, ...){
    int sum = 0;
    va_list parg;

    va_start(parg, count);
    for(int i = 0; i < count; i++){
        int num = va_arg(parg, int);
        sum += num;
    }

    va_end(parg);
    return sum;
}