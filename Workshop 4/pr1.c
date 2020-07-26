#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int n)
{
    int m = sqrt(n);
    int i;
    for (i=2;i<=m;i++)
        if (n%i==0)
            return 0;
    return 1;
}
void minMaxDigits(int n)
{
    int digit, min, max;
    digit=n%10;
    n=n/10;
    min=max=digit;
    while(n>0)
    {
        digit=n%10;
        n=n/10;
        if(min>digit)
            min=digit;
        if(max<digit)
            max=digit;
    }
    printf("Min is:%d\n",min);
    printf("Max is:%d\n",max);
}
int main(int argc, char** argv) 
{
    int choice;
    do
    {
        printf("=======Menu=======\n");
        printf("Option 1:Process primes\n");
        printf("Option 2:Min, max digit\n");
        printf("Option 3:Quit\n");
        printf("Choose an option: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int n;
                printf("Enter number:");
                do
                {
                    scanf("%d",&n);
                }while (n<0);
                if(prime(n))
                    printf("%d is a prime\n",n);
                else
                    printf("%d is not a prime\n",n);
                break;
            }
            case 2:
            {
                int digit;
                do
                {
                    printf("Enter digit:");
                    scanf("%d",&digit);
                } while(digit<0);
                minMaxDigits(digit);
                break;
            }
            case 3:
                printf("Bye!\n");
                return 0;
        }
    } while(choice!=3);
}

