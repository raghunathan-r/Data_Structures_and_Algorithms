#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
  char data;
  struct node *left;
  struct node *right;
} node;

node *makeTree()
{
  node *p;
  char x;
  fflush(stdin);
  printf("Enter data [enter N for no node] : ");
  scanf("%c", &x);

  if(x == 'N')
  return NULL;

  p=(node *)malloc(sizeof(node));
  p->data = x;
  printf("\nEnter left child of %c: \n", x);
  p->left = makeTree();
  printf("\nEnter right child of %c : \n", x);
  p->right = makeTree();
  
	return p;
}

void preorderTraversal(node *t)
{
  if(t!=NULL)
  {
    printf("%c ",t->data);
    preorderTraversal(t->left);
    preorderTraversal(t->right);
  }
}

void inorderTraversal(node *t)
{
  if(t!=NULL)
  {
    inorderTraversal(t->left);
    printf("%c ", t->data);
    inorderTraversal(t->right);
  }
}

void postorderTraversal(node *t)
{
  if(t != NULL)
  {
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%c ", t->data);
  }
}

void main()
{
  node *root;
  root = makeTree();

  printf("\nThe preorder traversal of tree is: ");
  preorderTraversal(root);
  printf("\nThe inorder traversal of tree is: ");
  inorderTraversal(root);
  printf("\nThe postorder traversal of tree is: ");
  postorderTraversal(root);
  
}