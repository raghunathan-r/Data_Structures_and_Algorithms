#include<stdio.h>
#include<stdlib.h>
  
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE *createNode (int value)
{
    struct node *newNode = malloc(sizeof(NODE));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
  
NODE *insert (NODE *root, int data)
{
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}

void preorderTraversal (NODE *root)
{
    if(root == NULL) return;
    
    printf("%d\t", root->data);
	preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal (NODE *root)
{
    if(root == NULL) return;
    
    inorderTraversal(root->left);
    printf("%d\t", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal (NODE *root)
{
    if(root == NULL) return;
        
	postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\t", root->data);
}

void search(NODE *p, int key)
{
    if (p == NULL) 
    {
		printf("Tree or node with key does not Exist\n");
		return;
	}
	if(p->data == key)
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
    NODE *root = NULL;
    int ch,num;
    
    printf("\n\nProgram to demonstrate Binary Tree\n");
    do
	{
		printf("\n1. Insert a node to the tree\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Search\n6. Exit\n\n");
		printf("Enter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1: printf("Enter a positive number : ");
	    			scanf("%d",&num);
	    			root=insert(root,num);
	    			break;
	    	case 2: preorderTraversal(root);
	    			break;
	    	case 3: inorderTraversal(root);
	    			break;
	    	case 4: postorderTraversal(root);
	    			break;
	    	case 5: printf("Enter a node to be searched : ");
	    			scanf("%d",&num);
	    			search(root,num);
	    			break;
	    	case 6: printf("Terminating the program...\n\n");
                    return 0;
	    	default: printf("Invalid entry ! Try again...\n");
		}
	}while (ch != 6);
}