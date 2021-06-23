#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;







void addEdge(int u,int v,int w,vector<vector<int>>graph)
{
    //bidirectional graph
      graph[u].push_back(v);
      graph[v].push_back(u);
}


void display(int N, vector<vector<int>>graph)
{

    for(int i=0;i<N;i++)
    {
        cout<<i<<"------->"<<" ";

        for(int j:graph[i])
        {
            cout<<j<<" ";
        }

        cout<<endl;
    }
}
    // ====================================================================
     // dis->discovery time, low-->low time ,Ap-articulation point, isAp- is articulation point


    vector<int>dis, low, AP;
    vector<bool> vis, isAP;
    int time1 = 0, noOfCallsFromRoot = 0;

    void dfs(int src, int par, int N, vector<vector<int>> graph) {
        dis[src] = low[src] = time1++;
        vis[src] = true;
          
          //nbr-neighbour
        for (int nbr : graph[src]) {
            if (!vis[nbr]) {

                if (par == -1)
                    noOfCallsFromRoot++;

                dfs(nbr, src, N, graph);

                if (dis[src] <= low[nbr]) { // why not this? : low[src] <= low[nbr]
                    AP[src]++;
                    isAP[src] = true;
                }

                if (dis[src] < low[nbr])// articulation bridge
                    cout<<"AP Edge: "<< src <<"->"<< nbr;

                low[src] = min(low[src], low[nbr]);

            } else if (nbr != par) {
                low[src] = min(low[src], dis[nbr]); // why not this? : low[src] = Math.min(low[src], low[nbr]);
            }
        }
    }

 void ArticulationPointsAndBridges(int N, vector<vector<int>>graph) {
        low.resize(N);
        dis.resize(N);
        vis.resize(N);

        AP.resize(N);
        isAP.resize(N);

        int components = 0;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, -1, N, graph);
                if (noOfCallsFromRoot == 1) {
                    isAP[i] = false;
                    AP[i] = 0;
                }
                noOfCallsFromRoot = 0;
                components++;
            }
        }

        // result.
        int countOfAP = 0;
        for (int i = 0; i < N; i++) {
            if (isAP[i]) {
                countOfAP++;
                cout<<"AP: "<< i << " @ "<< "Increase in No Of components: "<< AP[i];
            }
        }

    }

//leetcode 1192
  vector<vector<int>>ans;
       vector<int>dis,low;
       vector<bool>vis;int time2=0;
    //hume bridges dhudne hai isliye call ka zarrort nahi root wala ka
    
    void dfs(int src,int par,vector<vector<int>>&graph)
    {
        dis[src]=low[src]=time2++;
        
        
          vis[src]=true;
        
           for(int j:graph[src])
           {
               if(!vis[j])
               {
                  
                       
                   
                   dfs(j,src,graph);
                   
                   if(dis[src]< low[j])
                       ans.push_back({src,j});
                   
                   low[src]=min(low[src],low[j]);
               }
               else if(j!=par)
               {
                   low[src]=min(low[src],dis[j]);
               }
           }
    }
    

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        
        vector<vector<int>>graph(n);
        
          for(vector<int>&ar:connections)
          {
              graph[ar[0]].push_back(ar[1]);
                graph[ar[1]].push_back(ar[0]);
          }
        
        dis.resize(n);
        low.resize(n);
        vis.resize(n,false);
        
        dfs(0,-1,graph);
        
        return ans;
         
    }