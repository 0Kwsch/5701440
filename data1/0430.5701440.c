#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

/*typedef struct { 학생을 넣을 때
int age;
char name[20];
}element */

// 객체 구현
typedef int element; // element 정수, 실수라면 float element , 문자라면 char element

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) { // 포인터 q를 받아서 출력해줌
	fprintf(stderr, "%s", message);
	return -1;
}

int is_full(QueueType* q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE)); // 원형 q의 개념
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0; // -1로 해도 됨.
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("Queue is full \n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //q라고 하는 것은 포인터. % MAX_QUEUE_SIZE 하면 선형에서 원형으로 바뀜. 
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("Queue is empty\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return(q->data[q->front]);
	}
}

void print_queue(QueueType* q) {
	int i;
	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
		printf("[%2d] %2d, ", i, q->data[i]);
	}
	printf("[%2d] %2d \n", i, q->data[i]);
}

int main(void) {

	QueueType queue; //create 
	element e;
	init_queue(&queue); // queue의 위치를 넘겨 줌.

	int choice;
	int num = 0;
	while (1) {
		printf("1. 큐에 원소를 삽입\n");
		printf("2. 큐에서 원소를 삭제\n");
		printf("3. 큐의 원소를 출력\n");
		printf("4. 종료\n");
		printf("메뉴를 선택하세요: \n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("큐에 삽입할 숫자를 입력하세요: \n");
			scanf_s("%d", &num);
			if (is_empty) {
				enqueue(&queue, num); print_queue(&queue);
			}
			else {
				printf("큐가 포화상태입니다.\n");
			}
			break;
		case 2:
			if (is_empty) {
				printf("큐가 비어있습니다.\n");
			}
			else {
				e = dequeue(&queue); printf("<%2d> ", e); print_queue(&queue);
			}
			break;
		case 3:
			printf("현재 큐의 상태: ");
			print_queue(&queue);

			break;
		case 4:
			exit(0);
		default:
			printf("잘못된 선택입니다. \n");
		}

	}


	/*enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	enqueue(&queue, 4); print_queue(&queue);
	enqueue(&queue, 5); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d> ", e); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d> ", e); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d> ", e); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d> ", e); print_queue(&queue);*/

}
