#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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

void splitLinkedList(struct Node* original, struct Node** list1, struct Node** list2) {
    int count = 0;
    struct Node* current = original;

    while (current != NULL) {
        if (count % 2 == 0) {
            insert(list1, current->data);
        } else {
            insert(list2, current->data);
        }
        count++;
        current = current->next;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 
    struct Node* list1 = NULL; 
    struct Node* list2 = NULL; 
    int num, value;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insert(&head, value);
    }

    splitLinkedList(head, &list1, &list2);

    printf("Original list: ");
    printList(head);

    printf("List1: ");
    printList(list1);

    printf("List2: ");
    printList(list2);

    return 0;
}
