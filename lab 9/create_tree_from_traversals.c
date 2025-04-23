#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* newNode(int data) {
    struct tree* node = (struct tree*) malloc(sizeof(struct tree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; 
}

struct tree* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    int currentVal = preorder[*preIndex];
    (*preIndex)++;

    struct tree* node = newNode(currentVal);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, currentVal);

    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void Inorder(struct tree* root) {
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

int main() {
    int inorder[] =  {4,5,6,8,10,11,17,19,31,43,49};
    int preorder[] = {11,6,4,5,8,10,19,17,43,31,49};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    int preIndex = 0;

    struct tree* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Inorder traversal of the new tree is\n");
    Inorder(root);
    return 0;
}
