#include <stdio.h>
#include "tree.h"

int main() {
    Node* root = NULL;

    // Insert nodes into the tree
    insertNode(&root, createNode());
    insertNode(&root, createNode());
    insertNode(&root, createNode());

    // Calculate and print the height of the tree
    printf("Tree Height: %d\n", treeHeight(root));

    // Free the tree
    freeTree(root);

    return 0;
}
