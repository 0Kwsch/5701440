#include <stdio.h>
#include <time.h>

long long power_iter(int a,int b) {
	long long result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

long long power_rec(int a, int b) {
	if (b == 0) return 1;
	else if ((b % 2) == 0)
		return power_rec(a * a, b / 2);
	else return a * power_rec(a * a, (b - 1) / 2);
}

int main(void) {

	clock_t start, stop;
	double diff;
	start = clock(); // 측정시작


	long long result_iter = power_iter(13, 21);
	printf("13^21 = %lld\n", power_iter);
	double result_rec = power_rec(13, 21);
	printf("13^21 = %lld\n", power_rec);

	stop = clock(); // 측정종료
	diff = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간 : %lf", diff);
	return 0;

}
