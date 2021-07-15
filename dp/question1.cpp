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

    //https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

    int mod1=(int)1e9+7;
long friends(int i,vector<long>&dp)
{
    if(i<=1)
       return dp[i]=1;
       
     if(dp[i]!=-1)
       return dp[i];
       
       long count=0;
       
       long single=friends(i-1,dp);
       
        long pair= ((i-1)*friends(i-2,dp));
       
       count=(single%mod1 + pair%mod1)%mod1;
       return dp[i]=count;
}
long friends_dp(int n,vector<long>&dp)
{
    
    for(int i=0;i<=n;i++){
       if(i<=1)
       { 
          dp[i]=1;
         continue;
       }
       
    
       long count=0;
       
       long single=friends(i-1,dp);
       
        long pair= ((i-1)*friends(i-2,dp));
       
       count=(single%mod1 + pair%mod1)%mod1;
        dp[i]=count;
    }
    
    return dp[n];
}

long friends_optimize(int n)
{
    long a=1;
    long b=1;
    
//    long ans= (b%mod1 + ())
  
  for(int i=2;i<=n;i++)
  {
      long z=a*(i-1);
      long ans=(b%mod1 + z%mod1)%mod1;
      
      a=b;
      
      b=ans;
  }
  
  return b;
    
}

void frined_print(string s,string ans)
{
    if(s.size()==0)
      { 
        cout<<ans<<endl;
        return;
      }

      int n=s.size();

     
          frined_print(s.substr(1),ans+'('+s[0]+')');
       

        if(n>=2)
        {
         
           for(int i=1;i<n;i++)
           {
              string l="";
               l+='(';
               l+=s[0];
               l+=s[i];
               l+=')';
               
               string rst=s.substr(1,i-1)+s.substr(i+1);
               frined_print(rst,ans+l);


           }
        }

}
    int countFriendsPairings(int n) 
    { 
        // code here
        
        //vector<long>dp(n+1,-1);
        
        //return (int)friends(n,dp);
       //  return (int)friends_dp(n,dp);
         return (int)friends_optimize(n);
    }

    //https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#

    int maxGold1(int r, int c, vector<vector<int>>& M,vector<vector<int>>&dir,vector<vector<int>>&dp)
 {
     if(c==M[0].size()-1)
     {
         return dp[r][c]=M[r][c];
     }
     
     if(dp[r][c]!=-1)
     {
         return dp[r][c];
     }
     
     int max_gold=0;
     
       for(int l=0;l<dir.size();l++)
       {
            int x=r+dir[l][0];
            int y=c+dir[l][1];
            
            if(x>=0 && x<M.size())
            {
                max_gold=max(max_gold,maxGold1(x,y,M,dir,dp));
            }
       }
       
       
       return dp[r][c]=max_gold+M[r][c];
 }
   
     int goldMine_dp(vector<vector<int>>&mat, vector<vector<int>>&dp, vector<vector<int>>&dir) {
        int n = mat.size();
        int m = mat[0].size();

        for (int c = m - 1; c >= 0; c--) {
            for (int r = n - 1; r >= 0; r--) {

                if (c == mat[0].size() - 1) {
                    dp[r][c] = mat[r][c];
                    continue;
                }

                int maxGold = 0;
                for (int d = 0; d < 3; d++) {
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];
                    if (x >= 0 && x < n) {
                        maxGold = max(maxGold, dp[x][y]);
                    }
                }

                dp[r][c] = maxGold + mat[r][c];
            }
        }

        int maxGold = 0;
        for (int i = 0; i < mat.size(); i++) {
            maxGold = max(maxGold, dp[i][0]);
        }

        return maxGold;
    }
       int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        
          vector<vector<int>>dp(n,vector<int>(m,-1));
          
            vector<vector<int>>dir={{0,1},{1,1},{-1,1}};
    // int max_gold=0;
    
    //    for(int i=0;i<n;i++)
    //    {
    //        max_gold=max(max_gold,maxGold1(i,0,M,dir,dp));
    //    }
        
        
        return goldMine_dp(M,dp,dir);
    }
    // int main()
    // {
    //     //int l=uniquePaths(3,4);
          
    //       frined_print("ABCDE","");
    //     return 0;
    // }

 