#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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
vector<int>parent;
vector<int>size1;



// with Path Cpmpression :  alpha(n)  <= 4, Inverse Akermann Function
// without path compression : O(logn)
int find_parent(int u)
{
      return parent[u]==u?u:parent[u]=find_parent(parent[u]);
}


void merge(int p1,int p2)
{


    if(size1[p1]>size1[p2])
    {
           parent[p2]=p1;

             size1[p1]+=size1[p2];
    }
  else
  {
       parent[p1]=p2;

             size1[p2]+=size1[p1];

  }

}

// Edges : {{u,v,w}.....}

// without Path Compression and size : V + E*V
// Path Compression: V + E(alpha(n))
// without Path Compression: V + ELog(V)
void union_find(int n , vector<vector<int>>&edges)
{
      cout<<n<<endl;

    parent.resize(n);
    size1.resize(n);
       for(int i=0;i<n;i++)
       {
           size1[i]=1;
           parent[i]=i;
       }

       
         vector<vector<Edge>>graph(n);
  
         for(vector<int>&arr:edges)
         {
                 int u=arr[0];
                 int v=arr[1];
                  int w=arr[2];

                   int p1=find_parent(u);
                   int p2=find_parent(v);

                     if(p1!=p2)
                     {
                         merge(p1,p2);
                        addEdge(u,v,w,graph);
                     }
                    
         }
cout<<graph.size()<<endl;
            display(n, graph);
      
}
void solve()
{
    int N = 9;
    vector<vector<int>> edges{{0, 1, 4}, {0, 7, 8},{1,7,11},{1,2,8},{7,8,7},{7,6,1},{2,8,2},
    {8,6,2},{2,3,7},{2,5,4},
    {6,5,2},{3,5,14},{3,4,9},{5,4,10}};

    // default behaviour is increasing order.
   // increasing order me de dega // auto&a  and auto&b bhi pass kar sakthe the
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2]; 
    });

    cout<<edges.size()<<endl;

    union_find(N, edges);
}


int main()
{
       solve();

  return 0;
}



