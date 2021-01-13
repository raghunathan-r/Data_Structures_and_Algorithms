#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
  char data;
  struct node *left;
  struct node *right;
} node;

node *maketree()
{
    node *p;
    char x;
    fflush(stdin);
    printf("Enter data(Enter N for no node): ");
    scanf("%c",&x);

    if(x=='N')
		return NULL;

    p=(node *)malloc(sizeof(node));
    p->data=x;
    printf("\nEnter left child of %C:\n",x);
    p->left=maketree();
    printf("\nEnter right child of %C:\n",x);
    p->right=maketree();
    
	return p;
}

void preorder(node *t)
{
  if(t!=NULL)
  {
    printf("%c ",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}

void inorder(node *t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("%c ",t->data);
    inorder(t->right);
  }
}

void postorder(node *t)
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("  %c ",t->data);
  }
}

void main()
{
  node *root;
  root=maketree();
  printf("\nThe preorder traversal of tree is: ");
  preorder(root);
  printf("\nThe inorder traversal of tree is: ");
  inorder(root);
  printf("\nThe postorder traversal of tree is: ");
  postorder(root);
  
}