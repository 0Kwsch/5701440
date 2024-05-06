#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

/*typedef struct { �л��� ���� ��
int age;
char name[20];
}element */

// ��ü ����
typedef int element; // element ����, �Ǽ���� float element , ���ڶ�� char element

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) { // ������ q�� �޾Ƽ� �������
	fprintf(stderr, "%s", message);
	return -1;
}

int is_full(QueueType* q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE)); // ���� q�� ����
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0; // -1�� �ص� ��.
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("Queue is full \n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //q��� �ϴ� ���� ������. % MAX_QUEUE_SIZE �ϸ� �������� �������� �ٲ�. 
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
	init_queue(&queue); // queue�� ��ġ�� �Ѱ� ��.

	int choice;
	int num = 0;
	while (1) {
		printf("1. ť�� ���Ҹ� ����\n");
		printf("2. ť���� ���Ҹ� ����\n");
		printf("3. ť�� ���Ҹ� ���\n");
		printf("4. ����\n");
		printf("�޴��� �����ϼ���: \n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("ť�� ������ ���ڸ� �Է��ϼ���: \n");
			scanf_s("%d", &num);
			if (is_empty) {
				enqueue(&queue, num); print_queue(&queue);
			}
			else {
				printf("ť�� ��ȭ�����Դϴ�.\n");
			}
			break;
		case 2:
			if (is_empty) {
				printf("ť�� ����ֽ��ϴ�.\n");
			}
			else {
				e = dequeue(&queue); printf("<%2d> ", e); print_queue(&queue);
			}
			break;
		case 3:
			printf("���� ť�� ����: ");
			print_queue(&queue);

			break;
		case 4:
			exit(0);
		default:
			printf("�߸��� �����Դϴ�. \n");
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
