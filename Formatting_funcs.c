#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isEven(const int);
int isPrime(const int);

int main(int argc, char *argv[]){
    FILE *fptr = NULL;
    int num = 0, success = 0;

    if((fptr = fopen("numbers.txt", "r+")) == NULL){
        fprintf(stderr, "Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Successfully opened the file. Reading integers from file.\n\n");

    success = fscanf(fptr, "%d", &num);
    
    do{
        if(isPrime(num))
            printf("Prime number found: %d\n", num);
        else if(isEven(num))
            printf("Even number found: %d\n", num);
        else
            printf("Odd number found: %d\n", num);
        
        success = fscanf(fptr, "%d", &num);
    }while(success != -1);

    fclose(fptr);
    return 0;
}

int isEven(const int num){
    return !(num & 1);
}

int isPrime(const int num){
    if(num < 0)
        return 0;

    for(int i = 2; i <= num/2; i++){
        if(num % i == 0)
            return 0;
    }

    return 1;
}