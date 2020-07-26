#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
void clear(){
    while(getchar() != '\n');
}

int checkInput(){
    int n;
    int rc,keeptrying = 1;
    char after;
    do{
        rc = scanf("%d%c",&n,&after);
        if(rc == 0){
            printf("No input accepted!\n");
            printf("Choose option:\n");
            clear();
        }
        else if(after != '\n'){
            printf("Trailing characters!\n");
            printf("Choose option:\n");
            clear();
        }
        else
            keeptrying = 0;
    }while(keeptrying == 1);
    return n;
}

int isFull(int*a, int n){
    return n == MAXN;
}

int isEmpty (int*a, int n){
    return n == 0;
}
void add(int value, int*a, int*pn){
    a[*pn] = value;
    (*pn)++;
}

int search(int x, int*a, int n){
    int i;
    for (i = 0; i< n; i++){
        if(a[i] == x)
            return i;
    }
    return -1;
}

void print(int*a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d    ", a[i]);
    printf("\n");
}

void valRange(int *a, int n){
    int min, max;
    printf("Enter min value:");
    min = checkInput();
    printf("\nEnter max value:");
    max = checkInput();
    for(int i = min; i<= max; i++)
        printf("%d    ", a[i]);
    printf("\n");
    
}

void printAsc(int *a, int n){
    int**adds = (int**) calloc(n, sizeof(int*));
    int i,j;
    int*t;
    for(i = 0; i < n; i++)
        adds[i]= &a[i];
    for(i = 0; i < n; i++)
        for(j = n-1; j > i; j--)
            if(*adds[j] < *adds[j-1]){
                t = adds[j];
                adds[j] = adds[j-1];
                adds[j-1] = t;
            }
    for(i = 0; i < n;i++)
        printf("%d    ", *adds[i]);
        free(adds);
}
void menu(){
    printf("-----------MENU-----------\n");
    printf("1 - Add value\n");
    printf("2 - Search a value\n");
    printf("3 - Print out the array\n");
    printf("4 - Print out values in a range\n");
    printf("5 - Print out the array in ascending order\n");
    printf("Other - Quit\n");
    printf("Choose option:");
        
}
int main(){
    int a[MAXN];
    int n = 0 ;
    int value;
    int select;
    do{
        menu();
        select = checkInput();
        switch(select){
            case 1:
                if(isFull(a, n))
                    printf("Sorry! The array is full!\n");
                else{
                    printf("Enter added value:");
                    scanf("%d", &value);
                    add(value, a, &n);
                    printf("Added!\n");
                }
                break;
            case 2:
                if(isEmpty(a, n))
                    printf("Sorry! The array is empty!\n");
                else{
                    printf("Enter the searched value:");
                    scanf("%d", &value);
                    int pos = search(value, a, n);
                    if(pos<0)
                        printf("Not found!\n");
                    else
                        printf("Position is found at %d\n", pos);
                }
                break;
            case 3:
                print(a, n);
                break;
            case 4:
                valRange(a, n);
                break;
            case 5:
                printAsc(a, n);
                break;
            default:
                printf("Bye!\n");
                return 0;
        }
    }while (select >= 1||select <= 7);
    return 0;
}