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

void display(List L){
    printf("[ ");
    for(int i = 0; i < L.count; i++) {
        printf("%d, ", L.elemPtr[i]);
    }
    printf("]");
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

int main() {
    List myList;

    myList = initialize(myList);

    myList = insertPos(myList, 1, 0);
    myList = insertPos(myList, 2, 1);
    myList = insertPos(myList, 3, 2);
    display(myList);

    return 0;
}