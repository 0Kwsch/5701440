#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* tail, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        node->link = tail;
    }
    else {
        node->link = tail->link;
        tail->link = node;
    }
    return tail;
}

ListNode* insert_last(ListNode* tail, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        node->link = node;
    }
    else {
        node->link = tail->link;
        tail->link = node;
        tail = node;
    }
    return tail;
}

ListNode* delete_first(ListNode* tail) {
    if (tail == NULL) return NULL;
    ListNode* head = tail->link;
    if (tail == head) {
        free(head);
        return NULL;
    }
    tail->link = head->link;
    free(head);
    return tail;
}

ListNode* delete_last(ListNode* tail) {
    if (tail == NULL) return NULL;
    ListNode* prev = tail;
    ListNode* curr = tail->link;
    if (prev == curr) {
        free(curr);
        return NULL;
    }
    while (curr->link != tail) {
        prev = curr;
        curr = curr->link;
    }
    prev->link = curr->link;
    free(curr);
    return prev;
}

void print_list(ListNode* tail) {
    if (tail == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }
    ListNode* p = tail->link;
    do {
        printf("[%2d] ", p->data);
        p = p->link;
    } while (p != tail->link);
    printf("\n");
}

void menu() {
    printf("\n�޴�:\n");
    printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
    printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
    printf("3. ����Ʈ ó�� ��� ����\n");
    printf("4. ����Ʈ ������ ��� ����\n");
    printf("5. ����Ʈ ����Ʈ\n");
    printf("6. ����\n");
}

int main() {
    ListNode* tail = NULL;
    int choice, data;

    while (1) {
        menu();
        printf("�޴��� �����ϼ���: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &data);
            tail = insert_first(tail, data);
            break;
        case 2:
            printf("���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &data);
            tail = insert_last(tail, data);
            break;
        case 3:
            tail = delete_first(tail);
            break;
        case 4:
            tail = delete_last(tail);
            break;
        case 5:
            print_list(tail);
            break;
        case 6:
            printf("���α׷��� �����մϴ�.\n");
            while (tail != NULL) {
                tail = delete_first(tail);
            }
            exit(0);
            break;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
    }
    return 0;
}