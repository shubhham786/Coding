#include<iostream>
#include<vector>

using namespace std;

class Node{

    public:
       int val=0;

       vector<Node*>childen;

        Node(int val){
          this->val=val;
        }
};

int size(Node* root)
{

    int s=0;

    for(Node * i:root->childen)
    {
        s+=size(i);
    }

    return s+1;
}

// on the basis of edge
int height(Node* root)
{
    int h=-1;

    for(Node* i:root->childen)
    {
        h=max(h,height(i));
    }

    return h+1;
}

int max_ele(Node* root)
{
    int max1=root->val;

    for(Node* i:root->childen)
    {
        max1=max(max1,max_ele(i));
    }

    return max1;
}

bool find(Node* root,int data)
{
    if(root->val==data)
     return true;
  
    for(Node* i:root->childen)
    {
        if(find(i,data))
           return true;
    }

    return false;
}


bool root_to_node(Node* root, int data, vector<Node*>& ans)
{
    if(root->val==data)
    {
        ans.push_back(root);
        return true;
    }

    bool res=false;

    for(Node* i:root->childen)
    {
        res=res||root_to_node(i,data,ans);
    }

    if(res)
       ans.push_back(root);


       return res;

}


Node* Lca(Node*root,int d1,int d2)
{
    vector<Node*>ans;
    root_to_node(root,d1,ans);
    
    vector<Node*>ans1;
    root_to_node(root,d2,ans1);

    Node* Lca=NULL;


    int j=ans.size()-1;
    int i=ans1.size()-1;


      while(i>=0 && j>=0)
      {
          if(ans[i]!=ans1[j])
              break;

              Lca=ans[i];
              i--;
              j--;
      }


      return Lca;
    
}


void kdown(Node* root, Node* blockednode,int time,vector<vector<int>>&ans)
{
    if(root==blockednode)
       return ;

       if(ans.size()==time)
         ans.push_back({});

             ans[time].push_back(root->val);
         for(Node* i:root->childen)
         {
             kdown(i,blockednode,time+1,ans);
         }
}
//method 1
vector<vector<int>> burningtree(Node* root,int d1)
{

    vector<Node*>ans;
    root_to_node(root,d1,ans);

    vector<vector<int>>ans1;
     Node* blockednode=NULL;
       for(int i=0;i<ans.size();i++)
       {
           kdown(ans[i],blockednode,i,ans1);
           blockednode=ans[i];
       }

       return ans1;

}

//method2

int burningtree(Node* root,int d1,vector<vector<int>>&ans)
{

    if(root->val==d1)
    {
        kdown(root,NULL,0,ans);
        return 1;

    }

    int time=-1;

    Node* blockednode=NULL;

    for(Node* child:root->childen)
    {
        time=burningtree(child,d1,ans);
          
          if(time!=-1)
          {
              blockednode=child;
              break;
          }

    }

       if(time!=-1)
       {
           kdown(root,blockednode,time,ans);
           time++;
       }

       return time;
}
