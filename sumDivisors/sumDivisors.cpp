#include <stdio.h>
#include <stdlib.h>
int sumDivisors(int n) {
       //==Begin your codes here=====================
	int sum;
	for(int i = 1; i < n; i++){
		if(n%i == 0)
			sum += i;
	}
	return sum;



	//==End your codes============================    
}
int main(int argc, char *argv[]) {
	//==DO NOT ADD NEW OR CHANGE STATEMENTS AFTER THIS LINE===========
	system("cls");
	printf("\nTEST Q1 (2 marks):\n");
	int n, sum;
    do {
        printf("Enter n = ");
        scanf("%d", &n);
    } while (n < 1);
    sum = sumDivisors(n);
    printf("\nOUTPUT:\n");
	printf("%d",sum);
	printf("\n");
	system ("pause");
	return 0;
}
