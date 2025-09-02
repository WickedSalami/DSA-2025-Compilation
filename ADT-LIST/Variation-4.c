// List is a DYNAMIC ARRAY and accessed by POINTER
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;

void initialize (List *L);
void insertPos (List *L, int elem, int index);
void deletePos(List *L, int index);
int locate (List *L, int data);
int retrieve (List *L, int index);
void insertSorted (List *L, int elem);
void makeNULL(List *L);
void resize(List *L);
void display(List *L);

void initialize (List *L) {
    L->elemPtr = (int *)calloc(LENGTH, sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int elem, int index) {
    int i;
    if(index <= L->count) {
        for(i = L->count; i > index; i--) {
            L->elemPtr[i] = L->elemPtr[i-1];
        }
        L->elemPtr[i] = elem;
        L->count++;
    }
}

void deletePos(List *L, int index) {
    int i;
    if(index <= L->count) {
        for(i = index; i < L->count; i++) {
            L->elemPtr[i] = L->elemPtr[i+1];
        }
        L->count--;
    }
}

int locate (List *L, int data) {
    int i;
    for(i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data) {
            return i;
        }
    }
    return -1;
}

int retrieve (List *L, int index) {
    if(index < 0 || index >= L->count) {
        return -1;
    }
    return L->elemPtr[index];
}

void insertSorted(List *L, int data) {
    int i;
    for(i = L->count; i > 0 && L->elemPtr[i-1] > data; i--) {
        L->elemPtr[i] = L->elemPtr[i-1];
    }
    L->elemPtr[i] = data;
    L->count++;
}

void display(List *L){
    printf("[ ");
    for(int i = 0; i < L->count; i++) {
        printf("%d, ", L->elemPtr[i]);
    }
    printf("]");
}

void makeNULL(List *L) {
    L->count = 0;
}

int main() {
    List myList;

    initialize(&myList);

    insertPos(&myList, 2, 0);
    insertPos(&myList, 5, 1);
    insertPos(&myList, 6, 2);
    insertPos(&myList, 8, 3);
    insertPos(&myList, 9, 4);
    display(&myList);

    printf("\nDeleted elem: ");
    deletePos(&myList, 2);
    display(&myList);

    printf("\nLocate data 8: Index %d", locate(&myList, 8));

    printf("\nInsert Sorted: ");
    insertSorted(&myList, 7);
    display(&myList);

    return 0;
}