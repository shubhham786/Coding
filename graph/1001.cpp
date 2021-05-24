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

const int N=7;
vector<vector<Edge>>graph(N);

void addEdge(int u,int v,int w)
{
    //undirected graph 
    graph[u].push_back(Edge(v,w));
    graph[v].push_back(Edge(u,w));
}
void display(){

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

int searchedge_in_vtx(int u,int v)
{
    int idx=-1;
    for(int i=0;i<graph[u].size();i++)
    {
        if(graph[u][i].v==v)
        {
            idx=i;
            break;
        }
    }

    return idx;
}

void removeEdge(int u,int v){

          int idx1=searchedge_in_vtx(u,v);
          int idx2=searchedge_in_vtx(v,u);

          graph[u].erase(graph[u].begin()+idx1);
          graph[v].erase(graph[v].begin()+idx2);
}

void removeVtx(int u){

    for(int i= graph[u].size()-1;i>=0;i--)
    {
        int v= graph[u][i].v;

        removeEdge(u,v);
    }

}

bool hasPath(int src, int dest,vector<bool>& vis)
{
     if(src==dest)
     {
         return true;
     }

     vis[src]=true;
     bool res=false;

     for(Edge e:graph[src])
     {
         if(vis[e.v]!=true)
         {
             res=res || hasPath(e.v,dest,vis);
         }
     }

     return res;

}

int printAllPath(int src,int dest,vector<bool>& vis, string psf){

   if(src==dest)
   {
         cout<< psf<< dest<<endl;
         return 1;
   }

     vis[src]=true;
     int count=0;
     for(Edge e: graph[src])
     {
             if(vis[e.v]==false)
             {
                 count+= printAllPath(e.v,dest,vis,psf+to_string(src)+" ");
             }
     }
   vis[src]=false;

   return count;
}

// heavy Path -> print : path and weight

class heavypair
{
      public:
       int weight=0;
       string  path="";

       heavypair(int weight,string path)
       {
           this->weight=weight;
           this->path=path;
       }
};


heavypair heavypath(int src,int dest,vector<bool>&vis)
{

   if(src==dest)
   {
       heavypair ans(0,to_string(dest));
       //ans.weight=0;
       //ans.path=to_string(dest);


       return ans;
   }

    vis[src]=true;
    
     heavypair myans(-(int)1e9,"");
     for(Edge e: graph[src])
     {
         if(vis[e.v]==false)
         {
             heavypair path1=heavypath(e.v,dest,vis);

             if(path1.weight != -(int)1e9  &&  path1.weight+ e.w > myans.weight)
             {
                 myans=path1;
             }
         }
     }



    vis[src]=false;
    return myans;
}

// hamintonialPathAndCycle
int hamintonialPathAndCycle(int src,int osrc, int totaledge,vector<bool>& vis,string psf)
{
   
    if(totaledge==N-1)
    {
         int idx= searchedge_in_vtx(osrc,src);

         if(idx==-1)
         {
             cout<<"hamintonialpath :  "<< psf+to_string(src)+" ";
         }
         else
         {
             cout<<"hamintonialcycle: "<<psf+to_string(src)+" ";
         }

         cout<<endl;

         return 1;
    }


  
        vis[src]=true;
        int count=0;

        for(Edge e: graph[src])
        {  
            if(vis[e.v]==false)
              count+= hamintonialPathAndCycle(e.v,osrc,totaledge+1,vis,psf+to_string(src)+" ");


        }


        vis[src]=false;

        return count;
   
     


}


int hamintonialPathAndCycle(int src)
{
    vector<bool> vis(N, false);
    cout << hamintonialPathAndCycle(src, src, 0, vis, "") << endl;
}

// get all connected component

void dfs(int src,vector<bool>& vis,vector<int>&ans)
{

    vis[src]=true;
    for(Edge e: graph[src])
    {
        if(vis[e.v]==false)
          dfs(e.v,vis,ans);
    }

     ans.push_back(src);
}

int gcc()
{


    vector<vector<int>>result;
    vector<bool>vis(N,false);
    int component=0;
    for(int i=0;i<N;i++)
    {
        if(vis[i]==false)
        {
          component++;
          vector<int>ans;
             
              dfs(i,vis,ans);
              result.push_back(ans);
        

       }
    }
   
       return component;


}

void constructgraph()
{

    //static graph
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
     addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);
    addEdge(0, 6, 3);
}

    


int main(){
   
     constructgraph();
    // vector<bool> vis(N, false);
    // cout << printAllPath(0, 6, vis, "") << endl;
    hamintonialPathAndCycle(0);
    
   return 0;
}
