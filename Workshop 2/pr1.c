#include <stdio.h>
#include <stdlib.h>
int main() {
    double num1, num2;
    char op;
    double result;
    printf("Enter a cal: ");
    scanf("%lf",&num1);
    scanf("%c",&op);
    scanf("%lf",&num2);
    switch(op)
        {case'+': result= num1 + num2;
            printf("result is:%lf",result);
            break;
        case'-': result=num1-num2;
            printf("result is:%lf",result);
            break;
        case'*': result = num1*num2;
            printf("result is:%lf",result);
            break;
        case'/': if (num2==0)
            printf(" Divide by 0");
        else{ result= num1/num2;
            printf("result is:%lf",result);
            break;
            default:
        printf("Op is not supported ");}
    }
    return (0);
}

