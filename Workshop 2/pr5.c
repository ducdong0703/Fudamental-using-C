#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char** argv) {
    char ch;
    int nVowels =0;
    int nConsonants = 0;
    int nOthers = 0;
    printf("Enter a string:");
    scanf("%c",&ch);
    do
    {
        ch=getchar();
        ch=toupper(ch);
        if(ch>='A' && ch<='Z')
        {
            switch(ch)
            {
                case'A':
                case'E':
                case'I':
                case'O':
                case'U': nVowels++;break;
                default: nConsonants++;
            }
        }
        else  nOthers++;
    } while (ch!='\n');
    printf("Vowels:%d\n",nVowels);
    printf("Consonants:%d\n",nConsonants);
    printf("Others: %d",nOthers);
    
    return (0);
}

