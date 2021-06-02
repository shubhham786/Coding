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

  int height(TreeNode* root)
  {
      return root==NULL?-1:max(height(root->left),height(root->right))+1;

  }

  int size(TreeNode* root)
  {
      return root==NULL?0:size(root->left)+size(root->right)+1;

  }

 int maximum(TreeNode* root)
  {
      return root==NULL?-(int)1e9:max(max(maximum(root->left),maximum(root->right)),root->val);

  }  

  bool find(TreeNode* root,int data)
  {
      if(root==NULL) return false;

      if(root->val==data)return true;

      return find(root->left,data) ||find(root->right,data); //ek baar data mil gaya dusra call nahi lagega

  }

     vector<TreeNode*>* root_to_node_path(TreeNode* root,int data)
  {
      if(root==NULL)
      {
          //vector<TreeNode*>*ans=new vector<TreeNode*>();
          return NULL;
      }

      if(root->val==data)
      {
          vector<TreeNode*>*ans=new vector<TreeNode*>();;
          ans->push_back(root);
          return ans;
      }

     vector<TreeNode*>* a=root_to_node_path(root->left,data);

        if(a!=NULL)
        {
            //cout<<"*";
            a->push_back(root);
            return a;
        }

        vector<TreeNode*>* b=root_to_node_path(root->right,data);

        if(b!=NULL)
        {
            b->push_back(root);
            return b;
        }

        else{
            return NULL;
        }
     

  }
//leetcode 236
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
          return NULL;

        vector<TreeNode*>* a=root_to_node_path(root,p->val);
        //cout<<q->val<<endl;
        vector<TreeNode*>* b=root_to_node_path(root,q->val);

        if(a==NULL ||b==NULL)
            return NULL;
     
        int i=a->size()-1;
        int j=b->size()-1;
      
        while(i>=0 && j>=0 && a->at(i)->val==b->at(j)->val)
        {
            i--;
            j--;
        }

        return a->at(i+1);
    }

    //leetcode 863
   
      vector<int>ans;
    
    
    void distance_k(TreeNode* root,int k)
    {
           if(root==NULL)
               return;
        
        if(k==0)
            ans.push_back(root->val);
        
        distance_k(root->left,k-1);
        distance_k(root->right,k-1);
    }
    int distance_k_all(TreeNode* root, TreeNode* target, int k)
    {
        if(root==NULL)
            return -1;
        
        if(root==target){
            distance_k(root,k);
            return 0;
        }
        
        int z=distance_k_all(root->left,target,k);
        
        if(z!=-1)
        {
              if(z+1==k){
                  ans.push_back(root->val);
               return -1;   
              }  
             distance_k(root->right,k-z-2);
            
            return z+1;
        }
        //else if{
          int l=distance_k_all(root->right,target,k);
           
    if(l!=-1)
        {
              if(l+1==k){
                  ans.push_back(root->val);
               return -1;   
              }  
           
        distance_k(root->left,k-l-2);
            
            return l+1;
        } 
        else
         return -1;       
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        
        int z=distance_k_all(root,target,k);
        return ans;
        
    }

    //leetcode 543
    // diameter of binary diameter
     pair<int,int> diameter_01(TreeNode* root)
    {
        if(root==NULL)
        {
            pair<int,int> a;
            a.first= -1;
            a.second= -1;
            return a;
        }
        
        pair<int,int> a=diameter_01(root->left);
        pair<int,int> b=diameter_01(root->right);
        
        pair<int,int> c;
        
        c.first=max(a.first,max(b.first,a.second+b.second+2));
        c.second=max(a.second,b.second)+1;
        
        return c;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        pair<int,int> l=diameter_01(root);
        
        return l.first;
    }
