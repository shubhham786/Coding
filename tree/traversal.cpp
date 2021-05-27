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

//leetcode 102
//level order traversal
 vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        if(root==NULL)
            return ans;
        
        queue<TreeNode*>que;
        
        que.push(root);
        
        
            while(que.size()!=0)
            {
                int size=que.size();
                vector<int>ans1;
                
                
                while(size-->0){
                    TreeNode* front=que.front();
                    
                    que.pop();
                    
                    ans1.push_back(front->val);
                    
                    if(front->left)
                        que.push(front->left);
                    
                    if(front->right)
                         que.push(front->right);
                    
                }
                
                
                ans.push_back(ans1);
            }
        
        return ans;
    }
    
    //leetcode 199
    //right view
     vector<int> rightSideView(TreeNode* root) {
        
        
        if(root==NULL)
            return  {};
        
        vector<int>ans;
        
        queue<TreeNode*>que;
        
        que.push(root);
        
          while(que.size()!=0)
          {
              int size=que.size();
              
               while(size-->0)
               {
                   TreeNode* front=que.front();
                    que.pop();
                   
                   if(size==0)
                       ans.push_back(front->val);
                   
                   if(front->left)
                       que.push(front->left);
                   
                   if(front->right)
                       que.push(front->right);
               }
               
          }
        
        return ans;
        
    }
    vector<int> rightSideView_02(TreeNode* root) {
        
        
        if(root==NULL)
            return  {};
        
        vector<int>ans;
        
        queue<TreeNode*>que;
        
        que.push(root);
        
          while(que.size()!=0)
          {
              int size=que.size();
               ans.push_back(que.front()->val);
               while(size-->0)
               {
                   TreeNode* front=que.front();
                    que.pop();
                   
                   //if(size==0)
                      
                   
                   if(front->right)
                       que.push(front->right);

                   if(front->left)
                       que.push(front->left);
                   
                   
               }
               
          }
        
        return ans;
        
    }

    //left view
     vector<int> leftSideView(TreeNode* root) {
        
        
        if(root==NULL)
            return  {};
        
        vector<int>ans;
        
        queue<TreeNode*>que;
        
        que.push(root);
        
          while(que.size()!=0)
          {
              int size=que.size();
               ans.push_back(que.front()->val);
               while(size-->0)
               {
                   TreeNode* front=que.front();
                    que.pop();
                   
                   //if(size==0)

                     if(front->left)
                       que.push(front->left);  
                   
                   if(front->right)
                       que.push(front->right);

                  
                   
                   
               }
               
          }
        
        return ans;
        
    }

    //vertical order traversal
    // method -1
    class vertical_pair{
        public:
          TreeNode* node=nullptr;
          int h=0;

           vertical_pair(TreeNode* node,int h)
           {
               this->node=node;
               this->h=h;
           }
    };

     vector<vector<int>> verticalTraversal(TreeNode* root) {
            
            if(root==NULL)
               return {{}};

               queue<vertical_pair>que;

               que.push(vertical_pair(root,0));
               
               unordered_map<int,vector<int>>map;

               int minhl=0,maxhl=0;

               while(que.size()!=0)
               {
                   int size=que.size();

                     while(size-->0)
                     {
                         vertical_pair rp=que.front();

                         que.pop();

                         map[rp.h].push_back(rp.node->val);

                         minhl=min(minhl,rp.h);
                         maxhl=max(maxhl,rp.h);

                         if(rp.node->left)
                          que.push(vertical_pair(rp.node->left,rp.h-1));

                        if(rp.node->right)
                          que.push(vertical_pair(rp.node->right,rp.h+1));
                          


                     }
               }

            vector<vector<int>>ans;

            while(minhl<=maxhl)
            {
                 ans.push_back(map[minhl++]);
            }

            return ans;
    }
      
       //method-2

       void width(TreeNode* root,int h,vector<int>&ans)
       {
           if(root==NULL)
            return;


            ans[0]=min(ans[0],h);
            ans[1]=max(ans[1],h);

            width(root->left,h-1,ans);
            width(root->right,h+1,ans);
       }

       vector<vector<int>> verticalTraversal(TreeNode* root)
       {
            if(root==NULL)
              return {{}};


              vector<int>minmax(2,0);

              width(root,0,minmax);

              int len=minmax[1]-minmax[0]+1;
              vector<vector<int>>res(len);
              queue<vertical_pair>que;

              que.push(vertical_pair(root,-minmax[0]));

              while(que.size()!=0)
              {
                  int size=que.size();
                   
                      while(size-->0)
                      {
                          vertical_pair rp=que.front();
                          que.pop();

                          res[rp.h].push_back(rp.node->val);

                          if(rp.node->left)
                           que.push(vertical_pair(rp.node->left,rp.h-1));
                         
                          if(rp.node->right)
                           que.push(vertical_pair(rp.node->right,rp.h+1));

                      }
                      

              }

              return res;


       }
       // vertical sum

       vector<int> verticalsum(TreeNode* root)
       {
           if(root==NULL)
              return {};


              vector<int>minmax(2,0);

              width(root,0,minmax);

              int len=minmax[1]-minmax[0]+1;
             // vector<vector<int>>res(len);
               vector<int>res(len);
              queue<vertical_pair>que;

              que.push(vertical_pair(root,-minmax[0]));

              while(que.size()!=0)
              {
                  int size=que.size();
                   
                      while(size-->0)
                      {
                          vertical_pair rp=que.front();
                          que.pop();

                          res[rp.h]+=rp.node->val;

                          if(rp.node->left)
                           que.push(vertical_pair(rp.node->left,rp.h-1));
                         
                          if(rp.node->right)
                           que.push(vertical_pair(rp.node->right,rp.h+1));

                      }
                      

              }

              return res;

       }
     
     // bootom view
     //https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
      vector<int> bottomview(TreeNode* root)
       {
           if(root==NULL)
              return {};


              vector<int>minmax(2,0);

              width(root,0,minmax);

              int len=minmax[1]-minmax[0]+1;
             // vector<vector<int>>res(len);
               vector<int>res(len);
              queue<vertical_pair>que;

              que.push(vertical_pair(root,-minmax[0]));

              while(que.size()!=0)
              {
                  int size=que.size();
                   
                      while(size-->0)
                      {
                          vertical_pair rp=que.front();
                          que.pop();

                          res[rp.h]=rp.node->val;

                          if(rp.node->left)
                           que.push(vertical_pair(rp.node->left,rp.h-1));
                         
                          if(rp.node->right)
                           que.push(vertical_pair(rp.node->right,rp.h+1));

                      }
                      

              }

              return res;

       }

