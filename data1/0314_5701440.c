#include<stdio.h>
#include<stdbool.h>

int main(void) {
	int sum = 0;
	bool isPrime[101];

	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= 100; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= 10; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 100; j += i) { 
				isPrime[j] = false;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		if (isPrime[i]) {
			sum += i;
		}
	}
	printf("소수의 합 :%d \n", sum);
	return 0;
}