//better way
     int dia=0;
    
    int diameter(TreeNode* root)
    {
        if(root==NULL)
        {
            
            return -1;
        }
        
        int a=diameter(root->left);
         int b=diameter(root->right);
        
        
        
        dia=max(dia,a+b+2);
       int c=max(a,b)+1;
        
        return c;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int l=diameter(root);
        
        return dia;
    }
    

    // leetcode 112
     bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
        
        
        if(!root->left && !root->right)
        {
          return  targetSum-root->val==0?true:false;
        }
        
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }

    //leetcode 113
      void path_sum(TreeNode* root, vector<vector<int>>&res,vector<int>&sum_till_now,int tar)
    {
        if(root==NULL)
            return;

            if(!root->left && !root->right)
            {
                if(tar-root->val==0)
                {
                    sum_till_now.push_back(root->val);
                    res.push_back(sum_till_now);
                    sum_till_now.pop_back();
                }

                return;
            }

            sum_till_now.push_back(root->val);
            path_sum(root->left,res,sum_till_now,tar-root->val);
            path_sum(root->right,res,sum_till_now,tar-root->val);
            sum_till_now.pop_back();
    }
     vector<vector<int>> pathSum(TreeNode* root, int tar) {
        
        vector<vector<int>>res;
        vector<int>sum_till_now;

        path_sum(root,res,sum_till_now,tar);
        
        return res;
    }
    //https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#
    int max1=-(int)1e9;
    int maxPathSum1(TreeNode* root)
    {
        if(root==NULL)
           return 0;
           
           //if(!root->left)
         int l=maxPathSum1(root->left);
         int r=maxPathSum1(root->right);
         
         if(root->left && root->right){
            // cout<<"x"<<" ";
            // cout<<root->data<<" ";
            max1=max(max1,l+r+root->val);
            //cout<<max1<<endl;
            
            
            return max(l,r)+root->val;
         }
         
         return root->left==NULL?r+root->val:l+root->val;
         
        //return max(l,r)+root->data;            
    }
    int maxPathSum(TreeNode* root)
    {
        int l=maxPathSum1(root);
        return max1;
    }

    //lletcode 124
     //very good
     //method 1
      pair<int,int>maxsum(TreeNode* root)
    {
        if(root==nullptr)
        {
            pair<int,int>ans;
            ans.first=-(int)1e9;
            ans.second=-(int)1e9;
            
            return ans;
            
        }
        
        
        auto l=maxsum(root->left);
        auto r=maxsum(root->right);
        
        pair<int,int>ans;
        //return ke second value ko phle update karte hai
        int z=max(l.second,r.second)+root->val;
        
        ans.second=max(z,root->val);
        
        ans.first=max(max(l.first,r.first),max(z,max(l.second+r.second+root->val,root->val)));
        
        return ans;
    }
    int maxPathSum(TreeNode* root)
    {
        pair<int,int>ans=maxsum(root);
        
        return ans.first;
    } 
    //method 2
    int max_sum=-(int)1e9;
    int max_path_sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
       // if(!root->left && !root->right)
         //   return root->val;
        
        int l=max_path_sum(root->left);
        int r=max_path_sum(root->right);
        
     //   max_sum=max(max_sum,max(l+r+root->val,max(l,max(r,max(l+root->val,)))));
        
      //  return max(l,r)+root->val;
        // yahan pe bhut dimag chaiye
        int maxsumtillroot=max(l,r)+root->val;
        
        max_sum=max(max(max_sum,maxsumtillroot),max(l+r+root->val,root->val));
        
        return max(maxsumtillroot,root->val);
    }
    int maxPathSum(TreeNode* root) {
        //if(root==NULL)
          //  return 0;
        
        //if(!root->left && !root->right)
          //   return root->val;
        
        
        int l=max_path_sum(root);
        
        return max_sum;
    }

    //LEETCODE 98
    //method 1
      bool isvalidBST1(TreeNode* root ,long max1,long min1)
    {
        if(root==NULL)
             return true;
        
        return isvalidBST1(root->left,root->val,min1) && isvalidBST1(root->right,max1,root->val) &&   root->val<max1 && root->val>min1;
    }
    bool isValidBST(TreeNode* root) {
        
        return isvalidBST1(root,LLONG_MAX,LLONG_MIN);
    }
     // method 2
     // inorder 
    long max1=-(long)1e13;
     bool isValidBST(TreeNode* root)
     {
         if(root==NULL)
             return true;
         
         if(!isValidBST(root->left))
             return false;
         
         if(root->val<=max1)
             return false;
         
         max1=root->val;
         
         if(!isValidBST(root->right))
              return false;
         
         return true;
         
     }
     //leetcode 437
     //method 1 --->using the concept of subrray with sum k
    //leetcode--560
    unordered_map<int,int>map;
    int ans=0;
   // map[0]=1;
    void pathSum1(TreeNode* root, int tar,int sumtill_now)
    {
        if(root==NULL)
            return;
        
        sumtill_now+=root->val;
        
        if(map.find(sumtill_now-tar)!=map.end())ans=ans + map[sumtill_now-tar];
        
        map[sumtill_now]++;
        //cout<<root->val<<" "<<sumtill_now<<endl;
        pathSum1(root->left,tar,sumtill_now);
        pathSum1(root->right,tar,sumtill_now);
        
        if(map[sumtill_now]==1)
            map.erase(sumtill_now);
        else
        {
            map[sumtill_now]--;
        }
        sumtill_now-=root->val;
         //cout<<root->val<<" "<<sumtill_now<<endl;
        //if(map.find(sumtill_now-tar)!=map.end())    
    }
    
    int pathSum(TreeNode* root, int tar) {
     map[0]=1;
        pathSum1(root,tar,0);
        
        return ans;
    }

      //method-2 using dfs
    int ans=0;
    void dfs(TreeNode* root, int tar)
    {
        if(root==NULL)
            return ;
        
        if(tar-root->val==0)
            ans++;
        
        dfs(root->left,tar-root->val);
        dfs(root->right,tar-root->val);
    }
        int pathSum(TreeNode* root, int tar){
            
            if(root)
            {
                dfs(root,tar);
                pathSum(root->left,tar);
                pathSum(root->right,tar);
            }
            
            return ans;
        }

