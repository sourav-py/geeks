// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
#include <queue>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
int maxPalindrome(Node *head)
{
    //Finding length
    if(!head)
    {
        return 0;
    }
    int length = -1;
    Node* temp = head;
    vector<int> arr;
    
    while(temp)
    {
        arr.push_back(temp->data);
        length++;
        temp = temp->next;
    }
    
    vector<int> result;
    int start = 0;
    int end = length;
    while(start < length)
    {
        int s = start;
        int q = end;
        int count = 0;
        bool valid = false;
        while(arr[s] == arr[q])
        {
            count++;
            
            s++;
            q--;
            if(q<start)
            {
                valid = true;
                break;
            }
        }
        if(valid)
        {
            result.push_back(count);
            start++;
            end = length;
            continue;
        }
        else
        {
            end--;
            if(start == end || end == 0)
            {
                start++;
                end = length;
            }
        }
        
    }

    
    if(result.size())
    {
        return *max_element(result.begin(),result.end());

    }
    else
    {
        return 1;
    }

    
}