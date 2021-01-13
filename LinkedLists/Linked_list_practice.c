#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;

void createLinkedList (int A[], int n);
void displayLinkedList (struct Node *p);
int sizeOfLinkedList (struct Node *p);
int sumOfLinkedList (struct Node *p);
void maxElementInLinkedList (struct Node *p);
struct Node * SearchLinkedList (int key, struct Node *p);
void insertNodeAtFirst (struct Node *p, int num);
void insertNodeAtPosition (struct Node *p, int num, int pos);
void insertNodeSortedPosition (struct Node *p, int num);
int deleteNodeInLinkedList (struct Node *p, int pos);
int checkIfSortedLinkedList (struct Node *p);
void SortLinkedList (struct Node *p);
void removeDuplicatesFromList (struct Node *p);
void reverseElementsOfLinkedList (struct Node *p);



int main()
{
    int A[] = {1,2,3,4,5}, num, pos;
    createLinkedList (A, 5);
    displayLinkedList (first);
    sizeOfLinkedList (first);
    printf("\nThe sum of all the elements is : %d\n", sumOfLinkedList(first));
    maxElementInLinkedList (first);

    struct Node *temp;
    printf("Enter the element to search : ");
    scanf("%d", &num);
    temp = SearchLinkedList(num, first);
    if(temp)
    {
        printf("\nKey is found -> %d\n", temp->data);
    } 
    else
    {
        printf("\nKey not found !\n");
    }

    printf("\nEnter the position to add new element : ");
    scanf("%d", &pos);
    printf("\nEnter the element you want add : ");
    scanf("%d", &num);
    insertNodeAtPosition(first, num, pos);

    printf("\nEnter the element you want add in sorted list : ");
    scanf("%d", &num);
    insertNodeSortedPosition(first, num);

    printf("\nEnter the position element to delete : ");
    scanf("%d", &pos);
    printf("\nDeleted element is : %d\n", deleteNodeInLinkedList(first, pos));

    return 0;
}
    
void createLinkedList (int A[], int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void displayLinkedList (struct Node *p)
{
    printf("\nDisplaying the elements of the list :-\n");
    while (p!=NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

// Recursive display function
/*void displayLinkedList (struct Node *p)
{
    if(p !=NULL)
    {
        printf("%d\n", p->data);
        displayLinkedList (p->next);
    }
}*/

int sizeOfLinkedList (struct Node *p)
{
    int count = 0;
    while (p != NULL)       
    {
        count ++;
        p = p->next;
    }
    printf("\nThe size of linked list is : %d\n", count);
    return count;
}

// Recursive function for counting size of list- [dont use this as space complexity is high]
/*int sizeOfLinkedList (struct Node *p)
{
    int count = 0;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return sizeOfLinkedList(p->next) + 1;
    }
}*/
/*{
    int count=0;
    if (p!=NULL)
    {
        count = sizeOfLinkedList(p->next);
        return count + 1;
    }
    else
    {
        return 0;
    }
}*/

int sumOfLinkedList (struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// Recursive function for finding sum 
/*int sumOfLinkedList (struct Node *p)
{
   sum = 0;
   if (p == NULL)
   {
       return 0;
   }
   else
   {
       return sumOfLinkedList(p->next) + p->data;
   }
}*/

void maxElementInLinkedList (struct Node *p)
{
    int max=INT_MIN;
    while (p!=NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    printf("The highest element in linked list is : %d\n", max);
}

// Recursive function for Maxmimum element 
/*int maxElementInLinkedList (struct Node *p)
{
    int max=INT_MIN;
    if (p == NULL)
    {
        return max;
    }
    else
    {
        max = maxElementInLinkedList(p->data);
        if (max > p->data)
        {
            return max;
        }
        else
        {
            return p->data;
        }
    }    
}*/

struct Node * SearchLinkedList (int key, struct Node *p)
{
    while (p!=NULL)
    {
        if(p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
// Recursive function for seacrhing 
/*struct Node * SearchLinkedList (int key, struct Node *p)
{
    if (p==NULL)
    {
        return NULL;
    }
    if (key==p->data)
    {
        return p;
    }
    return SearchLinkedList (key, p->next);
}*/

void insertNodeAtFirst (struct Node *p, int num)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = p;
    p = temp;
    displayLinkedList(p);
}

void insertNodeAtPosition (struct Node *p, int num, int pos)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    int length = sizeOfLinkedList(p);
    if (pos < 0 || pos>length) 
    {
        printf("\nINVALID POSITION\n");
        return;
    }
    
    if (pos == 0)   
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        for (int i = 0; i < pos-1; i++)
        {
            p=p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    displayLinkedList(first);
}

void insertNodeSortedPosition (struct Node *p, int num)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *q=NULL;
    temp->data = num;
    temp->next = NULL;

    if(first==NULL)
    {
        first = temp;
    }
    else
    {
        while (p!=NULL && p->data < num)
        {
            q = p;
            p=p->next;
        }
        if (p==first)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            temp->next = q->next;
            q = temp;           
        }    
    }
    displayLinkedList(first);
}

int deleteNodeInLinkedList (struct Node *p, int pos)
{
    int deletedData;
    struct Node *temp=NULL;
    if(pos==0)
    {
        temp = first;
        first=first->next;
        free(temp);
    }
    else
    {
        for (int i = 0; i < pos-1; i++)
        {
            temp = p;
            p=p->next;
        }
        temp->next = p->next;
    }
    deletedData = p->data;
    free(p);
    displayLinkedList(first);
    return deletedData;
}

int checkIfSortedLinkedList (struct Node *p)
{
    int min = INT_MIN;
    while (p!=NULL)
    {
        if(p->data < min)
        {
            return 0;
        }
        min = p->data;
        p = p->next;
    }
    return 1;
}

void SortLinkedList (struct Node *p)
{
    int temp;
    struct Node *q=NULL;
    while (p!=NULL)
    {
        q=p;
        p=p->next;
        if(q->data > p->data)
        {
            temp = q->data;
            q->data = p->data;
            p->data = temp;
        }
    }
    
}

void removeDuplicatesFromList (struct Node *p)
{
    // The list must be sorted for this to work properly
    struct Node *q=p->next;
    while (q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q=p->next;
        }
        
    }
}
