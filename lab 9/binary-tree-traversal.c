#include <stdio.h>
#include <stdlib.h>

int node_count = 0;
int leaf_count = 0;

struct tree{
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree * create_node(){
    int choice;
    printf("Enter the number you want to insert in tree or -1 to stop\n");
    scanf("%d",&choice);
    if(choice == -1){
        return NULL;
    }
    else{
        struct tree * node;
        node =  (struct tree *)malloc(sizeof(struct tree));
        node->data = choice;
        node->left = create_node();
        node->right = create_node();
        if(node->left == NULL && node->right== NULL){
            leaf_count++;
        }
        return node;
    }
}

void preorder(struct tree * root){
    if(root == NULL){
        return;
    }
    else{
        printf("%d ",root->data);
        node_count++;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct tree * root){
    if(root == NULL){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct tree * root){
    if(root == NULL){
        return;
    }
    else{
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int height_calc(struct tree * root){

    if(root == NULL)
    return 0;

    int lh = height_calc(root->left);
    int rh = height_calc(root->right);

    if(lh>=rh)
    return lh+1;

    if(lh<rh)
    return rh+1;
}


int main()
{
    struct tree * root;
    root = create_node();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("The value of no of nodes is = %d\n",node_count);
    printf("The value of no of leaf nodes is = %d\n",leaf_count);
    printf("Height of tree is %d",height_calc(root));
    return 0;
}
