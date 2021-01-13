// Array implimenttaion of trees 
#include<stdio.h>

int max_node_length = 15;
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

int rightChild (int index)
{
    // Index of tree elements in array starts from 1
    if( tree[index]!='\0' && ((2*index)+1)<=max_node_length)
    {
        return (2*index) + 1;
    }
    else return -1;
}

int leftChild (int index)
{
    if(tree[index]!='\0' && (2*index)<=max_node_length)
    {
        return 2*index;
    }
    else return -1;
}

// Functions for diffrent traversal methods

void preorderTraversal (int index)
{
    if(index>0 && tree[index]!='\0')
    {
        printf(" %c\t", tree[index]);
        preorderTraversal(leftChild(index));
        preorderTraversal(rightChild(index));
    }
}

void postorderTraversal (int index)
{
    if(index>0 && tree[index]!='\0')
    {
        postorderTraversal(leftChild(index));
        postorderTraversal(rightChild(index));
        printf(" %c\t",tree[index]);
    }
}

void inorderTraversal (int index)
{
    if(index>0 && tree[index]!='\0')
    {
        inorderTraversal(leftChild(index));
        printf(" %c\t",tree[index]);
        inorderTraversal(rightChild(index));
    }
}

int main()
{
    printf("\n\nDisplaying the tree data\n");

    printf("\nIn preorder traversal :-\n");
    preorderTraversal(1);

    printf("\n\nIn postorder traversal :-\n");
    postorderTraversal(1);

    printf("\n\nIn inorder traversal :-\n");
    inorderTraversal(1);
    
    printf("\n\n");
    return 0;
}