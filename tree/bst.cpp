 #include<iostream>
 #include<bits/stdc++.h>
 #include<vector>
 #include<algorithm>
 #include<unordered_map>
 #include<list>
 using namespace std;

 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int size(TreeNode* root)
  {
      return root==NULL?0:size(root->left)+size(root->right)+1;

  }

int max_ele(TreeNode* root){
      
      TreeNode* curr=root;

      while(curr->right!=NULL)
      {
          curr=curr->right;
      }

      return curr->val;
}

int min_ele(TreeNode* root){
      
      TreeNode* curr=root;

      while(curr->left!=NULL)
      {
          curr=curr->left;
      }

      return curr->val;
}

bool find_data(TreeNode* root,int data)
{
    TreeNode* curr=root;
      while(curr!=NULL)
      {
          if(curr->val==data)
              return true;

          else if(curr->val >data)
                curr=curr->left;

           else
             curr=curr->right;         


      }

      return false;
}

bool find_data_02(TreeNode* root,int data)
{
    //TreeNode* curr=root;
      if(root==NULL)
           return false; 
      
    
          if(root->val==data)
              return true;

          else if(root->val >data)
              return find_data_02(root->left,data);                         // curr=curr->left;

           else
             return find_data_02(root->right,data);           //curr=curr->right;         


      

     // return false;
}

TreeNode* insert_bst(TreeNode* root,int data)
{

    if(root==nullptr)
       return new TreeNode(data);

       if(root->val>data)
        root->left=insert_bst(root->left,data);

       else
        root->right=insert_bst(root->right,data);

        return root;

}

TreeNode* insert_bst(TreeNode* root,int data)
{

    if(root==nullptr)
       return new TreeNode(data);

       if(root->val>data)
        root->left=insert_bst(root->left,data);

       else
        root->right=insert_bst(root->right,data);

        return root;
         
}

TreeNode* insert_bst(TreeNode* root,int data)
{
    
    TreeNode* curr=root;
    TreeNode* prev=NULL;

       while(curr!=NULL)
       {
           prev=curr;

           if(curr->val>data)
              curr=curr->left;
           else
               curr=curr->right;   
       }


         TreeNode* node=new TreeNode(data);

            if(prev==NULL)
                return node;
            else
            {
                if(prev->val>data)
                   prev->left=node;

                else 
                   prev->right=node;   
            }      
       
    
         return root;

}
//leetcode 701
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL)
             return new TreeNode(val);
        
        
        if(root->val>val)
            root->left=insertIntoBST(root->left,val);
        else
             root->right=insertIntoBST(root->right,val);
        
        return root;
    }

TreeNode* delete_bst(TreeNode* root,int data)
{
    if(root==NULL)
        return NULL;

        if(root->val>data)
           root->left=delete_bst(root->left,data);

        else if(root->val<data)
           root->right=delete_bst(root->right,data);

        else
        {
              if(root->right==NULL || root->left==NULL)
                   return root->left != NULL ? root->left : root->right;

                   int maxvalue=max_ele(root->left);

                   root->val=maxvalue;

                   root->left=delete_bst(root->left,maxvalue);
        }      


        return root;
}

//leetcode 450
 int max_ele(TreeNode* root)
    {
        TreeNode* curr=root;
        
        while(curr->right!=NULL)
            curr=curr->right;
        
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
             return NULL;
        
        if(root->val>key)
            root->left=deleteNode(root->left,key);
        else if(root->val<key)
            root->right=deleteNode(root->right,key);
        else
        {
            if((!root->left) || (!root->right))
                return !root->left?root->right:root->left;
            
            int maxval=max_ele(root->left);
            
            //swap(maxval,root->val
            root->val=maxval;
            
            root->left=deleteNode(root->left,maxval);
        }
        
        return root;
        
    }
//leetcode 235
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
    TreeNode* curr=root;
      while(curr!=NULL)
      {
          if(curr->val >p->val && curr->val>q->val)
              curr=curr->left;

          else if(curr->val <p->val && curr->val<q->val)
                curr=curr->right;

           else
             return curr;         


      }

      return NULL;
}
//leetcode 108
 TreeNode* sortedArrayToBST(vector<int>& nums,int si,int ei)
     {
           if(si>ei)
               return NULL;
         
         int mid=(si+ei)/2;
         // cout<<mid<<endl;
           TreeNode* root=new TreeNode(nums[mid]);
         
           root->left=sortedArrayToBST(nums,si,mid-1);
           
         root->right=sortedArrayToBST(nums,mid+1,ei);
         
         return root;
                
     }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        return sortedArrayToBST(nums,0,nums.size()-1);
        
    }

void pred_succ_in_Bst(TreeNode* root,int data)
{   TreeNode* curr=root;
    TreeNode* pred=NULL;
    TreeNode* succ=NULL;
      while(curr!=NULL)
      {
          if(curr->val==data)
           {
                 if(curr->left!=NULL)
                  {
                      pred=curr->left;
                      while(pred->right!=NULL)
                        pred=pred->right;
                  }
                if(curr->right!=NULL)
                 {
                     succ=curr->right;
                     while(succ->left!=NULL)
                      succ=succ->left;
                 }
               break;  
           }
          else if(curr->val>data){
              succ=curr;
             curr=curr->left;
          }
          else{
            pred=curr;
           curr=curr->right; 
          }  
      }
}


