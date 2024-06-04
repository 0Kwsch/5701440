#include<stdio.h>
#include<stdlib.h>


typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink, * rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode)); //<1>
	newnode->data = data;
	newnode->llink = before; //<2>
	newnode->rlink = before->rlink; //<3>
	before->rlink = newnode; //<4>
	newnode->rlink->llink = newnode; //<5>

}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		printf("[%d]  ", p->data);
	}
	printf("\n");
}

element ddelete(DListNode* head, DListNode* removed) {
	element r;
	if (removed == head) return;
	r = removed->data;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	return r;
}

int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));

	init(head);
	int choice, data;

	while (1)
	{
		printf("\n�޴�\n");
		printf("1.���ڸ� �Է¹޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2.���ڸ� �Է¹޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3.����Ʈ ó�� ��� ����\n");
		printf("4.����Ʈ ������ ��� ����\n");
		printf("5.����Ʈ ����Ʈ\n");
		printf("6. ����\n");
		printf("����: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("���ڸ� �Է�: ");
			scanf_s("%d", &data);
			dinsert(head, data);
			break;
		case 2:
			printf("���ڸ� �Է�: ");
			scanf_s("%d", &data);
			dinsert(head->llink, data);
			break;

		case 3:
			ddelete(head, head->llink);
			break;
		case 4:
			ddelete(head, head->rlink);
			break;
		case 5:
			print_dlist(head);
			break;
		case 6:
			printf("���α׷��� �����մϴ�.\n");
			return 0;

		default:
			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");

		}
	}

}
