#include <stdio.h>
#include <stdlib.h>

#define n = 100
int Inorder[100];
int i = 0;


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

void inorder(struct tree * root){
    if(root == NULL)
    return ;

    else{
        inorder(root->left);
        Inorder[i++] = root->data;
        inorder(root->right);
    }
}

void findPairsWithSum(int arr[], int size, int key) {
    int found = 0;

    printf("Pairs with sum %d are:\n", key);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == key) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pairs found.\n");
    }
}

int main()
{
    struct tree * root;
    root = create_tree();
    inorder(root);
    printf("\n");
    int val;
    printf("Enter the Key->\n");
    scanf("%d",&val);
    findPairsWithSum(Inorder,i+1,val);
    return 0;
}
