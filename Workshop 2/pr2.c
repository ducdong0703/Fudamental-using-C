#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int income,
       pa = 9000000, 
       pd = 3600000,n, ti, tf,it;
    printf("Enter your income this year:");
    scanf ("%d", &income);
    printf("Enter number of dependent:");
    scanf("%d", &n);
   /* tf = 12*(pa +n*pd);
    printf("Tax-free income: %d\n",tf);
    ti = income - tf;
        if (ti <= 0) 
            ti =0;
        else
            if(ti<=5000000)
            ti=ti*5/100;
            else
                if(ti<=10000000)
                    it=5000000*5/100+(ti-5000000)*10/100;
                else
                    if(ti<=18000000)
                        it=5000000*5/100+5000000*10/100+(ti-10000000)*15/100;
                    else
                        it=5000000*5/100+5000000*10/100+8000000*15/100+(ti-18000000)*20/100;
                 printf("Taxable income: %d\n", ti);
                 printf("Income tax: %d",it);*/
     return (0);
}

