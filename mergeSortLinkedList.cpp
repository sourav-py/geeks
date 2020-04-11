// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


// Function to merge two DLLs
struct Node* merge(struct Node* head1,struct Node* head2)
{
    Node* result = NULL;
    if(!head1)
    {
        return head2;
    }
    if(!head2)
    {
        return head1;
    }
    
    if(head1->data < head2->data)
    {
        result = head1;
        result->prev = NULL;
        Node* recieve = merge(head1->next,head2);
        result->next = recieve;
        recieve->prev = result;
    }
    else
    {
        result = head2;
        result->prev = NULL;
        Node* recieve =  merge(head1,head2->next);
        result->next = recieve;
        recieve->prev = result;
    }
    return result;
}


struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if(head->next)
	{
    	//find middle
        Node* fast = head;
    	Node* slow = head;
    	while(true)
    	{
            if(!fast)
            {
                break;
            }
            if(!fast->next)
            {
                break;
            }

            if(!(fast->next)->next)
            {
                break;
            }


    	    fast = (fast->next)->next;
    	    slow = slow->next;
            
            
    	}
    	Node* secondHalf = slow->next;
        slow->next = NULL;
    	
    	Node* left = sortDoubly(head);
    	Node* right = sortDoubly(secondHalf);
    	
    	Node* result = merge(left,right);
    	return result;
	}
	return head;
	
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends