#include <iostream>
#include <vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//200 --->Number of Islands

 void dfs(int src, int dest,vector<vector<char>>& grid,vector<vector<int>>& dir)
    {
        grid[src][dest]='0';
        
        
        for(int l=0;l<dir.size();l++)
        {
            
            int i=src+dir[l][0];
            int j=dest+dir[l][1];
            
            
            
            if(i>=0 && j>=0 && i<grid.size() && j< grid[0].size() && grid[i][j]=='1')
            {
                dfs(i,j,grid,dir);
            }
         }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
       
        vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
             
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {    
                   count++;
                  
                      dfs(i,j,grid,dir);
                    
                }
                
            }
        }
        
        return count;
    }

//695

  int dfs(int src,int dest,vector<vector<int>>& grid,vector<vector<int>>&dir)
    {
         
        
        grid[src][dest]=0;
        int z=1;
        
        for(int l=0;l<dir.size();l++)
        {
            int i=src+dir[l][0];
            int j=dest+dir[l][1];
            
            if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1)
                z += dfs(i,j,grid,dir); 
        }
        
        
        return z;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        
        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        
        
         int count=0;
        
         int n=grid.size();
         int m=grid[0].size();
        
         
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 
                 if(grid[i][j]==1)
                 {
                     int l=dfs(i,j,grid,dir);
                     
                     if(l>count)
                     {
                         count=l;
                     }
                 }
             }
         }
        
        
        return count;
        
        
        
    }

 //463
  int islandPerimeter(vector<vector<int>>& grid) {
        
        
        if(grid.size()==0 || grid[0].size()==0)
        {
            return 0;
        }
        
        
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        int count=0; 
        int near=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                    
                    for(int l=0;l<dir.size();l++)
                    {
                        int r=i+dir[l][0];
                        int c=j+dir[l][1];
                        if(r>=0 && c>=0  && r<grid.size() && c< grid[i].size() && grid[r][c]==1)
                        {
                            
                            near++;
                        }
                    }
                }
            }
        }
        
        return 4*count -near;
        
        
    }   
// 130
  void surroundedRegionDFS(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &dir)
{
    grid[i][j] = '$';
    for (int d = 0; d < dir.size(); d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];

        if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 'O')
            surroundedRegionDFS(r, c, n, m, grid, dir);
    }
}

void solve(vector<vector<char>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return;

    int area = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 'O')
            surroundedRegionDFS(i, 0, n, m, grid, dir);
        if (grid[i][m - 1] == 'O')
            surroundedRegionDFS(i, m - 1, n, m, grid, dir);
    }

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 'O')
            surroundedRegionDFS(0, j, n, m, grid, dir);
        if (grid[n - 1][j] == 'O')
            surroundedRegionDFS(n - 1, j, n, m, grid, dir);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'O')
                grid[i][j] = 'X';
            if (grid[i][j] == '$')
                grid[i][j] = 'O';
        }
    }
}

//Multiple bfs(994,286)
//994
int orangesRotting(vector<vector<int>>& grid) {
  
  int n=grid.size();
        int m=grid[0].size();
        
        int fresh=0,time=0;
        
        queue<int>pending;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pending.push(i*m+j);
                }
                if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        
        if(fresh==0)
        {
            return 0;
        }
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        
        while(pending.size()!=0)
        {
            int size=pending.size();
            
              while(size>0)
              {
                  int front=pending.front();
                  pending.pop();
                  
                  int row=front/m;
                  int  col=front%m;
                  
                  for(int i=0;i<dir.size();i++)
                  {
                      int x=row+dir[i][0];
                      int y=col+dir[i][1];
                      
                      
                      if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1)
                      {
                          fresh--;
                          grid[x][y]=2;
                          pending.push(x*m+y);
                          
                          if(fresh==0)
                          {
                              return time+1;
                          }
                      }
                     
                  }
                  
                  size--;
                  
              }
              time++;
        }
        
        
        return -1;
   
    }
       //https://www.lintcode.com/problem/663/

       void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here

        int n=rooms.size();
        int m=rooms[0].size();
          
          queue<int>que;
           int empty=0;
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(rooms[i][j]==0)
               que.push(i*m+j);
            else if(rooms[i][j]==2147483647)
               empty++;
         }
        }  
             vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

             int dist=0;
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

                           if(r>=0 && c>=0 && r<n && c<m && rooms[r][c]==2147483647)
                               {
                                 
                                      rooms[r][c]=dist+1;
                                      que.push(r*m+c);
                                        
                                          empty--;
                                      if(empty==0)
                                        break;
                               }
                      }

                  }

                  dist++;
           }       
    } 

  // leetcode 1765

    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
        
    int n=water.size();
        
     int m=water[0].size();
        
        queue<int>que;
        
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                   if(water[i][j]==1){
                      que.push(i*m+j);
                       water[i][j]=0;
                   }
                  else{
                      water[i][j]=-1;
                      
                  }
              }
          }
                     
        
        
           vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
          int level=1;
        
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
                            
                            
                              if(r>=0 && c>=0 && r<n && c<m && water[r][c]==-1)
                              {
                                  water[r][c]=level;
                                  
                                    que.push(r*m+c);
                              }
                                  
                            
                        }
                    }
                
                level++;
            }
        
        
        return water;
        
    }

    //leetcode 1162

     int maxDistance(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        
        int m=grid[0].size();
        
        
        queue<int>que;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                      if(grid[i][j]==1){
                            que.push(i*m+j);
                          grid[i][j]=-1;
                      }  
                }
            }
        
          int max1=-1;
        
          vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
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
                              
                              
                                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==0)
                                {
                                    max1=max(max1,level+1);
                                    grid[r][c]=-1;
                                    
                                      que.push(r*m+c);
                                }
                          }
                       
                     
                   }
                  level++;
            }
        
        return max1;
    }
    //union_find
    //leetcode 684
        
    int find_parent(int u)
    {
        return par[u]==-1?u:par[u]=find_parent(par[u]);
    }
    
    vector<int>par;
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
             
        int n=edges.size();
        
           par.resize(n+1,-1);
        
        
         vector<int>ans;
            for(vector<int>&arr:edges)
            {
                int u=arr[0];
                int v=arr[1];
                
                   int p1= find_parent(u);
                  int p2=find_parent(v);
                
                  if(p1!=p2)
                  {
                     par[p2]=p1; 
                  }
                else
                    ans=arr;
                 
            }
        
        return ans;
          
    }


/*
Given strings A and B of the same length, we say A[i] and B[i] are equivalent characters. For example, if A = "abc" and B = "cde", then we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.

Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'
Symmetry: 'a' == 'b' implies 'b' == 'a'
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'
For example, given the equivalency information from A and B above, S = "eed", "acd", and "aab" are equivalent strings, and "aab" is the lexicographically smallest equivalent string of S.

Return the lexicographically smallest equivalent string of S by using the equivalency information from A and B.



Example 1:

Input: A = "parker", B = "morris", S = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in A and B, we can group their characters as [m,p], [a,o], [k,r,s], [e,i]. The characters in each group are equivalent and sorted in lexicographical order. So the answer is "makkek".
Example 2:

Input: A = "hello", B = "world", S = "hold"
Output: "hdld"
Explanation:  Based on the equivalency information in A and B, we can group their characters as [h,w], [d,e,o], [l,r]. So only the second letter 'o' in S is changed to 'd', the answer is "hdld".
Example 3:

Input: A = "leetcode", B = "programs", S = "sourcecode"
Output: "aauaaaaada"
Explanation:  We group the equivalent characters in A and B as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in S except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".


Note:

String A, B and S consist of only lowercase English letters from 'a' - 'z'.
The lengths of string A, B and S are between 1 and 1000.
String A and B are of the same length.
*/

