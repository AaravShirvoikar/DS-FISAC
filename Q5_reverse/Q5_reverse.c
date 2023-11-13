#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->number = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 
    int num, value;

    printf("Enter the number of people in the line: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        insert(&head, i + 1); 
    }

    printf("Original line: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed line: ");
    printList(head);

    return 0;
}