//leetcode 99
// think how will you in solve in sorted array having 2 misplaced item
  //very good question
    TreeNode* a=NULL;
        TreeNode* b=NULL;
        TreeNode* prev=NULL;
    
    bool recoverTree1(TreeNode* root)
    {
        if(root==NULL)
            return true;
        
        if(!recoverTree1(root->left))return false;
        
        //kaam yahan hoga
        if(prev!=NULL && prev->val>root->val)
        {
            b=root;
            if(a==NULL)a=prev;
            
            else
              return false;
            
        }
        prev=root;
        if(!recoverTree1(root->right))return false;
        
        return true;
    }
    void recoverTree(TreeNode* root) {
        
        if(root==NULL)
            return;
        recoverTree1(root);
        if(a!=NULL)
        {
            int temp=a->val;
            a->val=b->val;
            b->val=temp;
        }
        
        return ;
    }

    //leetcode 968
     //-1: camera is required
    //0: i am covered
    //1: i am camera
    int camera=0;
    
    
    int minCamera_Cover(TreeNode* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        
        int left=minCamera_Cover(node->left);
        int right=minCamera_Cover(node->right);
        
        
        if(left==-1 || right==-1)
        {
            camera++;
            
            return 1;
        }
        
        if(left==1 || right==1)
        {
            return 0;
        }
        
        return -1;
    }
    
    
    
    int minCameraCover(TreeNode* root) {
        
        int ans=minCamera_Cover(root);
        
         ans==-1 ? camera++ : camera;
        
         return camera;
    }

    //leetcode 337
       //arr[0]=maximum amount generated by robbing house
    //arr[1]=maximum amount generated by not robbing house
    
    vector<int>rob1(TreeNode* root)
    {
        if(root==NULL)
        {
            vector<int>ans(2,0);
            
            
            return ans;
            
        }
        
        
        vector<int>left=rob1(root->left);
        vector<int>right=rob1(root->right);
        
        vector<int>ans(2,0);
        
        ans[0]=left[1]+right[1]+root->val;
        ans[1]=max(left[0],left[1])+max(right[0],right[1]);
        
        
        return ans;
    }
    int rob(TreeNode* root) {
        
        if(root==NULL)
            return 0;
            
            vector<int>ans=rob1(root);
        
        
          return max(ans[0],ans[1]);
    }

    //leetcode 1372
     //arr[0]=longest zig zag path fron left tree
    //arr[1]=longest zig zag path fron right tree
    int max_ans=0;
    
    vector<int> zigzag(TreeNode* root)
    {
        if(root==NULL)
        {
            return {-1,-1};
        }
        
        vector<int>left=zigzag(root->left);
        vector<int>right=zigzag(root->right);
        
          vector<int>ans(2,0);
        
          ans[0]=left[1]+1;
         ans[1]=right[0]+1;
        
          max_ans=max(max_ans,max(ans[0],ans[1]));
        
        
        return ans;
        
    }
    int longestZigZag(TreeNode* root) {
        
        if(root==NULL)
             return 0;
        
         vector<int>ans= zigzag(root);
        
        return max_ans;
    }

    //leetcode 230
     int count=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
        {
            return 0;
        }
        
        
        int l=kthSmallest(root->left,k);
        count++;
        if(count==k)
        {
            return root->val;
        }
        
        int r=kthSmallest(root->right,k);
         
        
        if(l>0)
        {
            return l;
        }
        else if(r>0)
        {
            return r;
        }
        else
        {
            return 0;
        }
        
    }
    //leetcode 653
     vector<int>inorder;
    
    void inor(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        inor(root->left);
        inorder.push_back(root->val);
         inor(root->right);
        
    }
    bool target(int k)
    {
        int s=0;
        int e=inorder.size()-1;
        
         while(s<e)
         {
             if(inorder[s]+inorder[e]==k)
                 return true;
             else if(inorder[s]+inorder[e]>k)
                 e--;
             else
                 s++;
         }
        
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
     
         inor(root);
        
        return target(k);
             
        
    }

    //leetcode 653
    void insertAllLeft(stack<TreeNode *> &st, TreeNode *node)
{
    while (node != nullptr)
    {
        st.push(node);
        node = node->left;
    }
}
void insertAllRight(stack<TreeNode *> &st, TreeNode *node)
{
    while (node != nullptr)
    {
        st.push(node);
        node = node->right;
    }
}

