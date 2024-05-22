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
    printf("1.리스트의 매 마지막에 새로운 과일 추가\n");
    printf("2. 리스트에 있는 과일을 삭제\n");
    printf("3. 삭제된 과일 목록 출력\n");
    printf("4. 종료\n");
    printf("번호를 입력하세요: ");
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
            printf("1.리스트의 매 마지막에 새로운 과일 추가 ");
            scanf("%s", fruit);
            if (search_list(head, fruit)) {
                printf("%s 이미 리스트 안에 존재합니다.\n", fruit);
            }
            else {
                head = insert_last(head, fruit);
                printf("%s 리스트에 추가합니다.\n", fruit);
            }
            break;
        case 2:
            printf("2. 리스트에 있는 과일을 삭제 ");
            scanf("%s", fruit);
            if (search_list(head, fruit)) {
                head = delete(head, fruit);
                deleted_head = insert_last(deleted_head, fruit);
                printf("%s 리스트에서 삭제합니다.\n", fruit);
            }
            else {
                printf("%s 리스트 안에서 찾을 수 없습니다.\n", fruit);
            }
            break;
        case 3:
            printf("삭제된 과일 목록 출력");
            print_list(deleted_head);
            break;
        case 4:
            printf("종료\n");
            break;
        default:
            printf("값이 존재하지않습니다. 다시 입력하세요.\n");
        }
    } while (choice != 4);

    return 0;
}