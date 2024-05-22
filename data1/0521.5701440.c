#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef char element[MAX_NAME_LENGTH];
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    strcpy(p->data, value);
    p->link = h;
    h = p;
    return h;
}

ListNode* insert_last(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    strcpy(p->data, value);
    p->link = NULL;

    if (h == NULL) {
        return p;
    }

    ListNode* temp = h;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = p;
    return h;
}

ListNode* delete(ListNode* h, element value) {
    ListNode* p = h;
    ListNode* pre = NULL;

    while (p != NULL && strcmp(p->data, value) != 0) {
        pre = p;
        p = p->link;
    }

    if (p == NULL) {
        printf("%s not found in the list.\n", value);
        return h;
    }

    if (pre == NULL) {
        h = p->link;
    }
    else {
        pre->link = p->link;
    }

    free(p);
    return h;
}

void print_list(ListNode* h) {
    while (h != NULL) {
        printf("[%s] ", h->data);
        h = h->link;
    }
    printf("\n");
}

ListNode* search_list(ListNode* h, element value) {
    ListNode* p = h;
    while (p != NULL) {
        if (strcmp(p->data, value) == 0) {
            return p;
        }
        p = p->link;
    }
    return NULL;
}

void menu() {
    printf("\nMenu:\n");
    printf("1.����Ʈ�� �� �������� ���ο� ���� �߰�\n");
    printf("2. ����Ʈ�� �ִ� ������ ����\n");
    printf("3. ������ ���� ��� ���\n");
    printf("4. ����\n");
    printf("��ȣ�� �Է��ϼ���: ");
}

int main() {
    ListNode* head = NULL;
    ListNode* deleted_head = NULL;
    element fruits[] = { "Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach" };
    for (int i = 0; i < 10; i++) {
        head = insert_last(head, fruits[i]);
    }

    int choice;
    element fruit;
    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("1.����Ʈ�� �� �������� ���ο� ���� �߰� ");
            scanf("%s", fruit);
            if (search_list(head, fruit)) {
                printf("%s �̹� ����Ʈ �ȿ� �����մϴ�.\n", fruit);
            }
            else {
                head = insert_last(head, fruit);
                printf("%s ����Ʈ�� �߰��մϴ�.\n", fruit);
            }
            break;
        case 2:
            printf("2. ����Ʈ�� �ִ� ������ ���� ");
            scanf("%s", fruit);
            if (search_list(head, fruit)) {
                head = delete(head, fruit);
                deleted_head = insert_last(deleted_head, fruit);
                printf("%s ����Ʈ���� �����մϴ�.\n", fruit);
            }
            else {
                printf("%s ����Ʈ �ȿ��� ã�� �� �����ϴ�.\n", fruit);
            }
            break;
        case 3:
            printf("������ ���� ��� ���");
            print_list(deleted_head);
            break;
        case 4:
            printf("����\n");
            break;
        default:
            printf("���� ���������ʽ��ϴ�. �ٽ� �Է��ϼ���.\n");
        }
    } while (choice != 4);

    return 0;
}