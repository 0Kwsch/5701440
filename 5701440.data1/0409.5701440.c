#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1; //인덱스 0에서 pop할 경우 top은  -1

//create : 이미 만들었음..
//delete : 할 수 없음.

// is_full
int is_full() {
	if (top == MAX_STACK_SIZE - 1) return 1; // stack full
	//else return 0;
	
	}

int is_empty() {
	//if (top == -1) return 1;
	//else return 0;
	return(top == -1);
}

//push
void push(element item) {
	if (is_full()) {// stack full
		//fprintf(stderr, "Stack Is Full\n");
		return;
	}
	else {
		top = top + 1;
		stack[top] = item;
	}
}

element pop() {
	element r;
	if (is_empty()) {
		fprintf(stderr, "stack is empty\n ");
		return -1;
	}
	else {
		/*r = stack[top];
		top = top - 1;
		return r;/*/
		return (stack[top--]);
	}
}

element peek() {


	element r;
	if (is_empty()) {
		fprintf(stderr, "stack is empty\n ");
		exit(1);
	}
	else {
		/*r = stack[top];
		top = top - 1;
		return r;/*/
		return (stack[top--]);
	}
}

int main() {

	srand(time(NULL));
	int rands_num = 0;
	int data;

	for (int i = 1; i <= 30; i++) {
		rands_num = rand() % 100 + 1;
		printf("current rand_num: %d \n", rands_num);
		if (rands_num % 2 == 0) { 
			push(rands_num);
			printf("Push %d \n", rands_num);
		}
		else {
			rands_num = pop();
			printf("Pop %d \n", rands_num);
		}
		printf("stack element: \n", rands_num);
	}
	return 0;
}
