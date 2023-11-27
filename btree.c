#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Tree
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node and its left and right child nodes
void insertNode(struct Node *root, int key) {
    printf("Enter left child for %d (Enter -1 for no left child): ", key);
    int leftKey;
    scanf("%d", &leftKey);
    if (leftKey != -1) {
        root->left = createNode(leftKey);
        insertNode(root->left, leftKey);
    }

    printf("Enter right child for %d (Enter -1 for no right child): ", key);
    int rightKey;
    scanf("%d", &rightKey);
    if (rightKey != -1) {
        root->right = createNode(rightKey);
        insertNode(root->right, rightKey);
    }
}

// Function to delete a node with the given key from the Binary Tree
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key == root->key) {
        free(root);
        return NULL;
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);

    return root;
}

// Function to search for a key in the Binary Tree
struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->key == key)
        return root;

    struct Node *leftSearch = search(root->left, key);
    struct Node *rightSearch = search(root->right, key);

    return leftSearch ? leftSearch : rightSearch;
}

// Function to find the minimum key in the Binary Tree
struct Node *findMin(struct Node *root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Function to find the maximum key in the Binary Tree
struct Node *findMax(struct Node *root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Function to perform inorder traversal of the Binary Tree
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Example usage
int main() {
    int rootKey;
    printf("Enter the key for the root node: ");
    scanf("%d", &rootKey);

    struct Node *root = createNode(rootKey);
    insertNode(root, rootKey);

    printf("Inorder traversal of the Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    int searchKey;
    printf("Enter key to search: ");
    scanf("%d", &searchKey);
    printf("Search for key %d: %s\n", searchKey, search(root, searchKey) ? "Found" : "Not Found");

    int deleteKey;
    printf("Enter key to delete: ");
    scanf("%d", &deleteKey);
    root = deleteNode(root, deleteKey);
    printf("Inorder traversal after deleting key %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    struct Node *minNode = findMin(root);
    struct Node *maxNode = findMax(root);

    printf("Minimum element in the Binary Tree: %d\n", minNode ? minNode->key : -1);
    printf("Maximum element in the Binary Tree: %d\n", maxNode ? maxNode->key : -1);

    return 0;
}
