#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Search Tree
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

// Function to insert a new node into the Binary Search Tree
struct Node *insertNode(struct Node *root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

// Function to delete a node with the given key from the Binary Search Tree
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        struct Node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to search for a key in the Binary Search Tree
struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Function to perform inorder traversal of the Binary Search Tree
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the Binary Search Tree
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the Binary Search Tree
void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

// Example usage
int main() {
    int rootKey;
    printf("Enter the key for the root node: ");
    scanf("%d", &rootKey);

    struct Node *root = createNode(rootKey);

    int n;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter the keys for insertion:\n");
    for (int i = 0; i < n; ++i) {
        int key;
        scanf("%d", &key);
        insertNode(root, key);
    }

    printf("Inorder traversal of the Binary Search Tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal of the Binary Search Tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the Binary Search Tree: ");
    postorderTraversal(root);
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

    return 0;
}
