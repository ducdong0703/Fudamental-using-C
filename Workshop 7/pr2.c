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

void add(char code[][8], char name[][20], double sala[], double allo[], int *count){
    char code1[8], temp[20];
    int check = -1;
    double s, a;
    printf("Enter code:");
    fflush(stdin);
    scanf("\n%[^\n]", code1);
    nameStr(code1);
    for(int i = 0; i < *count; i ++)
        if(strcmp(code[i], code1) == 0)
            check = 0;
    if(check == 0){
        printf("This code already in list!\n");
    }
    else{
        strcpy(code[*count], code1);
        printf("Enter name:");
        scanf("\n%[^\n]", temp);
        nameStr(temp);
        for(int i = 0; i < *count; i ++)
        if(strcmp(name[i], temp) == 0)
            check = 0;
        if(check == 0)
            printf("This name already in list!\n");
        else{
            strcpy(name[*count], temp);
            printf("Enter salary:");
            scanf("%lf", &s);
            sala[*count] = s;
            printf("Enter allowance:");
            scanf("%lf", &a);
            allo[*count] = a;
            (*count)++;
            printf("Added!\n");
        }
    }
}

void find(char code[][8], char name[][20], double sala[], double allo[], int *count){
    int pos = 0;
    char temp[8];
    int check = 0;
    printf("Enter name:");
    fflush(stdin);
    scanf("%[^\n]", temp);
    nameStr(temp);
    for(int i = 0; i < *count; i++){
        char* ptr = strstr(name[i], temp);
        if(ptr != '\0'){
            printf("Code: %s\n", code[i]);
            printf("Name: %s\n", name[i]);
            printf("Salary: %lf\n", sala[i]);
            printf("Allowance: %lf\n", allo[i]);
            break;
        }
    }
    if(check == 1){
       getchar();
     }
    else{
        printf("Not found!\n");
        getchar();
    }
}

void remov(char code[][8], char name[][20], double sala[], double allo[], int *count){
    int i, j;
    char del[8];
    int check = 1;
    for(i = 0; i < *count; i++)
        printf("Code: %s|Name: %s|Salary: %lf|Allowance: %lf\n", code[i], name[i], sala[i], allo[i]);
    printf("Enter code you want to remove:");
    fflush(stdin);
    scanf("\n%[^\n]", del);
    nameStr(del);
    for(i = 0; i < *count; i++){
        if(strcmp(code[i], del) == 0){
             strcpy(code[i], code[i+1]);
             strcpy(name[i], name[i+1]);
             sala[i] = sala[i+1];
             allo[i]= allo[i+1];
             (*count)--;
             check = 0;
        }
    }
    if(check == 0){
        printf("Code %s is remove!\n", del);
        getchar();
    }
    else{
        printf("Not found!\n");
        getchar();
    }
}

void ascen(char code[][8], char name[][20], double sala[], double allo[], int *count){
    int i;
    char c[8], n[20];
    double s, a;
    for(i = 0; i < *count; i++){
        if(sala[i-1] + allo[i-1] > sala[i] + allo[i]){
            strcpy(c, code[i-1]);
            strcpy(code[i-1], code[i]);
            strcpy(code[i], c);
            strcpy(n, name[i-1]);
            strcpy(name[i-1], name[i]);
            strcpy(name[i], n);
            s = sala[i-1];
            sala[i-1] = sala[i];
            sala[i] = s;
            a = allo[i-1];
            allo[i-1] = allo[i];
            allo[i] = a;
        }
    }
}

void print(char code[][8], char name[][20], double sala[], double allo[], int *count){
    for(int i = 0; i < *count; i++)
        printf("Code: %s|Name: %s|Salary: %lf|Allowance: %lf\n", code[i], name[i], sala[i], allo[i]);  
}

void menu(){
    printf("---------Employee program---------\n");
    printf("Option 1: Adding a new employee\n");
    printf("Option 2: Find employee\n");
    printf("Option 3: Remove employee\n");
    printf("Option 4: Print the list in descending order base on salary + allowance\n");
    printf("Option 5: Quit\n");
}
int main(int argc, char** argv) {
    int opt, count = 0;
    char name[MAXN][20];
    char code[MAXN][8];
    double sala[MAXN], allo[MAXN];
    do{
        system("clear");
        menu();
        opt = checkInput(1, 5);
        switch(opt){
            case 1:
                add(code, name, sala, allo, &count);
                getchar();
                getchar();
                break;
            case 2:
                if(count <= 0){
                    printf("Nothing to find!\n");
                    getchar();
                }
                else{
                    find(code, name, sala, allo, &count);
                    getchar();
                }
                break;
            case 3:
                if(count <= 0){
                    printf("Nothing to remove");
                    getchar();
                }
                else{
                    remov(code, name, sala, allo, &count);
                    getchar();
                }
                break;
            case 4:
                ascen(code, name, sala, allo, &count);
                print(code, name, sala, allo, &count);
                getchar();
                break;
            case 5:
                printf("Have a nice day!\n");
                return 0;
        }
    }while(opt != 5);
    return (EXIT_SUCCESS);
}

