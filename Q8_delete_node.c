#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteSmallestNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete the smallest node.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* smallestNode = *head;

    while (current != NULL) {
        if (current->data < smallestNode->data) {
            smallestNode = current;
        }
        current = current->next;
    }

    if (smallestNode->prev != NULL) {
        smallestNode->prev->next = smallestNode->next;
    } else {
        *head = smallestNode->next; 
    }
    if (smallestNode->next != NULL) {
        smallestNode->next->prev = smallestNode->prev;
    }

    free(smallestNode); 
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
    int num, value;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Original list: ");
    printList(head);

    deleteSmallestNode(&head);

    printf("Modified list: ");
    printList(head);

    return 0;
}
