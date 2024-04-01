#include <stdio.h>
#define MAX_DEGREE 101

/* 4x ^ 3 + 3x ^ 2 + 2x + 1
 3x^2 + 2x +  8*/

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

void print_polynomial(polynomial p) {

	for (int i = p.degree; i > 0; i = i - 1) { // i = i - 1 => i --
		printf(" %3.1fx^%d  + ", p.coef[p.degree - i], i);//3.1f 소수점 자리는 하나만 사용.
	}
	printf("%3.1f\n", p.coef[p.degree]);
}

polynomial poly_mult(polynomial a, polynomial b) {

	polynomial c;

	int coef_a = a.coef, coef_b = b.coef, coef_c = c.coef;
	int degree_a = a.degree, degree_b = b.degree, degree_c = c.degree;

	c.degree = a.degree + b.degree;

	for (int i = 0; i < a.degree; i++) {
		for (int j = 0; j < b.degree; i++) {
			c.coef[i + j] += a.coef[i] * b.coef[j];
		}
	}
	return c;
}



void print_polynomial(polynomial p);
polynomial poly_mult(polynomial a, polynomial b);



int main(void) {
	polynomial a = { 3, {4.0, 3.0, 2.0, 1.0} };
	polynomial b = { 2, {3.0, 2.0, 8.0} };

	polynomial c;

	print_poly(a);
	print_poly(b);

	c = poly_mult(a, b); //다항식 곱셈 수행
	printf("---------------------------------------------------------------\n");
	print_poly(c);

	return 0;
}