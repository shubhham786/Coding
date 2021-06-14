#include <iostream>
#include <vector>
#include <queue>
#include<string>

using namespace std;

//leetcode 207

 vector<int>khan_algo(int n,vector<vector<int>>&graph)
    {
        vector<int>indegree(n,0);
        
        
        //cout<<"1"<<endl;
            for(int i=0;i<n;i++)
                for(int j:graph[i])
                      indegree[j]++;
        
        
        
        queue<int>que;
        
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                que.push(i);
        }
        
        vector<int>ans;
        //cout<<ans.size();
        //cout<<que.size();
        int level=0;
          while(que.size()!=0)
          {
              int size=que.size();
              
                      while(size-->0)
                      {
                          int rvtx=que.front();
                           que.pop();
                          
                          ans.push_back(rvtx);
                          
                           for(int l:graph[rvtx])
                               if(--indegree[l]==0)
                                   que.push(l);
                      }
              
                   level++;
          }
        
          return ans;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>>graph(n);
        
            for(int i=0;i<pre.size();i++)
            {
                graph[pre[i][0]].push_back(pre[i][1]);
            }
        
        
        return khan_algo(n,graph).size()==n;
        
        
    }

// using dfs
   bool iscycle_df(int src,vector<int>&vis, vector<int>&ans,vector<vector<int>>&graph)
{
      

      vis[src]=0;
 
        bool res=true;
      
          for(int j: graph[src])
          {
              if(vis[j]==-1)
                 res=res && iscycle_df(j,vis,ans,graph);
              else if(vis[j]==0)
                  return false;   
          }

    ans.push_back(src);
          vis[src]=1;

          return res;

         
}

bool dfs(int n, vector<vector<int>>&graph)
{
    vector<int>vis(n,-1);

    vector<int>ans;
       bool res=true;
       for(int i=0;i<n;i++)
       {
           if(vis[i]==-1)
               res =res&&iscycle_df(i,vis,ans,graph);
       }

    
    return res;
         
}
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>>graph(n);
        
            for(int i=0;i<pre.size();i++)
            {
                graph[pre[i][0]].push_back(pre[i][1]);
            }
        
        
        return dfs(n,graph);
        
        
    }
    //leetcode 210
     vector<int>khan_algo(int n,vector<vector<int>>&graph)
    {
        vector<int>indegree(n,0);
        
        
        //cout<<"1"<<endl;
            for(int i=0;i<n;i++)
                for(int j:graph[i])
                      indegree[j]++;
        
        
        
        queue<int>que;
        
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                que.push(i);
        }
        
        vector<int>ans;
        //cout<<ans.size();
        cout<<que.size()<<endl;
        int level=0;
     cout<<que.front();
          while(que.size()!=0)
          {
              int size=que.size();
              
                      while(size-->0)
                      {
                          int rvtx=que.front();
                           que.pop();
                          //cout<<rvtx;
                          ans.push_back(rvtx);
                         // cout<<ans.size();
                           for(int l:graph[rvtx])
                               if(--indegree[l]==0)
                                   que.push(l);
                      }
              
                   level++;
          }
        
          return ans;
    }

  
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<vector<int>>graph(n);
        
            for(int i=0;i<pre.size();i++)
            {
                graph[pre[i][1]].push_back(pre[i][0]);
            }
        
         vector<int>ans=khan_algo(n,graph);
      if(ans.size()==n)
            return ans;
      else
          return  {};
        
    }
    //// it's better to use khan's algo

 bool iscycle_df(int src,vector<int>&vis, vector<int>&ans,vector<vector<int>>&graph)
{
      

      vis[src]=0;
       
         
        bool res=false;
      
          for(int j: graph[src])
          {
              if(vis[j]==-1)
                 res=res || iscycle_df(j,vis,ans,graph);
              else if(vis[j]==0)
                  return true;   
          }

   
 vis[src]=1;
        ans.push_back(src);   
          return res;

         
}


bool dfs(int n, vector<vector<int>>&graph,vector<int>&ans)
{
    vector<int>vis(n,-1);

    
       bool res=false;
       for(int i=0;i<n;i++)
       {
           if(vis[i]==-1)
               res =res|| iscycle_df(i,vis,ans,graph);
       }

    
    return res;
         
}
    
  
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<vector<int>>graph(n);
        
            for(int i=0;i<pre.size();i++)
            {
                graph[pre[i][0]].push_back(pre[i][1]);
            }
            vector<int>ans;
        
     
      if(!dfs(n,graph,ans))
            return ans;
      else
          return  {};
        
    }