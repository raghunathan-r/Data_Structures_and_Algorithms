#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(value)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};
  
  
struct node* insert(struct node* root, int data)
{
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}

void preorder(struct node* root)
{
    if(root == NULL) return;
    
    printf("%d ->", root->data);
	preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root == NULL) return;
    
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root == NULL) return;
        
	postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}

void search(struct node* p, int key)
{
    if (p == NULL) 
    {
		printf("Tree or node with key does not Exist\n");
		return;
	}
	if(p->data==key)
	{
		printf("Node found!\n");
		return;
	}
	else if (key < p->data)
        search(p->left, key);
    else if (key > p->data)
        search(p->right, key);   
 
    
}

int main()
{
    struct node *root = NULL;
    int ch,num;
    
    printf("Program to demonstrate Binary Tree\n");
l:  while(1)
	{
		printf("\n1.insert a node to the tree\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Serach\n6.Exit\n\n");
		printf("Enter your choice\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1: printf("Enter a positive number\n");
	    			scanf("%d",&num);
	    			root=insert(root,num);
	    			break;
	    	case 2: preorder(root);
	    			break;
	    	case 3: inorder(root);
	    			break;
	    	case 4: postorder(root);
	    			break;
	    	case 5: printf("Enter a node to be searched\n");
	    			scanf("%d",&num);
	    			search(root,num);
	    			break;
	    	case 6: return 0;
	    	default: printf("Wrong Choice!!!\n");
					goto l;
	    	
		}
	}
}
