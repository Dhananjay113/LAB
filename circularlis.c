#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;

    if(head != NULL) {
        struct Node* ptr = head;
        while(ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    } 
    else {
        temp->next = temp;
    }

    head = temp;
}

void print() {
    struct Node* ptr = head;
    if(ptr != NULL) {
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while(ptr != head);
    }
    printf("\n");
}

int main() {
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    print();
    return 0;
}
