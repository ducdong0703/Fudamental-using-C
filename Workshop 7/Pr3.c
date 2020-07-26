#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 100
void clear(){
    while(getchar() != '\n');
}

int checkInput(int min, int max){
    int opt, keeptrying = 1, rc;
    char after;
    do{
        rc = scanf("%d%c", &opt, &after);
        if(rc == 0){
            printf("No input accepted!\n");
            clear();
        }
        else if(after != '\n'){
            printf("Trailing characters!\n");
            clear();
        }
        else if(opt < min || opt > max){
            printf("No option!\n");
        }
        else
            keeptrying = 0;
    }while(keeptrying == 1);
    return opt;
}

char* lTrim(char name[]){
    int i = 0;
    while(name[i] == '  ')
        i++;
    if(i>0)
        strcpy(&name[0], &name[i]);
    return name;
}

char* rTrim(char name[]){
    int i = strlen(name) - 1;
    while(name[i] == '  ')
        i--;
    name[i+1] = '\0';
    return name;
}

char* trim(char name[]){
    rTrim(lTrim(name));
    char* ptr = strstr(name, "  ");
    while(ptr != NULL){
        strcpy(ptr, ptr + 1);
        ptr = strstr(name, "  ");
    }
    return name;
}

char* nameStr(char name[]){
    trim(name);
    strlwr(name);
    int L = strlen(name);
    int i;
    for(i=0; i < L; i++)
            name[i] = toupper(name[i]);
    return name;
}

void add(char name[][20], char make[][20], int volume[], int price[], int duration[], int *count){
    char n[20], m[20];
    int v, p, d;
    int check = 1;
    printf("Enter name of soft drink:");
    fflush(stdin);
    scanf("\n%[^\n]", n);
    nameStr(n);
    for(int i = 0; i < *count; i++)
        if(strcmp(name[i], n) == 0)
            check = 0;
    if(check == 0)
        printf("This soft drink already in list!");
    else{
        strcpy(name[*count], n);
        printf("Enter make of soft drink:");
        scanf("\n%[^\n]", m);
        nameStr(m);
        strcpy(make[*count], m);
        printf("Enter volume of soft drink:");
        scanf("%d", &v);
        volume[*count] = v;
        printf("Enter price:");
        scanf("%d", &p);
        price[*count] = p;
        printf("Enter number of days when this soft drink can be drunk:");
        scanf("%d", &d);
        duration[*count] = d;
        (*count)++;
        printf("Added!\n");
    }
}

void printM(char name[][20], char make[][20], int volume[], int price[], int duration[], int *count){
    char temp[20];
    int check = 0;
    printf("Enter make:");
    fflush(stdin);
    scanf("\n%[^\n]", temp);
    nameStr(temp);
    for(int i = 0; i < *count; i++)
        if(strcmp(make[i], temp) == 0){
            printf("Name: %s|Make: %s|Volume: %d|Price: %d|Duration: %d days\n", name[i], make[i], volume[i], price[i], duration[i]);
            check = 1;
        }
    if(check == 0)
        printf("Not found!\n");
}

void volumes(char name[][20], char make[][20], int volume[], int price[], int duration[], int *count){
    int v1, v2;
    int check = 0;
    printf("Enter volume 1:");
    scanf("%d", &v1);
    printf("Enter volume 2:");
    scanf("%d", &v2);
    if(v1 > v2){
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }
    for(int i = 0 ; i < *count; i++)
        if(v1 <= volume[i] && volume[i] <= v2){
            printf("Name: %s|Make: %s|Volume: %d|Price: %d|Duration: %d days\n", name[i], make[i], volume[i], price[i], duration[i]);
            check = 1;
        }
    if(check == 0)
        printf("No soft drink between %d and %d !\n", v1, v2);
}
    

void ascen(char name[][20], char make[][20], int volume[], int price[], int duration[], int *count){
    int i, v, p, d;
    char n[20], m[20];
    for(i = 0; i < *count; i++){
        if(volume[i-1] > volume[i]){
            strcpy(n, name[i-1]);
            strcpy(name[i-1], name[i]);
            strcpy(name[i], n);
            strcpy(m, make[i-1]);
            strcpy(make[i-1], make[i]);
            strcpy(make[i], m);
            v = volume[i-1];
            volume[i-1] = volume[i];
            volume[i] = i;
            p = price[i-1];
            price[i-1] = price[i];
            price[i] = p;
        }   
    }
    for(i = 0; i < *count; i++){
        if(volume[i-1] == volume[i] && price[i-1] > price[i]){
            strcpy(n, name[i-1]);
            strcpy(name[i-1], name[i]);
            strcpy(name[i], n);
            strcpy(m, make[i-1]);
            strcpy(make[i-1], make[i]);
            strcpy(make[i], m);
            v = volume[i-1];
            volume[i-1] = volume[i];
            volume[i] = i;
            p = price[i-1];
            price[i-1] = price[i];
            price[i] = p;
        }
    }
}

void print(char name[][20], char make[][20], int volume[], int price[], int duration[], int *count){
    for(int i = 0; i < *count; i++)
        printf("Name:%20s|Make: %s|Volume: %d|Price: %d|Duration: %d days\n", name[i], make[i], volume[i], price[i], duration[i]);     
}

void menu(){
    printf("---------Soft drink---------\n");
    printf("Option 1: Add a new soft drink\n");
    printf("Option 2: Print out soft drink belong to a known make\n");
    printf("Option 3: Print out soft drink between 2 volumes\n");
    printf("Option 4: Print out soft drink in ascending order based on volumes then prices\n");
    printf("Option 5: Quit\n");
    printf("Choose option:");
}

int main(int argc, char** argv) {
    int opt = 0;
    int count = 0;
    char name[MAXN][20], make[MAXN][20];
    int volume[MAXN], price[MAXN], duration[MAXN];
    do{
        system("clear");
        menu();
        opt = checkInput(1, 5);
        switch(opt){
            case 1:
                add(name, make, volume, price, duration, &count);
                getchar();
                getchar();
                break;
            case 2:
                printM(name, make, volume, price, duration, &count);
                getchar();
                getchar();
                break;
            case 3:
                volumes(name, make, volume, price, duration, &count);
                print(name, make, volume, price, duration, &count);
                getchar();
                break;
            case 4:
                ascen(name, make, volume, price, duration, &count);
                print(name, make, volume, price, duration, &count);
                getchar();
                break;
            case 5:
                printf("Have a nice day!\n");
                return 0;
        }
    }while(opt != 5);
    return (EXIT_SUCCESS);
}

