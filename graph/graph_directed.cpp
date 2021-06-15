#include <iostream>
#include <vector>
#include <queue>
#include<string>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

const int N = 11;
vector<vector<Edge>> graph(N);

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
}

void display()
{
    for (int i = 0; i < N; i++)
    {
        cout << to_string(i) + " -> ";
        for (Edge e : graph[i])
        {
            cout << "(" + to_string(e.v) + ", " + to_string(e.w) + ") ";
        }
        cout << endl;
    }
}


void dfs_to(int src,vector<bool> &vis,vector<int> &ans)
{
    vis[src]=true;

    for(Edge j:graph[src])
    {
         if(!vis[j.v])
            dfs_to(j.v,vis,ans);
    }

    ans.push_back(src);
}


void topologicalOrder_DFS()
{
    vector<bool>vis(N,false);
    vector<int>ans;

       for(int i=0;i<N;i++)
       {
                if(vis[i]==false)
                   dfs_to(i,vis,ans);
       }
    for(int ele:ans)
      cout<<ele<<" ";
}


vector<int> khan_algo()
{

  vector<int>indegree(N,0);

      for(int i=0;i<N;i++)
       for(Edge e:graph[i])
             indegree[e.v]++;

  
    queue<int>que;
      vector<int>ans;


        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0)
               que.push(i);
        }


        int level=0;

          while(que.size()!=0)
          {
              int size=que.size();
               
                while(size-->0)
                {
                    int rvtx=que.front();

                       que.pop();

                       ans.push_back(rvtx);

                        for(Edge j:graph[rvtx])
                        {
                            if(--indegree[j.v]==0)
                               que.push(j.v);
                        }
                }

                level++;
          }

        return ans;
         

         // to detect cycle
           // return ans.size()==N;

}

//-1->unvisited
//0-part of my path
//1-> visited but not part of my current path
bool iscycle_dfs(int src,vector<int>&vis, vector<int>&ans)
{
      vis[src]=0;
      bool res=true;
         for(Edge j: graph[src])
          {
              if(vis[j.v]==-1)
                 res=res && iscycle_dfs(j.v,vis,ans);
              else if(vis[j.v]==0)
                  return false;   
          }

    ans.push_back(src);
          vis[src]=1;

          return res;        
}

void dfs()
{
    vector<int>vis(N,-1);

    vector<int>ans;
       bool res=true;
       for(int i=0;i<N;i++)
       {
           if(vis[i]==-1)
               res =res&&iscycle_dfs(i,vis,ans);
       }

         
}
void dfs_SCC( vector<vector<Edge>> &graph,int src,vector<bool> &vis,vector<int> &ans)
{
    vis[src]=true;

    for(Edge j:graph[src])
    {
         if(!vis[j.v])
            dfs_SCC(graph,j.v,vis,ans);
    }

    ans.push_back(src);
}

//Kosaraju
void kosaraju()
{
    vector<bool> vis(N, false);
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            dfs_SCC(graph,i, vis, ans);
    }


    // Graph inverse.
    vector<vector<Edge>> ngraph(N);
    for (int i = 0; i < N; i++)
    {
        for (Edge e : graph[i])
        {
            ngraph[e.v].push_back(Edge(i, 1));
        }
    }

    vis.clear();
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        int ele = ans[i];
        if (!vis[ele])
        {
            vector<int> scc;
            dfs_SCC(ngraph, ele, vis, scc);

            for (int e : scc)
                cout << e << " ";
            cout << endl;
        }
    }
}

void constructGraph()
{
    addEdge(5, 0, 10);
    addEdge(4, 0, 10);
    addEdge(5, 1, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 10);
    addEdge(0, 6, 10);
    addEdge(6, 7, 10);
    addEdge(7, 3, 10);
    addEdge(4, 8, 10);
    addEdge(8, 9, 10);
    addEdge(9, 10, 10);
    addEdge(10, 3, 10);

    topologicalOrder_DFS();
}

int main()
{
    constructGraph();
    return 0;
}