
class Edge{

      public:

         int v=0;
         int w=0;

         Edge(int v,int w)
         {
             this->v=v;
             this->w=w;
         }
};


const int N=7;

vector<vector<Edge>>graph(N);

void addEdge(int u,int v,int w)
{
    //bidirectional graph
      graph[u].push_back(Edge(v,w));
      graph[v].push_back(Edge(u,w));
}


void display()
{

    for(int i=0;i<N;i++)
    {
        cout<<i<<"------->"<<" ";

        for(Edge j:graph[i])
        {
            cout<<"( "+to_string(j.v)+","+to_string(j.w)+" )";
        }

        cout<<endl;
    }
}

int findedge(int u,int v)
{
    int idx=-1;

    for(int i=0;i<graph[u].size();i++)
    {
       if(graph[u][i].v==v)
          return i;
    }

    return idx;
}

void removeEdge(int u, int v)
{
    
    int idx1=findedge(u,v);
    int idx2=findedge(v,u);

   graph[u].erase(graph[u].begin()+idx1);
   graph[v].erase(graph[v].begin()+idx1);


}

void remove_vertex(int u)
{

    for(int i=graph[u].size()-1;i>=0;i--)
    {
        removeEdge(u,graph[u][i].v);
    }


}

bool haspath(int src,int dest,vector<bool>&visited)
{
    if(src==dest)
       return true;

       bool res=false;
          visited[src]=true;

       for(Edge j: graph[src])
       {
            if(!visited[j.v])
              res=res||haspath(j.v,dest,visited);
       }

       return res;

}

int allpath(int src,int dest,vector<bool>&visited,string s)
{
     if(src==dest)
      {
          cout<<s+to_string(src)<<endl;
          return 1;
      }

      visited[src]=true;


        int count=0;

         for(Edge j: graph[src])
         {
            if(!visited[j.v])
              count+=allpath(j.v,dest,visited,s+to_string(src)+"--->");
          }

          
     visited[src]=false;

      return count;

}

//heaviest weight
class heavypair{
       public:
         int weight=0;
           string s="";
      heavypair(int w,string s)
           {
               this->weight=w;
               this->s=s;
           }
};

heavypair path(int src,int dest,vector<bool>&vis)
{
    if(src==dest)
    {
        heavypair ans(0,"");
        return ans;
    }
    vis[src]=true;
    heavypair ans(-(int)1e9,"");
     for(Edge j: graph[src])
         {
            if(!vis[j.v]){
             heavypair ans1=path(j.v,dest,vis);
                if(ans1.weight!=-(int)1e9 && ans1.weight+j.w >ans.weight)
                {
                    ans.weight=ans1.weight+j.w;
                    ans.s=to_string(src)+" "+ans1.s;
                }
            }
          }
          vis[src]=false;
          return ans;
}


int hamiltoninan_path_cycle(int src, int osrc,int totalno_edge,vector<bool>& visited,string s)
{
    if(totalno_edge=N-1)
    {
        int idx=findedge(osrc,src);

        if(idx==-1)
        {
            cout<<"hamiltonian path"<<s;
        }
        else
        {
            cout<<"hamiltonian cycle"<<s;
        }

        cout<<endl;

        return 1;
    }


    visited[src]=true;

   int count=0;

     for(Edge j:graph[src])
     {
         if(!visited[j.v])
           count+=hamiltoninan_path_cycle(j.v,osrc,totalno_edge+1,visited,s+to_string(src)+" ");
     }

     visited[src]=false;

     return count;

}

void hamiltion_cycle_path(int src)
{
    vector<bool>vis(N,false);
     cout<<hamiltoninan_path_cycle(src,src,0,vis,"");

}

 void dfs(int src,vector<bool>&vis,vector<int>&ans)
 {
    vis[src]=true;
  for(Edge j:graph[src])
    {
        if(!vis[j.v])
          {
             dfs(j.v,vis,ans);
          }
    }
  ans.push_back(src);
 }
 int GCC_DFS()
 {
    vector<vector<int>>result;
    vector<bool>vis(N,false);
      int component=0;
      for(int i=0;i<N;i++)
      {
       if(!vis[i])
          { 
                vector<int>ans;
               dfs(i,vis,ans);
               component++;
              result.push_back(ans);
          }
      }
      return component;
 }

// bfs
//1st method
void BFS_cycle(int src)
{
     queue<int>que;
     que.push(src);
          int level=0;
          int dest=6;
          int atlevel=-1;
          bool cycle=false;
   vector<bool>vis(N,false);
       while(que.size()!=0)
       {
           int size=que.size();
           cout<<"level "<<level<<"----> "<<" ";
              while(size-->0)
                 {
                       int rvtx=que.front();
                       que.pop();                       
                       cout<<rvtx<<" ";
                       if(vis[rvtx]==true)
                        {
                           cycle=true;
                           continue;
                        } 
                      if(vis[rvtx]==dest)
                       {
                           atlevel=level;
                       }
                       vis[rvtx]=true;
                       for(Edge j:graph[rvtx])
                       {
                           if(!vis[j.v])
                           {
                               que.push(j.v);
                           }
                       }
                 }
                 cout<<endl;
                 level++;
       }
       cout<<"iscycle:"<<(boolalpha)<<cycle<<endl;
       cout<<dest<<" present at:"<<atlevel<<endl;
}

//method-2
void BFS_shortest_path(int src)
{
     queue<int>que;
     que.push(src);
          int level=0;
          int dest=6;
          int atlevel=-1;
          vector<bool>vis(N,false);
        //important
         vis[src]=true;
     while(que.size()!=0)
       {
           int size=que.size();
             while(size-->0)
                 {
                       int rvtx=que.front();
                       que.pop();                       
                      for(Edge j:graph[rvtx])
                       {
                           if(!vis[j.v])
                           {   //important
                               vis[j.v]=true;
                               que.push(j.v);
                           }
                           if(j.v=dest)
                              atlevel=level+1;
                       }
                 }
                 level++;
       }
       cout<<dest<<" present at:"<<atlevel<<endl;
}


void bfs_shortest_path_print(int src,vector<bool>&vis)
{

    queue<int>que;
   que.push(src);

     vis[src]=true;
     int dest=6;
     int atlevel=-1;

     int level=0;
       vector<int>par(N,-1);

         while(que.size()!=0)
         {
             int size=que.size();
                while(size-->0)
                {
                    int rvtx=que.front();
                    que.pop();


                    for(Edge j:graph[rvtx])
                    {
                         if(!vis[j.v])
                         {
                             vis[j.v]=true;
                             que.push(j.v);
                             par[j.v]=rvtx;
                         }

                         if( atlevel ==-1 && j.v==dest)
                           atlevel=level+1;
                    }
                }
                level++;
         }

         cout<<dest<<" present at: "<<atlevel<<endl;

         int idx=dest;
           while(idx!=-1)
           {
               cout<<idx<<"-> ";
               idx=par[idx];
           }

}

void bfs_GCC()
{
    vector<bool>vis(N,false);
    int componemt=0;

    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            componemt++;
            bfs_shortest_path_print(i,vis);
        }
    }
}
void constructgraph()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

}

int main()
{
    constructgraph();
    vector<bool>vis(N,false);

    cout<<allpath(0,6,vis,"");
}