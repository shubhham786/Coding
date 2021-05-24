#include <iostream>
#include <vector>

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
}
 