// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}



vector<int> merge(Node *root1,Node *root2);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends
/* The structure of Node is
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/

/*You are required to complete below method */

void inOrder(Node* root,vector<int>* v)
{
    if(root)
    {
        inOrder(root->left,v);
        (*v).push_back(root->data);
        inOrder(root->right,v);
    }
}

vector<int> merge(vector<int> v1,vector<int>v2)
{
    vector<int> result;
    int i=0;
    int j=0;
    int k=0;
    int size1 = v1.size();
    int size2 = v2.size();
    while(i<size1 && j<size2)
    {
        if(v1[i]<v2[j])
        {
            result.push_back(v1[i]);
            i++;
            k++;
        }
        else
        {
            result.push_back(v2[j]);
            j++;
            k++;
        }
    }
    
    //left over elements
    while(i<size1)
    {
        result.push_back(v1[i]);
        i++;
        k++;
    }
    while(j<size2)
    {
        result.push_back(v2[j]);
        j++;
        k++;
    }
    return result;
}

vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
   vector<int> v1;
   vector<int> v2;
   vector<int> v3;
   inOrder(root1,&v1);
   inOrder(root2,&v2);
   v3 = merge(v1,v2);
   return v3;
   
}

