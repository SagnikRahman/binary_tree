#include <stdio.h>
#include <stdlib.h>

struct bnode {
    int data;
    struct bnode *left, *right;
};

struct bnode* createNode(int data) {
    struct bnode* newNode = (struct bnode*)malloc(sizeof(struct bnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct bnode* insert(struct bnode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct bnode* findMin(struct bnode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct bnode* deleteNode(struct bnode* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct bnode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct bnode* temp = root->left;
            free(root);
            return temp;
        }
        struct bnode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct bnode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct bnode* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Clean up: free allocated memory for the tree nodes
    // Implement a function to free the nodes if needed

    return 0;
}
