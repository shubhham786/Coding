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


vector<int> diagonal(Node *root);

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
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

    class vertical_pair{
        public:
          Node* node=nullptr;
          int h=0;

           vertical_pair(Node* node,int h)
           {
               this->node=node;
               this->h=h;
           }
    };
       void width(Node* root,int h,vector<int>&ans)
       {
           if(root==NULL)
            return;


            ans[0]=min(ans[0],h);
            ans[1]=max(ans[1],h);

            width(root->left,h-1,ans);
            width(root->right,h+1,ans);
       }
vector<int> diagonal(Node *root)
{
   if(root==NULL)
              return {}; 

   cout<<"10"<<endl;
              vector<int>minmax(2,0);

              width(root,0,minmax);
               cout<<-minmax[0]<<endl;
              int len=minmax[1]-minmax[0]+1;
             // vector<vector<int>>res(len);
               vector<int>res;
               
               vector<vector<int>>res1((-minmax[0])+1);
              queue<vertical_pair>que;

              que.push(vertical_pair(root,-minmax[0]));

              while(que.size()!=0)
              {
                  int size=que.size();
                   
                      while(size-->0)
                      {
                          vertical_pair rp=que.front();
                          que.pop();

                          res1[rp.h].push_back(rp.node->data);

                          if(rp.node->left)
                           que.push(vertical_pair(rp.node->left,rp.h-1));
                         
                          if(rp.node->right)
                           que.push(vertical_pair(rp.node->right,rp.h));

                      }
                      

              }
               
              for(int i=-minmax[0];i>=0;i--)
              {
                  for(int &i:res1[i])
                     res.push_back(i);
              }

              return res;

       

}
   
    


   // your code here
