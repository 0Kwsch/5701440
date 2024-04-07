#include <stdio.h>
#define MAX_TERMS 101

struct term
{
	float coef;
	int expon;

}terms[MAX_TERMS] = {
	{7.0, 6}, {5.0, 3}, {9.0, 2}, {1.0, 0},
	{5.0, 3}, {2.0, 2}, {1.0, 1}, {10.0, 0}
};

int avail = 7;

int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;

void polymult(int as, int ae, int bs, int be, int* cs, int* ce) {
	*cs = avail;


	for (; as <= ae; as++) {
		for (; bs <= be; bs++) {
			terms[*cs].coef = terms[as].coef * terms[bs].coef;
			terms[*cs].expon = terms[as].expon + terms[bs].expon;
			(*cs)++;
		}
	}
	*cs = avail;
	*ce = *cs - 111;

}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d +", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d  \n", terms[e].coef, terms[e].expon);
}

int main(void) {
	polymult(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;

}