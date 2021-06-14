#include<iostream>
#include<vector>
#include<queue>


using namespace std;

//leetcode 1091
 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;
        
        
        
        if(n==1 && m==1 && grid[0][0]==0)
            return 1;
        
           vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        
           queue<int>que;
        que.push(0);
        
        grid[0][0]=1;
        
        int level=1;
        
          while(que.size()!=0)
          {
              int size=que.size();
              
                while(size-- >0)
                {
                    int  front=que.front();
                    que.pop();
                    
                    int row=front/m;
                    int col=front%m;
                    
                    
                    for(int i=0;i<8;i++)
                    {
                        int r=row+dir[i][0];
                        int c=col+dir[i][1];
                        
                        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==0)
                        {
                            grid[r][c]=1;
                            que.push(r*m+c);
                        }
                        
                        // agar isko for loop ke upar dete tu [[0]] iske liye alag se check nahi karna hota
                        if(r==n-1 && c==m-1)
                            return level+1;
                    }
                }
              
              level++;
          }
        
        
        return -1;
    }


    //leetcode 785

    // bfs type-1
       
    //0 ==red
    //1==green
    //-1= unvisited
    bool isBipartite(int src,vector<vector<int>>& graph,vector<int>&vis) {
        
        
        
        
        //int m=graph[0].size();
        
        
   
        
        
        queue<int>que;
        
        que.push(src);
        //vis[0]=0;
        
        int level=0;
        
        
        while(que.size()!=0)
        {
             int size=que.size();
            
            
               while(size-->0)
               {
                   int rvtx=que.front();
                   que.pop();
                   
                   if(vis[rvtx]!=-1)
                   {
                       if(vis[rvtx]!=level)
                           return false;
                       
                       else
                         continue;
                   }
                   
                   vis[rvtx]=level;
                   for(int j:graph[rvtx])
                   {
                       if(vis[j]==-1)
                       {
                           //vis[j]=level;
                           que.push(j);
                       }
                      
                   }
               }
            
            level=(level+1)%2;
        }
        
        
        return true;
        
        
    }
     bool isBipartite(vector<vector<int>>& graph)     
     {
         int n=graph.size();
         
          vector<int>vis(n,-1);
         
         bool ans=true;
         for(int i=0;i<n;i++)
         {
             
             if(vis[i]==-1)
              ans=ans && isBipartite(i,graph,vis);
         }
         
         return ans;
     }


     //bfs type-2


        
    //0 ==red
    //1==green
    //-1= unvisited
   bool isBipartite(int src,vector<vector<int>>& graph,vector<int>&vis) {
        
        
      //  int n=graph.size();
        
        //int m=graph[0].size();
        
        
    //vector<int>vis(n,-1);
        
        
        queue<int>que;
        
        que.push(src);
        vis[src]=0;
        
        int level=0;
        
        level=level+1;
        while(que.size()!=0)
        {
             int size=que.size();
            
            
               while(size-->0)
               {
                   int rvtx=que.front();
                   que.pop();
                   
                 
                   //vis[rvtx]=level;
                   for(int j:graph[rvtx])
                   {
                       if(vis[j]==-1)
                       {
                           vis[j]=level;
                           que.push(j);
                       }
                       else
                       {
                           if(vis[j]!=level)
                               return false;
                       }
                      
                   }
               }
            
            level=(level+1)%2;
        }
        
        
        return true;
        
        
    }
     bool isBipartite(vector<vector<int>>& graph)     
     {
         int n=graph.size();
         
          vector<int>vis(n,-1);
         
         bool ans=true;
         for(int i=0;i<n;i++)
         {
             
             if(vis[i]==-1)
              ans=ans && isBipartite(i,graph,vis);
         }
         
         return ans;
     }


     //multiple point bfs


// 2nd type bfs
       int orangesRotting(vector<vector<int>>& grid) {
       
        
        int n=grid.size();
        
        int m=grid[0].size();
        
        
        
        queue<int>que;
        
        int fresh=0;
        
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
               {
                   if(grid[i][j]==2)
                       que.push(i*m+j);
                   
                   else if(grid[i][j]==1)
                     fresh++;        
               }
           }
        
       //cout<<fresh<<endl;;
        if(fresh==0)
            return 0;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        
        int min=0;
        
            while(que.size()!=0)
            {
                int size=que.size();
                
                   while(size>0)
                   {
                       //cout<<size<<endl;
                      int front=que.front();
                         que.pop();
                       int row=front/m;
                       int col=front%m;
                       
                       // cout<<row<<" "<<col<<endl;
                       
                       for(int i=0;i<4;i++)
                       {
                            int r=row+dir[i][0];
                           int c=col+dir[i][1];
                           
                           
                           if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1)
                           {
                               fresh--;
                               grid[r][c]=2;
                               
                               que.push(r*m +c);
                           }
                           if(fresh==0)
                               return min+1;
                       }
                       
                        size--;

                   }
                
                
                min++;
            }
            
        
        if(fresh>0)
            return -1;
        else
            return min;
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