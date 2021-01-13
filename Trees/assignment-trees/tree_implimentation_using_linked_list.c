#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   char data;
   struct node *left;
   struct node *right;
}NODE;

NODE *makeTree()
{
    NODE *p;
    int x;
    printf("\nEnter the data [-1 to return null] : ");
    scanf("%d", &x);
    if( x== -1)
      return NULL;
    
    p = (NODE *)malloc(sizeof(NODE));
    p->data = x;
    printf("\nEnter the value for left node of %d 👇",x);
    p->left = makeTree();
    printf("\nEnter the data for right node of %d 👇",x);
    p->right = makeTree();
    
    return p;
}

void inorderTraversal(NODE *t)
{
    if(t != NULL)
    {
        inorderTraversal(t->left);
        printf("%d\t", t->data);
        inorderTraversal(t->right);
    }
}

void preorderTraversal(NODE *t)
{
  if(t != NULL)
  {
    printf("%d\t", t->data);
    preorderTraversal(t->left);
    preorderTraversal(t->right);
  }
}

void postorderTraversal(NODE *t)
{
  if(t!=NULL)
  {
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%d\t", t->data);
  }
}

int main()
{
    NODE *root;
    root = makeTree();

    printf("\n\nDisplaying the inorder transversal\n");
    inorderTraversal(root);
    printf("\n\nDisplaying the preorder transversal\n");
    preorderTraversal(root);
    printf("\n\nDisplaying the postorder transversal\n");
    postorderTraversal(root);
    printf("\n\n");
    return 0;
}