#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print1D(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout <<ele<<" ";
    }
    cout << endl;
}

void print2D(vector<vector<int>> &arr)
{
    for (vector<int> &ar : arr)
    {
        print1D(ar);
    }
}
//leetcode 62

  int unique_path_memo(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i==m-1 && j==n-1)
            return dp[i][j]=1;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
         
         if(i+1<m) 
          ans+=unique_path_memo(i+1,j,m,n,dp);
        
        if(j+1<n)
             ans+=unique_path_memo(i,j+1,m,n,dp);
        
        
        return dp[i][j]=ans;
    }

    int unique_path_dp(int m,int n,vector<vector<int>>&dp)
    {

       for(int i=m-1;i>=0;i--)
       { 
           for(int j=n-1;j>=0;j--)
           {
              if(i==m-1 && j==n-1)
               { 
                   dp[i][j]=1;
                 continue;
               }
        
        
       
             
        
        int ans=0;
         
          if(i+1<m)
          ans+=dp[i+1][j];//unique_path_memo(i+1,j,m,n,dp);
        
           if(j+1<n)
             ans+=dp[i][j+1];//unique_path_memo(i,j+1,m,n,dp);
        
        
         dp[i][j]=ans;
           }
       }

       return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
       int l= unique_path_dp(m,n,dp);

        // print2D(dp);
         return l;     
    }

    //leetcode 63
    long unique_path_dp(int m,int n,vector<vector<long>>&dp,vector<vector<int>>& grid)
    {

       for(int i=m-1;i>=0;i--)
       { 
           for(int j=n-1;j>=0;j--)
           {
              if(i==m-1 && j==n-1)
               { 
                   dp[i][j]=1;
                 continue;
               }
        
        
       
             
        
        long ans=0;
         
          if(i+1<m && grid[i+1][j]!=1)
          ans+=dp[i+1][j];//unique_path_memo(i+1,j,m,n,dp);
        
           if(j+1<n && grid[i][j+1]!=1)
             ans+=dp[i][j+1];//unique_path_memo(i,j+1,m,n,dp);
        
        
         dp[i][j]=ans;
           }
       }

       return dp[0][0];
    }
   
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
             return 0;
        
        
           vector<vector<long>>dp(m,vector<long>(n,-1));
       long l= unique_path_dp(m,n,dp,grid);

        
          return l;
    }

    int main()
    {
        int l=uniquePaths(3,4);

        return 0;
    }