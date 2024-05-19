#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
}

void init(ArrayListType* L) {
    L->size = 0;
}

int is_full(ArrayListType* L) {
    return (L->size == MAX_LIST_SIZE);
}

int is_empty(ArrayListType* L) {
    return (L->size == 0);
}

void print_list(ArrayListType* L) {
    printf("[LIST] ");
    for (int i = 0; i < L->size; i++) {
        printf("<%2d> ", L->array[i]);
    }
    printf("\n");
}

int insert(ArrayListType* L, int pos, element item) {
    int move_count = 0;
    if (is_full(L)) {
        error("리스트 오버플로우");
        return -1;
    }
    if (pos < 0 || pos > L->size) {
        error("위치 오류");
        return -1;
    }
    for (int i = L->size - 1; i >= pos; i--) {
        L->array[i + 1] = L->array[i];
        move_count++;
    }
    L->array[pos] = item;
    L->size++;
    return move_count;
}

int delete(ArrayListType* L, int pos) {
    int move_count = 0;
    if (pos < 0 || pos >= L->size) {
        error("위치 오류");
        return -1;
    }
    for (int i = pos; i < L->size - 1; i++) {
        L->array[i] = L->array[i + 1];
        move_count++;
    }
    L->size--;
    return move_count;
}

int main() {
    ArrayListType list;
    int menu, pos, item, move_count;

    init(&list);

    while (1) {
        printf("\n메뉴:\n");
        printf("1: 리스트에 추가 (숫자와 위치 입력)\n");
        printf("2: 리스트에서 삭제 (위치 입력)\n");
        printf("3: 리스트 출력\n");
        printf("0: 프로그램 종료\n");
        printf("선택: ");
        scanf_s("%d", &menu);

        switch (menu) {
        case 1:
            printf("추가할 숫자와 위치 입력: ");
            scanf_s("%d %d", &item, &pos);
            move_count = insert(&list, pos, item);
            if (move_count != -1) {
                printf("데이터 이동 횟수: %d\n", move_count);
                print_list(&list);
            }
            break;
        case 2:
            printf("삭제할 위치 입력: ");
            scanf_s("%d", &pos);
            move_count = delete(&list, pos);
            if (move_count != -1) {
                printf("데이터 이동 횟수: %d\n", move_count);
                print_list(&list);
            }
            break;
        case 3:
            print_list(&list);
            break;
        case 0:
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 선택\n");
        }
    }
}