int findPar(int u)
{
    return par[u] == -1 ? u : par[u] = findPar(par[u]);
}
string smallestEquivalentString(string A, string B, string S)
{
    for (int i = 0; i < 26; i++)
        par.push_back(i);
    // par.resize(26,-1);

    for (int i = 0; i < A.length(); i++)
    {
        int p1 = findPar(A[i] - 'a');
        int p2 = findPar(B[i] - 'a');

        par[p1] = min(p1, p2);
        par[p2] = min(p1, p2);

        //     if(p1 < p2)
        //         par[p2] = p1;
        //     else if(p2 < p1)par[p1] = p2;
        //
    }

    string ans = "";
    for (int i = 0; i < S.length(); i++)
    {
        ans += (char)(findPar(S[i] - 'a') + 'a');
    }

    return ans;
}
 
 //leetcode 839
   
    int find_par(int u)
    {
        return par[u]==u?u:par[u]=find_par(par[u]);
    }
    
    vector<int>par;
    
    
    bool is_permuation(string &s1, string &s2)
    {
       int count=0;
       
       for(int i=0;i<s1.size();i++)
       {
           if(s1[i]!=s2[i] && ++count >2)
           {
               return false;
           }
       }
       
       return true;
    }
   
    
    int numSimilarGroups(vector<string>& strs) {
        
        
        int n=strs.size();
        
          par.resize(n+1);
        
          for(int i=0;i<=n;i++){
              par[i]=i;
          }
        
            int count=n;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                
                   
                             int p1=find_par(i);
                     int p2=find_par(j);
                    
                    
                    if(p1!=p2)  
                       {
                         
                            if(is_permuation(strs[i],strs[j]))
                           {
                                 par[p2]=p1;
                                 count--;
                           }
                       }
                    }         
            
            }
        
       
        return count;
        
    }

    //https://www.lintcode.com/problem/number-of-islands-ii/description

    /*
    A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]. Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
*/
struct Point {
     int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
 int findPar(int u)
      {
          return par[u]==u?u:par[u]=findPar(par[u]);
      }
     vector<int>par;
    vector<int> numIslands2(int n, int m, vector<Point> &positions) {
        // write your code here

         par.resize(m * n, -1);

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int count = 0;
    vector<int> ans;
    for (Point &pos : positions)
    {
        int i = pos.x;
        int j = pos.y;

        if (par[i * m + j] == -1)
        {

            par[i * m + j] = (i * m+ j);
            count++;

            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[d][0];
                int y = j + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < m && par[x * m + y] != -1)
                {
                    int p1 = findPar(i * m + j);
                    int p2 = findPar(x * m + y);

                    if (p1 != p2)
                    {
                        count--;
                        par[p1] = p2;
                    }
                }
            }
        }

        ans.push_back(count);
    }

     return ans;
    }

    //leetcode 1168
    vector<int> par;
int minCostToSupplyWater_(int N, vector<vector<int>> &Edges)
{

    for (int i = 0; i <= N; i++)
    {
        par.push_back(i);
    }

    int cost = 0;

    for (vector<int> &edge : Edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        int p1 = findPar(u);
        int p2 = findPar(v);

        if (p1 != p2)
        {
            par[p1] = p2;
            cost += w;
        }
    }

    return cost;
}

int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }

    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    return minCostToSupplyWater_(n, pipes);
}

//leetcode 695
 vector<int>par;
    
 int findPar(int u)
    {
        return par[u]==u?u:par[u]=findPar(par[u]);
    }
  int maxAreaOfIsland(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n * m; i++)
        par.push_back(i);

    vector<int> componentSize(n * m, 1);
    int maxArea = 0;

    vector<vector<int>> dir{{1, 0}, {0, 1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int p1 = findPar(i * m + j);
                for (int d = 0; d < 2; d++)
                {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];

                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                    {
                        int p2 = findPar(x * m + y);
                        if (p1 != p2)
                        {
                            par[p2] = p1;
                            componentSize[p1] += componentSize[p2];
                        }
                    }
                    maxArea = max(maxArea, componentSize[p1]);
                }
            }
            else
                componentSize[i * m + j] = 0;
        }
    }

    return maxArea;
}

