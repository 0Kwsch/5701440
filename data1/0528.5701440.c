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
        printf("리스트가 비어있습니다.\n");
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
    printf("\n메뉴:\n");
    printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
    printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
    printf("3. 리스트 처음 노드 삭제\n");
    printf("4. 리스트 마지막 노드 삭제\n");
    printf("5. 리스트 프린트\n");
    printf("6. 종료\n");
}

int main() {
    ListNode* tail = NULL;
    int choice, data;

    while (1) {
        menu();
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("숫자를 입력하세요: ");
            scanf_s("%d", &data);
            tail = insert_first(tail, data);
            break;
        case 2:
            printf("숫자를 입력하세요: ");
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
            printf("프로그램을 종료합니다.\n");
            while (tail != NULL) {
                tail = delete_first(tail);
            }
            exit(0);
            break;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
    }
    return 0;
}