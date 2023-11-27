#include<stdio.h>
#include<stdlib.h>

struct bnode {
    int data;
    struct bnode *left, *right;
};

struct bnode* create() {
    printf("Press 1 to create a new node and 0 to exit ");
    int choice;
    scanf("%d", &choice);
    if (choice == 0)
        return NULL;
    else {
        int data;
        struct bnode* temp = (struct bnode*)malloc(sizeof(struct bnode));
        printf("Enter data: ");
        scanf("%d", &data);
        temp->data = data;
        printf("FOR LEFT CHILD OF %d........\n", data);
        temp->left = create();
        printf("FOR RIGHT CHILD OF %d........\n", data);
        temp->right = create();
        return temp;
    }
}

void preorder_traversal(struct bnode* node) {
    if (node == NULL)
        return;
    printf("%d\t", node->data);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void postorder_traversal(struct bnode* node) {
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    printf("%d\t", node->data);
}

void inorder_traversal(struct bnode* node) {
    if (node == NULL)
        return;
    inorder_traversal(node->left);
    printf("%d\t", node->data);
    inorder_traversal(node->right);
}

int main() {
    struct bnode* root = create();
    printf("PREORDER-\n");
    preorder_traversal(root);
    printf("\nPOSTORDER-\n");
    postorder_traversal(root);
    printf("\nINORDER-\n");
    inorder_traversal(root);
    return 0;
}
