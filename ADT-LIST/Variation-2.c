#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr *L);
void insertPos(EPtr L, int data, int index);
void deletePos(EPtr L, int index);
int locate(EPtr L, int data);
int retrieve(EPtr L, int index);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

// Function definitions
void initialize(EPtr *L) {
    *L = (EPtr)calloc(1, sizeof(Etype));
}

void insertPos(EPtr L, int data, int index) {
    int i;
    for(i = L->count; i > index; i--) { // move the element to the right
        L->elem[i] = L->elem[i-1];
    }
    L->elem[i] = data;
    L->count++;
}

void deletePos(EPtr L, int index) {
    int i;
    for(i = index; i < L->count; i++) { // move items to the left
        L->elem[i] = L->elem[i+1];
    }
    L->count--;
}

int locate(EPtr L, int data) { // return the index of the search data
    int i;
    for(i = 0; i < L->count; i++) {
        if(L->elem[i] == data){
            return i;
        }
    }
    return -1; // if not found
}

int retrieve(EPtr L, int index){ // pangitaon ang element based sa given index
    // check if the index is valid
    if(index < 0 || index >= L->count){
        return -1; // if not valid
    }
    // return the element at the given index
    return L->elem[index];
}

void display(EPtr L) {
    printf("[ ");
    for(int i = 0; i < L->count; i++) {
        printf("%d, ", L->elem[i]);
    }
    printf("]\n");
}

void makeNULL(EPtr L) {
    L->count = 0;
}

void insertSorted(EPtr L, int data) {
    int i;
    for(i = L->count; i > 0 && L->elem[i-1] > data; i--) {
        L->elem[i] = L->elem[i-1]; // copy the element to the free index to the right
    }
    L->elem[i] = data; // insert the data at the given index
    L->count++;
}

int main() {
    EPtr list;

    initialize(&list);   // start with empty list

    printf("Inserting elements...\n");
    insertPos(list, 10, 0); // [10]
    insertPos(list, 20, 1); // [10, 20]
    insertPos(list, 15, 1); // [10, 15, 20]
    display(list);

    printf("Retrieve element at index 1: %d\n", retrieve(list, 1)); // should print 15

    printf("Locating element 20... Index: %d\n", locate(list, 20)); // should print 2

    printf("Inserting element 12 in sorted order...\n");
    insertSorted(list, 12); // [10, 12, 20]
    display(list);

    printf("Deleting element at index 1...\n");
    deletePos(list, 1); // removes 15 -> [10, 20]
    display(list);

    printf("Making list empty...\n");
    makeNULL(list); // count = 0
    display(list);  // should print []

    return 0;
}
