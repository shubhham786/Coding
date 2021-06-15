#include <iostream>
#include <vector>
#include<queue>

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
 