//https://www.hackerrank.com/challenges/journey-to-the-moon/problem

vector<int>par,size1;

   int find_par(int u)
   {
       return par[u]==u?u:par[u]=find_par(par[u]);
   }
long journeyToMoon(int n, vector<vector<int>> astronaut) {


  for(int i=0;i<n;i++)
  {
      par.push_back(i);
      size1.push_back(1);
  }
  
  
  for(vector<int>&arr: astronaut)
  {
      int p1=find_par(arr[0]);
      int p2=find_par(arr[1]);
      
      if(p1!=p2)
      {
          par[p1]=p2;
          size1[p2]+=size1[p1];
      }
  }
  
  long totalpair=0,sum=0;
  
     for(int i=0;i<n;i++)
     {
         if(par[i]==i)
          {
              totalpair+=size1[i]*sum;
              sum +=size1[i];
          }
     }
    
    
    return totalpair;
  

          
}

//leetcode 815 
//bus stop
 int numBusesToDestination(vector<vector<int>>& routes, int s, int d) {
        
      if(s==d)
            return 0;
        
        int n=routes.size();
    
         unordered_map<int,vector<int>>busStandMapping;
      unordered_set<int>isBusStandSeen;
    vector<bool> isBusSeen(n, false);
        
        
          int bus_no=0;
        
           for(vector<int>&arr:routes)
           {
                 
                 for(int &j:arr)
                     busStandMapping[j].push_back(bus_no);
               
               bus_no++;
                     
           }
        
        
          queue<int>que;
         que.push(s);
          isBusStandSeen.insert(s);
    
        int level=0;
            while(que.size()!=0)
            {
                int size=que.size();
                
                   while(size-->0)
                   {
                       int front=que.front();
                       que.pop();
                         
                        vector<int>allbuses_from_this_stand=busStandMapping[front];
                       
                       for(int & i:allbuses_from_this_stand)
                       {
                           if(isBusSeen[i])
                                 continue;
                           
                           
                           for(int &j:routes[i])
                           {
                               
                               if(isBusStandSeen.find(j)==isBusStandSeen.end())
                               {
                                     isBusStandSeen.insert(j);
                                   
                                   que.push(j);
                                   
                                   if(j==d)
                                       return level+1;
                                   
                                  
                                   
                               }
                           }
                           
                           isBusSeen[i]=true;
                           
                       }
                       
                   }
                
                level++;
            }
        
        
        
        return -1;
        
        
        
        
        
    }
  
