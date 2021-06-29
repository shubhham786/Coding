#include <iostream>
#include <vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//1466

 
    void dfs(int src,vector<vector<int>>&out,vector<bool>&vis,int &con, vector<vector<int>>&in)
    {
        
        vis[src]=true;
        
         
          for(int &j:out[src])
          {
              
              if(vis[j]==false)
              {
                  
                  con++;
                  dfs(j,out,vis,con,in);
              }
          }
           for(int &j:in[src])
          {
              
              if(vis[j]==false)
              {
                  
                
                  dfs(j,out,vis,con,in);
              }
          }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
     
        
        vector<vector<int>>outdegree(n);
         vector<vector<int>>indegree(n);
        
        vector<bool>vis(n,false);
        for(vector<int>&arr:connections)
        {
            
          
            outdegree[arr[0]].push_back(arr[1]);
            
            indegree[arr[1]].push_back(arr[0]);
        }
        
//          for(int i=1;i<n;i++)
//          {
//              if(vis[i]==false)
//              {
//                  order.push_back(i);
//          }
//          }
                
  
//          for(int i=0;i<n;i++)
//         {
//           vis[i]=false;
//         }
//         for(int i=0;i<order.size();i++)
//         {
//             if(!vis[order[i]])
//             {
                
//                 dfs(order[i],graph,vis,con,order);
//             }
//         }
//            for(int i=0;i<order.size();i++)
//         {
//             if(!vis[order[i]])
//             {
                
//                 dfs(order[i],graph,vis,con,order);
//             }
//         }
        
//         return con;
        
        int con=0;
        
         for(int i=0;i<n;i++)
        {            
             if(!vis[i])
            {
                  dfs(i,outdegree,vis,con,indegree);        
             }
        }
        
        return con;
    }