bool findTarget(TreeNode *root, int k)
{
    if (root == nullptr)
        return false;

    stack<TreeNode *> lst;
    stack<TreeNode *> rst;

    insertAllLeft(lst, root);
    insertAllRight(rst, root);

    while (lst.top()->val < rst.top()->val)
    {
        int sum = lst.top()->val + rst.top()->val;
        if (sum == k)
            return true;
        else if (sum < k)
        {
            TreeNode *node = lst.top();
            lst.pop();
            insertAllLeft(lst, node->right);
        }
        else
        {
            TreeNode *node = rst.top();
            rst.pop();
            insertAllRight(rst, node->left);
        }
    }

    return false;
//leetcode 662
 typedef unsigned int uint;
    int widthOfBinaryTree(TreeNode* root) {
        
        
        queue<pair<TreeNode*,uint>>a;
        if(root==NULL)
        {
            return 0;
        }
        a.push(make_pair(root,1));
        uint current=0;
        
         
          while(a.size()!=0)
          {
              int size=a.size();
              
             
               uint min1=UINT_MAX;
                uint max1=0;
                 while(size-->0)
                 {
                     
                                                 
                      pair<TreeNode*,uint> front=a.front();
                      a.pop();
                      if(min1>front.second)
                           min1=front.second;
                    // min1= min(min1,);
                    // cout<<min1; 
                    // max1=max(max1,front.second);
                      if(max1<front.second)
                           max1=front.second;
                    // cout<<max1<<endl;
                      if(front.first->left!=NULL)
                      {
                          a.push(make_pair(front.first->left,front.second*2));
                         
                      }
                     
                     if(front.first->right!=NULL)
                     {
                        a.push(make_pair(front.first->right,front.second*2+1));
                     }

                       
                 }
              
              if(max1-min1+1 >current)
                  current=max1-min1+1;
              
          }
        
        return current;
    }