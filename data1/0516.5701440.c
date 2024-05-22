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
		printf("메뉴 :\n");
		printf("1. 숫자를 위치에 삽입\n");
		printf("2. 위치에서 숫자 삭제\n");
		printf("3. 리스트 출력\n");
		printf("4. 종료\n");
		printf("선택하세요: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("삽입할 숫자를 입력하세요: ");
			scanf_s("%d", &value);
			printf("삽입할 위치를 입력하세요: ");
			scanf_s("%d", &position);


			if (position == 0) {
				head = insert_first(head, value);
				printf("링크를 따라 이동한 횟수: 0\n");
			}
			else {
				ListNode* pre = head;
				for (i = 0; i < position - 1 && pre != NULL; i++) {
					pre = pre->link;
				}
				if (pre == NULL) {
					printf("유효하지 않은 위치입니다.\n");
				}
				else {
					head = insert(head, pre, value);
					printf("링크를 따라 이동한 횟수: %d\n", i + 1);
				}
			}
			break;

		case 2:
			printf("삭제할 위치를 입력하세요: ");
			scanf_s("%d", &position);

			if (position == 0) {
				head = delete_first(head, h);
				printf("링크를 따라 이동한 횟수: 0\n");
			}
			else {
				ListNode* pre = head;
				for (i = 0; i < position - 1 && pre != NULL; i++) {
					pre = pre->link;
				}
				if (pre == NULL || pre->link == NULL) {
					printf("유효하지 않은 위치입니다.\n");
				}
				else {
					head = delete(head, pre);
					printf("링크를 따라 이동한 횟수: %d\n", i + 1);
				}
			}
			break;
		case 3:
			print_list(head);
			break;
		case 0:
			exit(0);
		default:
			printf("유효하지 않은 선택입니다! \n ");
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
