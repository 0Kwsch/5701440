#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = h;
	h = p;
	return h;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	if (pre == (ListNode*)NULL) {
		fprintf(stderr, "Insert parameter error in pre == NULL");
		return;
	}
	p->data = value;
	p->link = pre->link;    //<1>
	pre->link = p; // <2>
	return head;
}


ListNode* delete_first(ListNode* head, ListNode* h) {

	if (h == NULL) return NULL;
	ListNode* remove = head;

	head = remove->link;
	free(remove);
	return head;
}

ListNode* delete(ListNode* h, ListNode* pre) {
	ListNode* remove = pre->link;

	pre->link = remove->link;
	free(remove);

	return h;
}

void print_list(ListNode* h) {
	while (h != (ListNode*)NULL) {
		printf("[%d] ", h->data);
		h = h->link;
	}
	printf("\n");
}

main() {
	int choice, position, value, i;
	ListNode* head = (ListNode*)NULL;
	ListNode* h = (ListNode*)NULL;

	while (1) {
		printf("�޴� :\n");
		printf("1. ���ڸ� ��ġ�� ����\n");
		printf("2. ��ġ���� ���� ����\n");
		printf("3. ����Ʈ ���\n");
		printf("4. ����\n");
		printf("�����ϼ���: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("������ ���ڸ� �Է��ϼ���: ");
			scanf_s("%d", &value);
			printf("������ ��ġ�� �Է��ϼ���: ");
			scanf_s("%d", &position);


			if (position == 0) {
				head = insert_first(head, value);
				printf("��ũ�� ���� �̵��� Ƚ��: 0\n");
			}
			else {
				ListNode* pre = head;
				for (i = 0; i < position - 1 && pre != NULL; i++) {
					pre = pre->link;
				}
				if (pre == NULL) {
					printf("��ȿ���� ���� ��ġ�Դϴ�.\n");
				}
				else {
					head = insert(head, pre, value);
					printf("��ũ�� ���� �̵��� Ƚ��: %d\n", i + 1);
				}
			}
			break;

		case 2:
			printf("������ ��ġ�� �Է��ϼ���: ");
			scanf_s("%d", &position);

			if (position == 0) {
				head = delete_first(head, h);
				printf("��ũ�� ���� �̵��� Ƚ��: 0\n");
			}
			else {
				ListNode* pre = head;
				for (i = 0; i < position - 1 && pre != NULL; i++) {
					pre = pre->link;
				}
				if (pre == NULL || pre->link == NULL) {
					printf("��ȿ���� ���� ��ġ�Դϴ�.\n");
				}
				else {
					head = delete(head, pre);
					printf("��ũ�� ���� �̵��� Ƚ��: %d\n", i + 1);
				}
			}
			break;
		case 3:
			print_list(head);
			break;
		case 0:
			exit(0);
		default:
			printf("��ȿ���� ���� �����Դϴ�! \n ");
		}

	}
	//ListNode* head = (ListNode*)NULL;

	//head = insert_first(head, 10);

	//insert(head, head, 20);
	//print_list(head);

	//insert(head, head, 15);
	//print_list(head);

	//ListNode* p = (ListNode*)head;
	//for (int i = 0; i < 2; i++) {
	//	p = p->link;
	//}
	//insert(head, p, 40);
	//print_list(head);

	//element value;
	//value = delete(head, head);
}