//leetcode 743
  class comp{
      
          public:// always remeber to make public
          bool operator()(const pair<int,int>&a,const pair<int,int>&b)const{
              
              return a.second>b.second;//min_heap
          }
    };
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
     
        vector<vector<pair<int,int>>>graph(n + 1);

    // {u -> {v,w}}
    for (vector<int> &ar : times)
    {

      //  vector<int>ans=
     
         graph[ar[0]].push_back({ar[1],ar[2]});
    }

        
         priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
          
        
          int no_of_edge=0;
        
                 //vtx,wsf
                pq.push(make_pair(k,0));
              
        vector<bool>vis(n,false);
        
        int max_time=0;
             
          while(pq.size()!=0 && no_of_edge<n-1)
          {
              
              pair<int,int>p=pq.top();
              
               pq.pop();
              
               if(vis[p.first]==true)
                 continue;
              
              
                  if(p.first!=k)
                      no_of_edge++;
              
               
              vis[p.first]=true;
               max_time=max(max_time,p.second);
                    
                 for(pair<int,int> &a:graph[p.first])
                 {
                     if(!vis[a.first]){
                         pq.push({a.first,a.second+p.second});
                        
                 } 
                 }
              
              
              
              
              
          }
              
              
              if(no_of_edge<n-1)
                  return -1;
              
        return max_time;
        
        
    }

    //leetcode 1905
     // good dfs question   
    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2, int i,int j,   vector<vector<int>>&dir,bool& ans )
    {
        
        
      
        
          if(grid1[i][j]==0)
                ans=false;
        
          grid2[i][j]=0;
        
        
        
          for(int l=0;l<4;l++)
          {
              int x=i+dir[l][0];
              int y=j+dir[l][1];
              
        if(x>=0 && y>=0 && x<grid2.size() && y< grid2[0].size() && grid2[x][y]==1)
            dfs(grid1,grid2,x,y,dir,ans);
          }
        
        return ans;
           
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        
       
         int n=grid1.size();
        int m=grid1[0].size();
        
         vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        
       
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    //cout<<"x"<<i<<" "<<j<<endl;
                    bool ans=true;
                    if(dfs(grid1,grid2,i,j,dir,ans)==true){
                        count++;
                       //cout<<i<<" "<<j<<endl;   
                    }
                }
            }
        }
        
        return count;
     
        
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
    //leetcode 787
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
               
        
        
        vector<vector<int>>dp(n,vector<int>(k+2,(int)1e9));
        
     //  cout<<dp.size()<<" "<<dp[0].size();
        
        for(int i=0;i<n;i++)
        {
             if(i==src)
             {
                 dp[i][0]=0;
             }
             else
                 dp[i][0]=(int)1e9;
        }
        
     //cout<<dp[0][src]<<endl;
        int count=0;
        for(int i=1;i<=k+1;i++){
       
            for(int z=0;z<n;z++)
            {
                dp[z][i]=dp[z][i-1];
            }
          for(int l=0;l<flights.size();l++){
            int u=flights[l][0];
           
             int v=flights[l][1];
             int w=flights[l][2];
               
            
               if(dp[u][i-1]!=(int)1e9 && dp[u][i-1]+w <dp[v][i]){
                    dp[v][i]= dp[u][i-1]+w;
                   //cout<<u<<" "<<v<<" "<<count++<<endl;
                 
               }
          }
         
        }
        
        return dp[dst][k+1]==(int)1e9?-1:dp[dst][k+1];
    }

    //leetcode 942
    // see discussion , reframed question
      int find_par(int u)
    {
        return par[u]==u?u:par[u]=find_par(par[u]);
    }
    
    vector<int>par;
    vector<int>size2;
    
    void merge(int p1,int p2)
    {
        if(size2[p1]>size2[p2])
        {
            par[p2]=p1;
            size2[p1]+=size2[p2];
        }
       else
        {
            par[p2]=p1;
            size2[p1]+=size2[p2];
        }
        
    }
    
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    
        
        int n=graph.size();
        
        par.resize(n);
        size2.resize(n);
        
         for(int i=0;i<n;i++)
         {
             par[i]=i;
             size2[i]=1;
         }
        
        sort(initial.begin(),initial.end());
        
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(i!=j && graph[i][j]==1)
                 {
                     int p1=find_par(i);
                     int p2=find_par(j);
                     
                     if(p1!=p2)
                     {
                         merge(p1,p2);
                     }
                 }
             }
         }
            
   vector<int>InfectedNodesInCity(n,0);
        for (int i : initial) {
            int leader = find_par(i);
            InfectedNodesInCity[leader]++;
        }

        int ans = initial[0];
        int maxPopulatedCity = 0;
        for (int i : initial) {
            int NoOfNodesInfected = InfectedNodesInCity[find_par(i)];
            if (NoOfNodesInfected == 1 && size2[find_par(i)] > maxPopulatedCity) {
                maxPopulatedCity = size2[find_par(i)];
                ans = i;
            }
        }
        
        
        return ans;
        
    }