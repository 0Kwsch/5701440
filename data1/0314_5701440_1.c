#include<stdio.h>
#include<stdbool.h>
#include<time.h>


int main(void) {

	double diff; //stop - start을 저장할 변수

	clock_t start, stop; //start, stop 선언
	start = clock(); // 수행 시작

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

	stop = clock(); //수행 멈춤
	diff = (double)(stop - start) / CLOCKS_PER_SEC; // stop - start를 초 단위로 나누어 diff에 저장
	printf("수행 시간은 %lf초입니다. \n", diff);
	return 0;

}