//top view
//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
vector<int> topview(TreeNode* root)
       {
           if(root==NULL)
              return {};


              vector<int>minmax(2,0);

              width(root,0,minmax);

              int len=minmax[1]-minmax[0]+1;
             // vector<vector<int>>res(len);
               vector<int>res(len,-1);
              queue<vertical_pair>que;

              que.push(vertical_pair(root,-minmax[0]));

              while(que.size()!=0)
              {
                  int size=que.size();
                   
                      while(size-->0)
                      {
                          vertical_pair rp=que.front();
                          que.pop();

                          if(res[rp.h]==-1)res[rp.h]=rp.node->val;

                          if(rp.node->left)
                           que.push(vertical_pair(rp.node->left,rp.h-1));
                         
                          if(rp.node->right)
                           que.push(vertical_pair(rp.node->right,rp.h+1));

                      }
                      

              }

              return res;

       }
       //diagonal view 
       //
       class vertical_pair{
        public:
          TreeNode* node=nullptr;
          int h=0;

           vertical_pair(TreeNode* node,int h)
           {
               this->node=node;
               this->h=h;
           }
    };

     vector<int> diagnol_view(TreeNode* root) {
            
            if(root==NULL)
               return {};

               queue<vertical_pair>que;

               que.push(vertical_pair(root,0));
               
               unordered_map<int,vector<int>>map;

               int minhl=0;

               while(que.size()!=0)
               {
                   int size=que.size();

                     while(size-->0)
                     {
                         vertical_pair rp=que.front();

                         que.pop();

                         map[rp.h].push_back(rp.node->val);

                         minhl=min(minhl,rp.h);
                         //maxhl=max(maxhl,rp.h);

                         if(rp.node->left)
                          que.push(vertical_pair(rp.node->left,rp.h-1));

                        if(rp.node->right)
                          que.push(vertical_pair(rp.node->right,rp.h));
                          


                     }
               }

            vector<int>ans;

            while(minhl<=0)
            {
                 //ans.push_back(map[minhl++]);
                 for(int &i:map[minhl++])
                    ans.push_back(i);
            }

            return ans;
    }

      //vertical order traversal
      // leetcode 987
     class vertical_tri{
        public:
          TreeNode* node=nullptr;
          int c=0;
          int r=0;
           vertical_tri(TreeNode* node,int c,int r)
           {
               this->node=node;
               this->c=c;
               this->r=r;
           }
};

class comp{

    public:
       
          bool operator()(const vertical_tri&  a,const vertical_tri&  b)const{

              if(a.r!=b.r)
                  return a.r >b.r; 
                  
              return a.node->val >b.node->val;
          }
};
     vector<vector<int>> verticalTraversal(TreeNode* root) {
            
            if(root==NULL)
               return {{}};

               priority_queue<vertical_tri,vector<vertical_tri>,comp>que;

               que.push(vertical_tri(root,0,0));
               
               unordered_map<int,vector<int>>map;

               int minhl=0,maxhl=0;

               while(que.size()!=0)
               {
                   int size=que.size();

                     while(size-->0)
                     {
                         vertical_tri rp=que.top();

                         que.pop();

                         map[rp.c].push_back(rp.node->val);

                         minhl=min(minhl,rp.c);
                         maxhl=max(maxhl,rp.c);

                         if(rp.node->left)
                          que.push(vertical_tri(rp.node->left,rp.c-1,rp.r+1));

                        if(rp.node->right)
                          que.push(vertical_tri(rp.node->right,rp.c+1,rp.r+1));
                          


                     }
               }

            vector<vector<int>>ans;

            while(minhl<=maxhl)
            {
                 ans.push_back(map[minhl++]);
            }

            return ans;
    }