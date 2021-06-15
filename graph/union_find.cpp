#include<iostream>
#include<vector>
#include<string>
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
vector<int>par;
vector<int>size1;

// with Path Cpmpression :  alpha(n)  <= 4, Inverse Akermann Function
// without path compression : O(logn)
int find_parent(int u)
{
    return par[u]==u?u:par[u]=find_parent(par[u]);
}

//O(1)
void merge(int p1,int p2)
{
   
   if(size1[p1]>size1[p2])
    {
        par[p2]=p1;
        size1[p1]++;
    }
    else{
        par[p1]=p2;
        size1[p2]++;
    }
}

//graph in the form :{{u,v,w}....}
// without Path Compression and size : V + E*V
// Path Compression: V + E(alpha(n))
// without Path Compression: V + ELog(V)

void union_find(int N,vector<vector<int>>&Edges)
{
    vector<vector<Edge>>graph(N);
    par.resize(N);
    size1.resize(N);
    for(int i=0;i<N;i++)
    {
        par.push_back(i);
        size1.push_back(1);
    
    }
    
    bool cycle=false;
    for(vector<int>&edge:Edges)
    {
        int u=edge[0],v=edge[1],w=edge[2];
        int p1=find_parent(u);
        int p2=find_parent(v);

           if(p1!=p2)
           {
               merge(p1,p2);
               addEdge(u, v, w,graph);
           }
           else{
               cycle=true;
           }
    }

      display(N, graph);
    cout<<(boolalpha)<<cycle<<endl;



}

int main()
{
    return 0;
}