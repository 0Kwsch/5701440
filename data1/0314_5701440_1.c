#include<stdio.h>
#include<stdbool.h>
#include<time.h>


int main(void) {

	double diff; //stop - start�� ������ ����

	clock_t start, stop; //start, stop ����
	start = clock(); // ���� ����

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
	printf("�Ҽ��� �� :%d \n", sum);

	stop = clock(); //���� ����
	diff = (double)(stop - start) / CLOCKS_PER_SEC; // stop - start�� �� ������ ������ diff�� ����
	printf("���� �ð��� %lf���Դϴ�. \n", diff);
	return 0;

}