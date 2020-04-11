// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

void addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        
        addPolynomial(poly1,poly2);
        
        cout<<endl;
       
    }

}
// } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
Node* merge(Node* head1,Node* head2)
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
    while(head1 && head2)
    {
        if(head1->pow > head2->pow)
        {
            result = head1;
            result->next = merge(head1->next,head2);
        }
        else
        {
            result = head2;
            result->next = merge(head1,head2->next);
        }
        
    }
    return result;

}

Node* mergeSort(Node* head)
{
    cout<<head->coeff<<" "<<head->pow<<endl;
    if(head->next)
    {
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
    	
    	Node* left = mergeSort(head);
    	Node* right = mergeSort(secondHalf);
    	
    	Node* result = merge(left,right);
    	return result;
    }
    return head;
}


void addPolynomial(Node *p1, Node *p2)
{
    //Your code here
    p1 = mergeSort(p1);
    p2 = mergeSort(p2);
    cout<<"sorted"<<endl;

    while(p1 && p2)
    {
        
        if(p1->pow == p2->pow)
        {
            if(!p1->next && !p2->next)
            {
                cout<<p1->coeff+p2->coeff<<"x^"<<p1->pow;
            }
            else
            {
                cout<<p1->coeff+p2->coeff<<"x^"<<p1->pow<<" + ";
            }
            
            p1 = p1->next;
            p2 = p2->next;
            continue;
        }
       if(p1->pow > p2->pow)
       {
           cout<<p1->coeff<<"x^"<<p1->pow<<" + ";
           
           
           p1 = p1->next;
           continue;
       }
       if(p1->pow < p2->pow)
       {
           
           cout<<p2->coeff<<"x^"<<p2->pow<<" + ";
           p2 = p2->next;
       }
    }
    
    while(p1)
    {
        if(!p1->next)
        {
            cout<<p1->coeff<<"x^"<<p1->pow;
        }
        else
        {
            cout<<p1->coeff<<"x^"<<p1->pow<<" + ";
        }
        p1 = p1->next;
    }
    
    while(p2)
    {
        if(!p2->next)
        {
            cout<<p2->coeff<<"x^"<<p2->pow;   
        }
        else
        {
            cout<<p2->coeff<<"x^"<<p2->pow<<" + ";
        }
        p2 = p2->next;
    }
    
    
    
}
