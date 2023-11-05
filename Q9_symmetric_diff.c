#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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
    }
}

struct Node* symmetricDifference(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;

    while (temp1 != NULL) {
        int found = 0;
        struct Node* temp2 = list2;

        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                found = 1;
                break;
            }
            temp2 = temp2->next;
        }

        if (!found) {
            insertEnd(&result, temp1->data);
        }
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        int found = 0;
        struct Node* temp1 = list1;

        while (temp1 != NULL) {
            if (temp2->data == temp1->data) {
                found = 1;
                break;
            }
            temp1 = temp1->next;
        }

        if (!found) {
            insertEnd(&result, temp2->data);
        }
        temp2 = temp2->next;
    }

    return result;
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
    struct Node* list1 = NULL; 
    struct Node* list2 = NULL; 
    int num1, num2, value;

    printf("Enter the number of elements in list1: ");
    scanf("%d", &num1);

    for (int i = 0; i < num1; i++) {
        printf("Enter element %d for list1: ", i + 1);
        scanf("%d", &value);
        insertEnd(&list1, value);
    }

    printf("Enter the number of elements in list2: ");
    scanf("%d", &num2);

    for (int i = 0; i < num2; i++) {
        printf("Enter element %d for list2: ", i + 1);
        scanf("%d", &value);
        insertEnd(&list2, value);
    }

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* result = symmetricDifference(list1, list2);

    printf("Symmetric Difference: ");
    printList(result);

    return 0;
}