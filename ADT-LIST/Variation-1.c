// List is a static array and accessed by value
#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count; // count is how many elements are in the list
}List;

// Function Prototypes
List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data); // pangitaon gamit index
List insertSorted(List L, int data);
void display(List L);

// Initialize
List initialize(List L) {
    L.count = 0;
    return L;
}
// Insert at Position (index)
List insertPos(List L, int data, int position) {
    int i;
    // check if there is available space
    if(L.count < MAX) {
        for(i = L.count; i > position; i--) {
            L.elem[i] = L.elem[i-1];
        }
        L.elem[i] = data;
        L.count++;
    }

    return L;
}
// delete at position
List deletePos(List L, int position) {
    int i;
    if (position < L.count) { // dapat less than count para ma valid position
        for(i = position; i < L.count; i++) {
        L.elem[i] = L.elem[i+1];
    }
    L.count--;
    }
    return L;
}
// locate
int locate(List L, int data) {
    int i;
    for(int i=0; i<L.count; i++) {
        if(L.elem[i] == data) {
            return i;
        }
    }
    return -1; // if not found
}
// insert sorted
List insertSorted(List L, int data) {
    int i;
    for(i = L.count; i > 0 && L.elem[i-1] > data; i--) {
        L.elem[i] = L.elem[i-1]; // copies the element to the right
    }
    L.elem[i] = data;
    L.count++;
    return L;
}
// display
void display(List L) {
    int i;
    for (i = 0; i < L.count; i++) {
        printf("%c ", L.elem[i]);
    }
}

int main() {
    List Listahan;

    Listahan = initialize(Listahan);
    
    Listahan = insertPos(Listahan, 'S', 0); // S at pos 0
    Listahan = insertPos(Listahan, 'O', 1); // 0 at pos 1
    Listahan = insertPos(Listahan, 'P', 2); // P at pos 2
    
    // Display list 
    display(Listahan); // S O P

    // Insert A in pos 2
    Listahan = insertPos(Listahan, 'A', 2); // A at pos 2

    // updated display
    display(Listahan); // S O A P

    Listahan = deletePos(Listahan, 1);

    //Updated display list with delete
    display(Listahan); // S A P

    return 0;
}