#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Edge
{
   public: 
    int v=0;
    int w=0;
   
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }

};



void addEdge(int u,int v,int w,vector<vector<Edge>>&graph)
{
    
    graph[u].push_back(Edge(v,w));
    graph[v].push_back(Edge(u,w));
}
void display(int N,vector<vector<Edge>>&graph){

    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"---->"<<" ";
        for(Edge j :graph[i])
        {
            //cout<<"(";
           //cout<<j.v<<","<<j.w<<")"<<" "<<",";// both same
          //print as a whole string
          cout<<"( "+ to_string(j.v) + "," + to_string(j.w) + ")";

        }

        cout<<endl;
    }

}

class primsPair
{
public:
    int vtx = 0;
    int par = 0;
    int wt = 0;

    primsPair(int vtx, int par, int wt)
    {
        this->vtx = vtx;
        this->par = par;
        this->wt = wt;
    }
};


class comp{


   bool operator()(const primsPair&a,const primsPair&b)const
   {
       return a.wt>b.wt;
   }
};

void primsAlgo_02(int src, int N, vector<int>&par,vector<int>&dist,vector<bool> &vis, vector<vector<Edge>> &graph)
{
    

    vector<vector<Edge>>MST;

    priority_queue<primsPair,vector<primsPair>,comp>pq;

      pq.push(primsPair(src,-1,0));

      int no_of_edge=0;
  


        while(no_of_edge < N-1)
        {
           primsPair rvtx=pq.top();
            pq.pop();

            if(vis[rvtx.vtx])
               continue;//cycle

             
             if(rvtx.par!=-1)
             {
                 addEdge(rvtx.par,rvtx.vtx,rvtx.wt,MST);
                 no_of_edge++;
             }

              vis[rvtx.vtx]=true;

               for(Edge e:graph[rvtx.vtx])
               {
                  if(!vis[e.v] && e.w< dist[e.v])
                   {
                       dist[e.v]=e.w;
                       par[e.v]=rvtx.vtx;
                       pq.push(primsPair(e.v,rvtx.vtx,e.w));
                       
                   }
               }



        }

   display(N, MST);
      

}

void primsAlgo_01(int src, int N, vector<bool> &vis, vector<vector<Edge>> &graph)
{
    

    vector<vector<Edge>>MST;

    priority_queue<primsPair,vector<primsPair>,comp>pq;

      pq.push(primsPair(src,-1,0));

      int no_of_edge=0;
  


        while(no_of_edge < N-1)
        {
           primsPair rvtx=pq.top();
            pq.pop();

            if(vis[rvtx.vtx])
               continue;//cycle

             
             if(rvtx.par!=-1)
             {
                 addEdge(rvtx.par,rvtx.vtx,rvtx.wt,MST);
                 no_of_edge++;
             }

              vis[rvtx.vtx]=true;

               for(Edge e:graph[rvtx.vtx])
               {
                  if(!vis[e.v])
                   {
                       pq.push(primsPair(e.v,rvtx.vtx,e.w));
                       
                   }
               }



        }


      

}
void prims(int N,vector<vector<Edge>> &graph)  {
      vector<bool>vis(N,false); 
      vector<int>dist(N,(int)1e9); 
        vector<int>par(N,-1);
        
        for (int i = 0; i < N; i++) {
            if (!vis[i])
                primsAlgo_02(i, N, par, dist, vis, graph);
        }
    }

int main()
{
    
}