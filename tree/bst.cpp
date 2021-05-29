 #include<iostream>
 #include<bits/stdc++.h>
 #include<vector>
 #include<algorithm>
 #include<unordered_map>
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