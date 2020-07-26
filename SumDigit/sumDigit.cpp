#include <stdio.h>
#include <stdlib.h>

int sumDigits(int n) {
	//==Begin your codes====================
	int sum = 0;
	do{
		sum += n%10;
		n /= 10; 
	}while(n > 0);	
	return sum;




	//==End your codes======================
}

int main(int argc, char** argv) {
    int n;
    do {
        printf("Enter the number (0 exit): ");
        scanf("%d", &n);
        if (n >= 0) {
            printf("%d \n", sumDigits(n));
        }
    } while (n != 0);

    return (EXIT_SUCCESS);
}

