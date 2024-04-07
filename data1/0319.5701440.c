#include<stdio.h>
#include<time.h>

/*long long factorial_iter(int a) {
	long long result = 1;
	for (int i = 1; i <= a; i++) {
		result *= i; //result = result * i

	}
	return result;
}
long long factorial_rec(int a) {
	if (a <= 1) return (1);
	else return (a * factorial_rec (a - 1));

}
int main(void) { 
	clock_t start, stop;
	double diff;

	start = clock(); // 측정시작

	long long result_iter = factorial_iter(20);
	printf("factorial_iter 20! = %lld\n", result_iter);
	
	long long result_rec = factorial_rec(20);
	printf("factorial_iter 20! = %lld\n", result_rec);

	stop = clock();
	diff = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간 : %lf", diff);
	return 0;
}*/
int main(void) {
	for (int i = 1; i <= 5; i++) {
		printf(" aoi ");
	}
	return 0;
}