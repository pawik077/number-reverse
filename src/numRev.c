#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int num, rev = 0, trailing_zeros_number = 0, leading_zeros = 1;
	char number[15];
	if (argc != 2) {
		printf("Enter a number: ");
		scanf("%s", number);
	} else strcpy(number, argv[1]);
	num = atoi(number);
	while (num <= 0) {
		if (num < 0) fprintf(stderr, "Only positive numbers are supported\n");
		else fprintf(stderr, "Incorrect input\n");
		printf("Enter a number: ");
		scanf("%s", number);
		num = atoi(number);
	}
	for (int i = 0; number[i] == '0'; i++) 
		leading_zeros *= 10;
	while (num % 10 == 0) {
		num /= 10;
		++trailing_zeros_number;
	}
	char* trailing_zeros = malloc(trailing_zeros_number * sizeof(char));
	for (int i = 0; i < trailing_zeros_number; i++) {
		trailing_zeros[i] = '0';
	}
	while (num != 0) {
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	rev *= leading_zeros;
	printf("Reverse of the number is: %s%d\n", trailing_zeros, rev);
	free(trailing_zeros);
}