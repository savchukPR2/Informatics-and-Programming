#include <stdio.h>
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif

bool prime(int num, int del)
{
    if (del > num / 2)
        return true;
    return num % del ? prime(num, ++del) : false;
}

int main()
{
    int num;

    printf("enter your number: ");
    scanf_s("%i", &num);

    if (prime(num, 2))
        printf("your number is prime\n");
    else
        printf("you number is'nt prime\n");
    return 0;
}