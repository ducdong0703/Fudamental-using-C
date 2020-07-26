#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void clear(){
    while(getchar()!='\n');
}
int isValid(double value,char after){
    int rc;
    rc=("%lf%c",value,after);
        if(rc==0||after!='\n'){
            printf("Invalid input!\n");
            clear();
        }
    return value;
}
void quaEquation(double a,double b, double c){
    double dis,x1,x2;
    dis=b*b-4*a*c;
    if(dis<0)
        printf("No solution\n");
    else if(dis>0){
        x1=(-b+sqrt(dis))/(2*a);
        x2=(-b-sqrt(dis))/(2*a);
        printf("X1 is:%lf\n",x1);
        printf("X2 is:%lf\n",x2);
    }
    else{
        x1=-b/(2*a);
        printf("X is:%lf\n",x1);
    }
}
void bankDes(double des, double rate, int year){
    double amount;
    amount=des*pow(1+rate,year);
    printf("Amount at the %d year:%lf\n",year,amount);
}
int main(int argc, char** argv) {
    int selection;
    char s;
    do{
        printf("=======MENU=======\n");
        printf("Selection 1:Quadratic equation\n");
        printf("Selection 2:Bank deposit problem\n");
        printf("Selection 3:Quit\n");
        do{
            printf("Enter Selection:");
            scanf("%d%c",&selection,&s);
            isValid(selection,s);
        }while(s!='\n');
        switch(selection){
             case 1:{
                 double a,b,c;
                 char a1,a2,a3;
                 do{
                    printf("Enter ax^2:");
                    scanf("%lf%c",&a,&a1);
                    isValid(a,a1);
                 }while(a1!='\n');
                 do{
                    printf("Enter bx:");
                    scanf("%lf%c",&b,&a2);
                    isValid(b,a2);
                 }while(a2!='\n');
                 do{
                    printf("Enter c:");
                    scanf("%lf%c",&c,&a3);
                    isValid(c,a3);
                 }while(a3!='\n');
                 quaEquation(a,b,c);
                 break;
                }
            case 2:{
                double des,rate;
                int year;
                char c1,c2,c3;
                do{
                    printf("Enter deposit:");
                    scanf("%lf%c",&des,&c1);
                    if(des<0)
                        printf("Deposit must be positive!\n");
                    else
                        isValid(des,c1);
                }while(c1!='\n'||des<0);
                do{
                    printf("Enter yearly rate:");
                    scanf("%lf%c",&rate,&c2);
                    if(rate<0||rate>0.1)
                        printf("Rate must be about 0 to 0.1!\n");
                    else
                        isValid(rate,c2);
                }while(c2!='\n'||rate<0||rate>0.1);
                do{
                    printf("Enter number of year:");
                    scanf("%d%c",&year,&c3);
                    if(year<0)
                        printf("Year must be positive!\n");
                    else
                    isValid(year,c3);
                }while(c3!='\n'||year<0);
                bankDes(des,rate,year);
                break;
            }
            case 3:
                printf("Bye!");
                break;
            default:
                printf("No Selection!\n");
                break;
        }                
    }while(selection!=3);
    return (EXIT_SUCCESS);
}

