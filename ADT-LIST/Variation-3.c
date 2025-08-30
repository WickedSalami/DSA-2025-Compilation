// List is a dynamic array and accessed by value
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int index);
List deletePos(List L, int index);
int locate(List L, int data); // return the index of the search data
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

List initialize(List L) {
    L.elemPtr = (int *)calloc(LENGTH, sizeof(int));
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int index) {
    int i;
    if(index <= L.count) {
        for(i = L.count; i > index; i--) { // start at the last index
            L.elemPtr[i] = L.elemPtr[i-1]; // copy the element to the right
        }
        L.elemPtr[i] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int index) {
    int i;
    if(index < L.count) {
        for(i = index; i < L.count; i++) {
            L.elemPtr[i] = L.elemPtr[i+1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data) {
    int i;
    for(i = 0; i < L.count; i++) {
        if(L.elemPtr[i] == data) {
            return i;
        } 
    }
    return -1;
}

List insertSorted(List L, int data) {
    int i;
    for(i = L.count; i > 0 && L.elemPtr[i-1] > data; i--) { // if count is greater than 0 and the previous element is greater than data
        L.elemPtr[i] = L.elemPtr[i-1]; // copies the element to the right
    }
    L.elemPtr[i] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("[ ");
    for(int i = 0; i < L.count; i++) {
        printf("%d, ", L.elemPtr[i]);
    }
    printf("]");
}

int main() {
    List myList;

    myList = initialize(myList);

    myList = insertPos(myList, 1, 0);
    myList = insertPos(myList, 2, 1);
    myList = insertPos(myList, 7, 2);
    display(myList);

    printf("\nAdded an element: ");
    myList = insertPos(myList, 8, 3);
    display(myList);

    printf("\nLocating element 7... Index: %d", locate(myList, 7)); // should print 2

    printf("\nInsert sorted: ");
    myList = insertSorted(myList, 5);
    display(myList);

    printf("\nDeleted an element: ");
    myList = deletePos(myList, 1);
    display(myList);

    return 0;
}