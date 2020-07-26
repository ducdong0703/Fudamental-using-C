#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int n) {
	//==Begin your codes here=====================
	int count = 0;
	int check = 1;
	for(int i = 1; i<=n; i++){
		if(n%i == 0)
			count++;
	}
	if(count == 2)
		check = 1;
	else
		check = 0;
	return check;

	//==End your codes============================
}

int main(int argc, char *argv[]) {
	system("cls");
	printf("\nTEST Q1 (2 marks):\n");
	int n = 17;
	do {
		printf("Enter n = ");
		scanf("%d", &n);
	} while (n < 2);
	printf("\nOUTPUT:\n");
	if (prime(n) == 1)
		printf("%d is prime.\n", n);
	else
		printf("%d isn't prime.\n", n);
	system ("pause");
	return 0;
}
