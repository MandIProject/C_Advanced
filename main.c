#include <stdio.h>

union mixed{
    int i_value;
    float f_value;
    char c_value;
};

int main(void){
    union mixed x;
    x.c_value = 'j';
    printf("Memory size occupied by data: %zu\n", sizeof(x));
    printf("\n%c\n", x.c_value);    

    return 0;
}