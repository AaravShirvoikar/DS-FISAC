#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void preorderPrint(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void levelOrderPrint(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    struct Node* root = NULL; 
    int num, value;

    printf("Enter the number of elements in the binary tree: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nBinary Tree in Preorder : ");
    preorderPrint(root);
    printf("\n");

    printf("Binary Tree in Level Order : ");
    levelOrderPrint(root);
    printf("\n");

    return 0;
}