//leetcode 173 
class BSTIterator {
public:
   // TreeNode* curr=NULL;
    //TreeNode* prev=NULL;
    
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
       add(root); 
    }
    
    void add(TreeNode* node)
    {
        if(node==NULL)
            return;
        
        TreeNode* curr=node;
        
        while(curr!=NULL)
        {    st.push(curr);
            curr=curr->left;
        } 
        
    }
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        add(curr->right);
          
        return curr->val;
    }
    
    bool hasNext() {
        return st.size()!=0;
    }
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        
        return ans[cur++];
    }
    
    bool hasNext() {
        return cur<ans.size();   
    }
    
    private:
       vector<int>ans;
       
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
         ans.push_back(root->val);
        inorder(root->right);
    }
    
    //int n=ans.size();
    int cur=0;
};


//leetcode 510
/*
p Node inorderSuccessor(Node node) {

        if (node->right != nullptr) {
            node = node->right;
            while (node->left != nullptr)
                node = node->left;

            return node;
        } else {
            while (node != nullptr) {
                if (node->parent != nullptr && node->parent->left == node) {
                    return node->parent;
                }
                node = node->parent;
            }

            return null;
        }
    }
 */ 

 //leetcode 1008
     int binarysearch(vector<int>&arr,int l,int s,int e)
    {
       // int s=0;
        //int e=l-1;
        
          while(s<=e)
          {
              int mid=(s+e)/2;
              
              if(arr[mid]==l)
                  return mid;
              else if(arr[mid]>l)
                  e=mid-1;
              else
                  s=mid+1;
          }
        
        return -1;
    }
    
    TreeNode* bstFrom_Preorder(vector<int>& pre,vector<int>& in,int si,int ei,int& i)
    {
        if(si>ei)
            return NULL;
        
      //  int l=binarysearch(preorder,in[])
        
        TreeNode* root=new TreeNode(pre[i]);
        
        //int l=binary
        int l=binarysearch(in,pre[i],si,ei);
        i++;
    
        root->left=bstFrom_Preorder(pre,in,si,l-1,i);
        
      root->right=bstFrom_Preorder(pre,in,l+1,ei,i);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        vector<int>in=pre;
        
        sort(in.begin(),in.end());
         int i=0;
        return bstFrom_Preorder(pre,in,0,in.size()-1,i);
    }

       
    //method-2
    int bst_idx=0;
    //lr->left range, rr->right range
    TreeNode* bstFromPreorder1(vector<int>& pre,int lr,int rr){
        if(bst_idx==pre.size() || pre[bst_idx]<lr || pre[bst_idx]>rr)
            return NULL;
        
        TreeNode* node=new TreeNode(pre[bst_idx++]);
        
        node->left=bstFromPreorder1(pre,lr,node->val);
        node->right=bstFromPreorder1(pre,node->val,rr);
        
        return node;
    }
  
     TreeNode* bstFromPreorder(vector<int>& pre){
         
         return bstFromPreorder1(pre,-(int)1e9,(int)1e9);
     }

     //https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1

     //bst from level order

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
//Function to construct the BST from its given level order traversal.
class pair2{

public:
    Node* par=NULL;

    int l_min=-(int)1e9;
    int r_max=(int)1e9;

    pair2()
    {

    }

    pair2(Node* par,int l_min,int r_max)
    {
        this->par=par;
        this->l_min=l_min;
        this->r_max=r_max;
    }
};
Node* constructBst(int arr[], int n)
{
    // Code here
    list<pair2>que;
      
      pair2 l;
        int idx=0;
      que.push_back(l);
      Node* root=NULL;
         while(que.size()!=0 && idx<n)
         {
             pair2 l1=que.front();
              que.pop_front();
             if(arr[idx]<l1.l_min || arr[idx]>l1.r_max)continue;

           Node * curr=new Node(arr[idx++]);
            if(l1.par==NULL)
            {
                root=curr;

            }
            else
            {
                if(curr->data<l1.par->data)
                   l1.par->left=curr;
                else
                   l1.par->right=curr;   
            }


            que.push_back(pair2(curr,l1.l_min,curr->data));
            que.push_back(pair2(curr,curr->data,l1.r_max));

            

         }
         

    return root;    
    
}

//https://practice.geeksforgeeks.org/problems/construct-tree-from-inorder-and-levelorder/1#

// bt tree from level order and inorder

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
   // cout<<n<<endl;
   //cout<<iStart<<" "<<iEnd<<endl;
    if(iStart>iEnd)return NULL;
    //return new Node(levelOrder[0]);
    
    Node * root=new Node(levelOrder[0]);
    if(iStart==iEnd)return root;
    
    int idx=iStart;
      while(inorder[idx]!=levelOrder[0])
         idx++;
         
         int ttl=idx-iStart;
        // cout<<ttl<<" ";
         //cout<<root->key<<" "<<idx<<endl;
         int level_left[ttl];
           
           int level_right[iEnd-ttl];
           //cout<<iEnd-ttl<<" "<<endl;
          unordered_map<int,int>map;
          
          for(int i=iStart;i<idx;i++)
          {
              map[inorder[i]]++;
          }
          int idx_l=0;
          int idx_r=0;
          for(int i=1;i<n;i++)
          {
              if(map.find(levelOrder[i])!=map.end())
                 level_left[idx_l++]=levelOrder[i];
              else
                 level_right[idx_r++]=levelOrder[i];
          }
          
          //cout<<endl;
         root->left=buildTree(inorder,level_left,iStart,idx-1,ttl);
         root->right=buildTree(inorder,level_right,idx+1,iEnd,iEnd-ttl);
         
         return root;
}

