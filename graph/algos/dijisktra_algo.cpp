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

class dijisktraPair
{
public:
    int vtx = 0;
    //int par = 0;
    int wsf = 0;

    dijisktraPair(int vtx,int wt)
    {
        this->vtx = vtx;
        //this->par = par;
        this->wsf = wt;
    }
};


class comp{


   bool operator()(const dijisktraPair&a,const dijisktraPair&b)const
   {
       return a.wsf>b.wsf;
   }
};

void dijisktra(int src, int N, vector<vector<Edge>> &graph)
{
    

    //vector<vector<Edge>>MST;

    priority_queue<dijisktraPair,vector<dijisktraPair>,comp>pq;

      pq.push(dijisktraPair(src,0));

      int no_of_edge=0;
  
     vector<int>vis(N,false);

        while(no_of_edge < N-1)
        {
           dijisktraPair p=pq.top();
            pq.pop();

            if(vis[p.vtx])
               continue;//cycle

             
             if(p.vtx!=src)
             {
                 
                 no_of_edge++;
             }

              vis[p.vtx]=true;

               for(Edge e:graph[p.vtx])
               {
                  if(!vis[e.v])
                   {
                       pq.push(dijisktraPair(e.v,e.w+p.wsf));
                       
                   }
               }



        }

}


//better
void dijisktra_01(int src, int N, vector<vector<Edge>> &graph)
{
    

    //vector<vector<Edge>>MST;

    priority_queue<dijisktraPair,vector<dijisktraPair>,comp>pq;

      pq.push(dijisktraPair(src,0));

      int no_of_edge=0;

      vector<int>dist(N,(int)1e9);
      vector<int>par(N,-1);
  
     vector<int>vis(N,false);

        while(no_of_edge < N-1)
        {
           dijisktraPair p=pq.top();
            pq.pop();

            if(vis[p.vtx])
               continue;//cycle

             
             if(par[p.vtx]!=-1)
             {
                 
                 no_of_edge++;
             }

              vis[p.vtx]=true;

               for(Edge e:graph[p.vtx])
               {
                  if(!vis[e.v] && dist[e.v]> e.w+p.wsf)
                   {
                       dist[e.v]= e.w+p.wsf;
                       par[e.v]=p.vtx;

                       pq.push(dijisktraPair(e.v,e.w+p.wsf));
                       
                   }
               }



        }

}

