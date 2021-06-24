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
              if(vis[j]==-1)// unvisited
                 res=res || iscycle_df(j,vis,ans,graph);
              else if(vis[j]==0)
                  return true;  // there is cycle 
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


    //leetcode 329

     int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        
        
         int n=matrix.size();
        
        int  m= matrix[0].size();
        
           vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        
              vector<vector<int>>indegree(n,vector<int>(m,0));
           queue<int>que;
            
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   
                      int count=0;
                    for(int k=0;k<4;k++)
                    {
                        int r=i+dir[k][0];
                        int c=j+dir[k][1];
                        
                        if(r>=0 && c>=0 && r<n && c<m && matrix[i][j] > matrix[r][c])
                             count++;
                    }
                   
                      indegree[i][j]=count;
                   
                    if(count==0)
                          que.push(i*m+j);
               }
           }
         // cout<<indegree
         
        
           int level=0;
             
            while(que.size()!=0)
            {
                int size=que.size();
                  
                   while(size-->0)
                   {
                       int front=que.front();
                       que.pop();
                         int row=front/m;
                         int col=front%m;
                       
                       for(int i=0;i<4;i++)
                       {
                           int r=row+dir[i][0];
                           int c=col+dir[i][1];
                           
                           // this condition
                           //matrix[r][c] >matrix[row][col] 
                           //[[0],[1],[5],[5]] for these type of test cases
                         
                           if(r>=0 && c>=0 && r<n && c<m && matrix[r][c] >matrix[row][col] && --indegree[r][c]==0)
                           {
                               //  cout<<r <<" "<<c<<endl;
                              // cout<<level<<endl;
                               que.push(r*m+c);
                           }
                       }
                       
                   }
                
                level++;
            }
          
        
         
          return level;
        
           
        
        
    }

        //method 2- dfs
int longestIncreasingPath(vector<vector<int>>& matrix){
    
       
         int n=matrix.size();
        
        int  m= matrix[0].size();
     vector<vector<int>>dp(n,vector<int>(m,-1));
    
     int ans=1;
    
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
                  if(dp[i][j]==-1)
                       ans=max(ans,dfs(matrix,dp,i,j));
           }
       }
    
        return ans;
}
    
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>&dp,int i, int j)
    {
        
         int n=matrix.size();
        
        int  m= matrix[0].size();
        
          if(dp[i][j]!=-1)
               return dp[i][j];
        
        
        
        dp[i][j]=1;
          vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        
           for(int l=0;l<4;l++)
             {
                  int r=i+dir[l][0];
               int c=j+dir[l][1];
               
                if(r>=0 && c>=0 && r<n && c<m && matrix[i][j] > matrix[r][c])
                {
                    dp[i][j]=max(dp[i][j], dfs(matrix,dp,r,c)+1);
                }
           }
        
          
        return dp[i][j];
    }

    //leetcode 547
     int find_par(int u)
    {
         return par[u]==-1?u:par[u]=find_par(par[u]);
    }
    
    
    vector<int>par;
    int findCircleNum(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
          par.resize(n,-1);
        
        
          int count=n;
      
          int l=0;
            for(vector<int>&arr:graph)
            {
                
                 for(int i=0;i<arr.size();i++)
                 {
                     int u=l;
                     int v=i;
                     
                        int p1=find_par(u);
                       int p2=find_par(v);
                     
                    // cout<<p1<<" "<<p2<<endl;
                     
                        if(arr[i]==1 && p1!=p2)
                        {
                            par[p1]=p2;
                        
                             count--;
                         //   cout<<" x"<<count<<endl;
                        }
                 }
                l++;
            }
        
        
        return count;
        
    }

    //leetcode 802
        
    //nokia game
    // dfs, cycle detection in directed graph
    //-1:unvisisted
    //0:-part my current my path
    //1:-visited but not part of my path
    
    bool dfs(vector<vector<int>>& graph,int src,vector<int>&vis)
    {
        vis[src]=0;
        
        bool res=true;
         for(int &j:graph[src])
         {
             if(vis[j]==-1)
                 res=res && dfs(graph,j,vis);
             else if(vis[j]==0)
                 return false;
         }
        
        
        if(res)
          vis[src]=1;
        
         return res;
    }
   
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        int n=graph.size();
        vector<int>vis(n,-1);
        
        vector<int>ans;
          for(int i=0;i<n;i++)
          {
             if(vis[i]==-1)
             {
                 if(dfs(graph,i,vis))
                 {
                     ans.push_back(i);
                 }
                
             }
               else if(vis[i]==1)
                     ans.push_back(i);
          }
        return ans;
    }