#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter ID: ");
    scanf("%d", &(newNode->id));

    printf("Enter Project Name: ");
    scanf("%s", newNode->project);

    newNode->left = newNode->right = NULL;

    return newNode;
}

void insertNode(Node** root, Node* newNode) {
    if (*root == NULL) {
        *root = newNode;
    } else {
        if (newNode->id < (*root)->id) {
            insertNode(&((*root)->left), newNode);
        } else {
            insertNode(&((*root)->right), newNode);
        }
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}
