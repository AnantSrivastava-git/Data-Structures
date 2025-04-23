#include <stdio.h>
#include <stdlib.h>


struct tree{
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree * create_tree(){
    int choice;
    printf("Enter the value you want to insert in node of the tree or -1 to stop\n");
    scanf("%d",&choice);

    if(choice == -1)
    return NULL;

    else{
        struct tree* node = (struct tree*)malloc(sizeof(struct tree));
        node->data = choice;
        node->left = create_tree();
        node->right = create_tree();

        return node;
    }
}

struct tree * search (struct tree* root,int val){
    if(root== NULL)
    return NULL;

    if( root->data == val)
    return root;

    if(val<root->data)
    return search(root->left,val);

    else
    return search(root->right,val);
}

struct tree* findMin(struct tree* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct tree* delete(struct tree* root, int val) {
    if (root == NULL)
        return NULL;

    if (val < root->data)
        root->left = delete(root->left, val);
    else if (val > root->data)
        root->right = delete(root->right, val);
    else {

        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct tree* temp = root->left;
            free(root);
            return temp;
        }

        struct tree* temp = findMin(root->right);  
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void preorder(struct tree * root){
    if(root == NULL)
    return ;

    else{
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct tree * root;
    root = create_tree();
    preorder(root);
    printf("\n");
    int val;
    printf("Enter the value you want to search for ?\n");
    scanf("%d",&val);
    struct tree * node = search(root,val);
    if(node != NULL)
    printf("Found!");
    else
    printf("Not Found!");
    printf("\n");
    return 0;
}
