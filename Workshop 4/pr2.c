#include <stdio.h>
#include <stdlib.h>
void fibo(int n)
{
    int t1=0,t2=1,f=1;
    if(n==1)
        printf("1");
    while(f<n)
    {
        printf("%d ",f);
        f=t1+t2;
        t1=t2;
        t2=f;
    }
    printf("\n");
}
int validDate(int d, int m, int y)
{
    int maxd=31;
    if(d<1||d>31||m<1||m>12)
        return 0;
    if(m==4||m==6||m==9||m==11)
        maxd=30;
    else
        if(m==2)
        {
            if(y%400==0||y%4==0&&y%100!=0)
                maxd=29;
            else
                maxd=28;        
        }
    return d<=maxd;
}
int main(int argc, char** argv) 
{
    int option;
    do
    {
        printf("=======Menu=======\n");
        printf("Option 1: Fibonacci sequence\n");
        printf("Option 2: Check a date\n");
        printf("Option 3: Quit\n");
        printf("Select an option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                int n;
                do
                {
                    printf("Enter a number:");
                    scanf("%d",&n);
                } while (n < 0);
                    fibo(n);
                    break;
            }
            case 2:
            {
                int d,m,y;
                printf("Enter day:");
                scanf("%d",&d);
                printf("Enter month:");
                scanf("%d",&m);
                printf("Enter year:");
                scanf("%d",&y);
                if (validDate(d,m,y))
                    printf("Valid date\n");
                else
                    printf("Invalid date\n");
                break;
            }
            case 3:
            {   
                printf("Bye!");
                return 0;
            }
        }
    } while(option!=3);
}
