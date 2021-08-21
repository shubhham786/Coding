#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//leetcode 300

//using binary search

//important
    int lengthOfLIS(vector<int>& nums) {
     
        
        vector<int>dp(nums.size(),0);
          int ans=0;
        
        
           for(int &val:nums)
           {
               int si=0,ei=ans;
               
               while(si<ei)
               {
                   int mid=si+ (ei-si)/2;
                   
                   if(dp[mid]<val)
                       si=mid+1;
                   else
                       ei=mid;
               }
               
               dp[si]=val;
               
               if(si==ans)
                   ans++;
           }
        
        return ans;
        
    }

    //leetcode 354
        int maxEnvelopes(vector<vector<int>>& env) {
        
        sort(env.begin(),env.end(),[](vector<int>&a,vector<int>&b){
             if(a[0]<b[0])
                 return true;
             else if(a[0]==b[0])
                 return a[1]>b[1];
            else 
                 return false;
        });
        
        
        vector<int>dp(env.size(),0);
        int ans=0;
        
        //cout<<env[2][1]<<endl;
        for(vector<int>& a:env)
        {
            int si=0,ei=ans;
            
              while(si<ei)
              {
                  int mid= si+(ei-si)/2;
                  
                  if(dp[mid]<a[1])
                      si=mid+1;
                  else
                      ei=mid;
              }
          
           // if(si==0 ||env[si-1][0]>env[si][0])
              dp[si]=a[1];
             if(si==ans)
                 ans++;
            
        }
        
        
            
            return ans;
        
    
        
    }


    //https://practice.geeksforgeeks.org/problems/box-stacking/1/

     int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
       
        vector<vector<int>>dim(3*n,vector<int>(3));
       
       
        int j=0;
       
        for(int i=0;i<n;i++)
        {
            dim[j][0]=height[i];
            dim[j][1]=min(width[i],length[i]);
            dim[j++][2]=max(width[i],length[i]);
         
            dim[j][0]=width[i];
            dim[j][1]=min(height[i],length[i]);
            dim[j++][2]=max(height[i],length[i]);  
           
             dim[j][0]=length[i];
            dim[j][1]=min(height[i],width[i]);
            dim[j++][2]=max(height[i],width[i]);  
        }
       
          //cout<<dim.size();
        //  cout<<dim[0][0]<<" "<<dim[0][1]<<" "<<dim[0][2]<<" "<<endl;  
        //return 1;
       
        sort(dim.begin(),dim.end(),[](vector<int>&a,vector<int>&b){
           
             if(a[1]<b[1])
               return true;
             else if(a[1]==b[1])
                return a[2]>b[2];
            else
               return false;
        });
/*        for(int i=0;i<3*n;i++)
         cout<<dim[i][0]<<" "<<dim[i][1]<<" "<<dim[i][2]<<" "<<endl;
*/        
         //return 1;
         
         vector<int>dp(3*n);
         int max_ans=1;
         for(int i=0;i<3*n;i++)
         {
             dp[i]=dim[i][0];
             
             for(int j=i-1;j>=0;j--)
             {
                 if(dim[i][2]>dim[j][2] && dim[i][1]>dim[j][1])
                 {
                     dp[i]=max(dp[i],dp[j]+dim[i][0]);
                 }
                 
             }
             
/*              if(dp[i]>max_ans)
                   max_ans=dp[i];
*/            
              max_ans=max(max_ans,dp[i]);
         }
         
         
         return max_ans;
    }


    //day 2

//https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#
        long long countWays(int n, int k){
        // code here
        if(n==1)
         return k;
         int mod=(int)1e9+7;
         long last_two_same=k;
         long last_two_diff=k*(k-1);
         
         for(int i=3;i<=n;i++)
         {
             long total=(last_two_same+last_two_diff)%mod;
             last_two_same=last_two_diff;
             last_two_diff=(total*(k-1))%mod;
         }
         
         return (last_two_same+last_two_diff)%mod;
    }

    //https://www.lintcode.com/problem/515/
       int minCost(vector<vector<int>> &costs) {
        // write your code here

  if(costs.size()==0)
     return 0;
        for(int i=1;i<costs.size();i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                costs[i][j]+=min(costs[i-1][j+1],costs[i-1][j+2]);
                else if(j==1)
                costs[i][j]+=min(costs[i-1][j+1],costs[i-1][j-1]);
                else
                costs[i][j]+=min(costs[i-1][j-1],costs[i-1][j-2]);
            }
        }
        
        return min(costs[costs.size()-1][0],min(costs[costs.size()-1][1],costs[costs.size()-1][2]));
    }

//https://www.lintcode.com/problem/516/
    int minCostII(vector<vector<int>> &costs) {
        // write your code here


if(costs.size()==0)
  return 0;

        int min1=(int)1e9;
        int min_2=(int)1e9;

        for(int i=0;i<costs[0].size();i++)
        {
            if(costs[0][i]<=min1)
            {
                min_2=min1;
                min1=costs[0][i];

            }
            else if(costs[0][i]>min1 && costs[0][i]<min_2)
                min_2=costs[0][i];
        }
        
   //cout<<min_2<<" "<<min1<<endl;

        for(int i=1;i<costs.size();i++)
        {
            for(int j=0;j<costs[0].size();j++)
            {
                costs[i][j]+= (costs[i-1][j]==min1)?min_2:min1;   
             }
           min1=min_2=(int)1e9;
            for(int j=0;j<costs[0].size();j++)
            {
                  if(costs[i][j]<=min1)
            {
                min_2=min1;
                min1=costs[i][j];

            }
             else if(costs[i][j]>min1 && costs[i][j]<min_2)
                min_2=costs[i][j];
             }
           //  cout<<min_2<<" "<<min1<<endl;


        }

        return min1;

    //   int ans=(int)1e9;
    //       for(int i=0;i<costs[0].size();i++)
    //       {
    //           ans=min(ans,costs[costs.size()-1][i]);
    //       }

         // return ans;

    }

    //https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1#

 #define ll long long
	ll countStrings(int n) {
	    // code here
	    
	    int mod=(int)1e9+7;
	    ll ending_with_1=1;
	    ll ending_with_0=1;
	    ll total=0;
	    for(int i=2;i<=n+1;i++)
	    {
	         total=(ending_with_1+ending_with_0)%mod;
	        
	        ending_with_1=ending_with_0;
	        ending_with_0=total;
	    }
	    
	    return total;
	    
	}

    //https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1#
        int numTrees(int N) 
    {
        // Your code here
        
        int mod=(int)1e9+7;
        vector<long>dp(N+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=N;i++)
        {
            for(int j=i-1,k=0;k<i;j--,k++)
            {
                dp[i]=(dp[i]+(dp[j]*dp[k])%mod)%mod;
            }
        }
        
        
        return (int)dp[N];
    }

    //leetcode 64
     int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
          vector<vector<int>>dp(n,vector<int>(m));
        
        
          return minPathSum_dp(grid,n-1,m-1,dp);
        
    }
     
    int minPathSum(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
             return (int)1e9;
        
        if(i==0 && j==0)
            return dp[i][j]=grid[i][j];
        
        if(dp[i][j]!=-1)
             return dp[i][j];
        
        
        //if(i-1>=0)
        int up=minPathSum(grid,i-1,j,dp);
        int right=minPathSum(grid,i,j-1,dp);
        
        return dp[i][j]=min(up,right)+grid[i][j];
            
    }
    
     int minPathSum_dp(vector<vector<int>>& grid,int I,int J,vector<vector<int>>&dp)
    {
       for(int i=0;i<=I;i++)
       {
           for(int j=0;j<=J;j++)
           {
                       if(i==0 && j==0)
                       {dp[i][j]=grid[i][j];
                        continue;
                       }
        
//         if(dp[i][j]!=-1)
//              return dp[i][j];
        
        
        //if(i-1>=0)
               
        int up= i!=0?dp[i-1][j]:(int)1e9;//minPathSum(grid,i-1,j,dp);
        int right= j!=0?dp[i][j-1]:(int)1e9;//minPathSum(grid,i,j-1,dp);
        
          dp[i][j]=min(up,right)+grid[i][j];
           }
       }
       
         return dp[I][J];
            
    }

    //leetcode 741
    // using 4d array

       int cherry(vector<vector<int>>& grid,int r, int c, int r1,int c1,int r2, int c2,        vector<vector<vector<vector<int>>>>&dp)
    {
    
        
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
              return -1;
        
     if(r1==r && c1==c)
              {
        // cout<<r<<" "<<c<<endl;
               return dp[r1][c1][r2][c2]=(grid[r1][c1]==1)?1:0;
           }
        
        if(dp[r1][c1][r2][c2]!=-2)
            return dp[r1][c1][r2][c2];
        
        int ans=0;
        
        if(r1==r2 && c1==c2){
             if(grid[r1][c1]==1){
                 ans++;
                 //grid[r1][c1]=0;
             }
        } 
        else{
            if(grid[r1][c1]==1)
            {  ans++;
             // cout<<ans<<" "; 
            }   
             if(grid[r2][c2]==1)
             {    ans++;
              //cout<<ans<<" "<<endl;
             }
            
           // grid[r1][c1]=0;
         //   grid[r2][c2]=0;
        }
        
        //cout<<r1<<" "<<c1<<"--> "<<r2<<" "<<c2<<"  "<<ans<<endl;
        
        int rans1=-1,rans2=-1;
        int dans1=-1,dans2=-1;
        int max1=-(int)1e9;
        
        if(r1+1<=r && r2+1<=r)
            rans1=cherry(grid,r,c,r1+1,c1,r2+1,c2,dp);
        if(r1+1<=r && c2+1<=c)
            rans2=cherry(grid,r,c,r1+1,c1,r2,c2+1,dp);
        if(c1+1<=c && r2+1<=r)
            dans1=cherry(grid,r,c,r1,c1+1,r2+1,c2,dp);
          if(c1+1<=c && c2+1<=c)
            dans2=cherry(grid,r,c,r1,c1+1,r2,c2+1,dp);
        
        
         if(rans1!=-1)
              max1=max(max1,rans1);
         if(rans2!=-1)
              max1=max(max1,rans2);
         if(dans1!=-1)
              max1=max(max1,dans1);
         if(dans2!=-1)
              max1=max(max1,dans2);
        
            return dp[r1][c1][r2][c2]= max1==-(int)1e9?-1:max1+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        //cout<<r<<c<<endl;
        
        vector<vector<vector<vector<int>>>>dp(r,vector<vector<vector<int>>>(c,vector<vector<int>>(r,vector<int>(c,-2))));
        int z=cherry(grid,r-1,c-1,0,0,0,0,dp);
        return z==-1?0:z;
    }
    //using 3d dp
        int cherry(vector<vector<int>>& grid,int r, int c, int r1,int c1,int r2,         vector<vector<vector<int>>>&dp)
    {
       int c2=r1+c1-r2;
        
        if(r1>=r || r2>=r || c1>=c || c2>=c ||grid[r1][c1]==-1 || grid[r2][c2]==-1)
              return -(int)1e9;
        
     if(r1==r-1 && c1==c-1)
              {
        // cout<<r<<" "<<c<<endl;
               return grid[r1][c1];
           }
        
        if(dp[r1][c1][r2]!=-2)
            return dp[r1][c1][r2];
        
        int ans=0;
        
        if(r1==r2 && c1==c2){
             ans=grid[r1][c1];
        } 
        else{
           ans=grid[r1][c1]+grid[r2][c2];
        }
        
        //cout<<r1<<" "<<c1<<"--> "<<r2<<" "<<c2<<"  "<<ans<<endl;
        
        // int rans1=-1,rans2=-1;
        // int dans1=-1,dans2=-1;
        
        
      
           int rans1=cherry(grid,r,c,r1+1,c1,r2+1,dp);
         
           int rans2=cherry(grid,r,c,r1+1,c1,r2,dp);
    
            int rans3=cherry(grid,r,c,r1,c1+1,r2+1,dp);
         
         int rans4=cherry(grid,r,c,r1,c1+1,r2,dp);
        
        
//          if(rans1!=-1)
//               max1=max(max1,rans1);
//          if(rans2!=-1)
//               max1=max(max1,rans2);
//          if(dans1!=-1)
//               max1=max(max1,dans1);
//          if(dans2!=-1)
//               max1=max(max1,dans2);
        
        int z=max({rans1,rans2,rans3,rans4});
           return dp[r1][c1][r2]= z==-(int)1e9?z:z+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        //cout<<r<<c<<endl;
        
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(r,-2)));
        int z=cherry(grid,r,c,0,0,0,dp);
        return z==-(int)1e9?0:z;
    }

    //leetcode 1463
    //cherry pick up2
        int cherry(vector<vector<int>>& grid,int r,int c,int r1,int c1,int c2,vector<vector<int>>&dir,vector<vector<vector<int>>>&dp)
    {
        int r2=r1;
         if(r1==r)
            return 0;//dp[r1][c1][c2]=(c1==c2)?grid[r1][c1]:grid[r1][c1]+grid[r2][c2];
        
        if(r1>=r || c1<0 || c1>=c || c2<0 || c2>=c)
             return -(int)1e9;
        
       
        
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
         
        int ans=0;
        
        if(c1==c2)
            ans=grid[r1][c1];
        else
            ans=grid[r1][c1]+grid[r2][c2];
        
      
        int max_ans=0;
        
        for(int i=0;i<dir.size();i++)
        {
            int x1=r1+1;
            int y1=c1+dir[i][0];
            int x2=x1;
            int y2=c2+dir[i][1];
            
            max_ans=max(max_ans,cherry(grid,r,c,x1,y1,y2,dir,dp));
        }
        
       
        return dp[r1][c1][c2]=max_ans+ans;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        
        
         vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        
        return cherry(grid,r,c,0,0,c-1,dir,dp);
        
    }

      //recursive
   int longestCommonSubsequence(string & a,string &b,int i,int j,vector<vector<int>>&dp)
   {
       if(i==0 || j==0)
       {
           return dp[i][j]=0;
       }
      // cout<<i<<" "<<j<<endl;
       
       
       if(dp[i][j]!=-1)
           return dp[i][j];
       
       
       if(a[i-1]==b[j-1])
       {
           return dp[i][j]=longestCommonSubsequence(a,b,i-1,j-1,dp)+1;
       }
       else
       {
           
           return dp[i][j]=max(longestCommonSubsequence(a,b,i-1,j,dp),longestCommonSubsequence(a,b,i,j-1,dp));
       }
       
   }

    //bootom up
    
    int longestCommonSubsequence(string text1, string text2) {
        
        
        int n=text1.size();
        
        int m=text2.size();
        
        
          vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
       //int a= longestCommonSubsequence(text1,text2,n,m,dp);
        
         //  print2D(dp);
        
       // return a;
        
         for(int i=0;i<=n;i++)
         {
             for(int j=0;j<=m;j++)
             {
                  if(i==0 || j==0)
       {
           dp[i][j]=0;
              continue;
       }
      // cout<<i<<" "<<j<<endl;
       
       
//        if(dp[i][j]!=-1)
//            return dp[i][j];
       
       
       if(text1[i-1]==text2[j-1])
       {
           dp[i][j]=dp[i-1][j-1]+1;//longestCommonSubsequence(a,b,i-1,j-1,dp)+1;
       }
       else
       {
           
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//max(longestCommonSubsequence(a,b,i-1,j,dp),longestCommonSubsequence(a,b,i,j-1,dp));
       }
             }
         }
        
        
        return dp[n][m];

    
    }

    //https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1#
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here

    vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
    
      
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                for(int k=0;k<=n3;k++)
                {
                    if(i==0 || j==0 || k==0)
                    {
                        dp[i][j][k]=0;
                        continue;
                    }
                    
                    if(A[i-1]== B[j-1] && A[i-1]==C[k-1] && B[j-1]==C[k-1])
                    {
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                    }
                    else
                    {
                        dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                    }
                }
            }
        }
        
        return dp[n1][n2][n3];
}

//leetcode 516
     int longestPalindromeSubseq_rec(string &s,int i,int j,vector<vector<int>>&dp)
    {
        
        
        if(i>=j)
        {
            return dp[i][j]= (i==j)?1:0;
        }
        
        
        if(dp[i][j]!=0)
              return dp[i][j];
        
        
        if(s[i]==s[j])
        {
            return dp[i][j]=2+longestPalindromeSubseq_rec(s,i+1,j-1,dp);
        }
        else
        {
            return dp[i][j]=max(longestPalindromeSubseq_rec(s,i+1,j,dp),longestPalindromeSubseq_rec(s,i,j-1,dp));
        }
    }

    //leetcode 72
     int min_distance_rec(string& a,string &b,int i,int j,vector<vector<int>>&dp)
        
    {
        if(i==0 || j==0)
        {
            return dp[i][j]=(i==0)?j:i;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        
        if(a[i-1]==b[j-1])
        {
            return dp[i][j]=min_distance_rec(a,b,i-1,j-1,dp);
        }
        
        int replace=min_distance_rec(a,b,i-1,j-1,dp);
        int insert=min_distance_rec(a,b,i,j-1,dp);
        int delete1=min_distance_rec(a,b,i-1,j,dp);
        
        return dp[i][j]=min({replace,insert,delete1})+1;
    }
    
    int min_distance_dp(string& a,string &b,int I,int J,vector<vector<int>>&dp)
    {
        
        for(int i=0;i<=I;i++)
            dp[i][0]=i;
        
        for(int j=0;j<=J;j++)
             dp[0][j]=j;
        
        
        for(int i=1;i<=I;i++)
        {
            for(int j=1;j<=J;j++)
            {
                 
        if(a[i-1]==b[j-1])
        {
              dp[i][j]=dp[i-1][j-1];//min_distance_rec(a,b,i-1,j-1,dp);
        }
        else{
        int replace=min_distance_rec(a,b,i-1,j-1,dp);
        int insert=min_distance_rec(a,b,i,j-1,dp);
        int delete1=min_distance_rec(a,b,i-1,j,dp);
        
                dp[i][j]=min({replace,insert,delete1})+1;
        }  
            }
        }
        
        return dp[I][J];
        
    }
    int minDistance(string word1, string word2) {
     
        
        int n=word1.size();
        
        int m=word2.size();
        
        
          vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        
          return min_distance_dp(word1,word2,n,m,dp);
    }

    //leetcode 132
    
    /*TLE
    // same like matrix multplication
    int count=0;
    int min_cut_rec(string &s,int si, int ei,vector<vector<bool>>&is_pall,vector<vector<int>>&cut_dp)
    {
        
       // count++;
        
        if(cut_dp[si][ei]!=-1)
            return cut_dp[si][ei];
        
        if(si==ei)
            return cut_dp[si][ei]=0;
        
        if(is_pall[si][ei]==true)
            return cut_dp[si][ei]=0;
        
        int min1=(int)1e9;
           for(int i=si;i<ei;i++)
           {
                 int part1=min_cut_rec(s,si,i,is_pall,cut_dp);
               
               int part2=min_cut_rec(s,i+1,ei,is_pall,cut_dp);
               
                 min1=min(part1+part2+1,min1);
                   
           }
        
        return cut_dp[si][ei]=min1;
    }
    
    int minCut(string s) {
       
        
        int n=s.size();
        
          vector<vector<bool>>dp(n,vector<bool>(n,false));
          vector<vector<int>>cut_dp(n,vector<int>(n,-1));
        
          
            for(int gap=0;gap<n;gap++)
            {
                for(int i=0,j=gap;j<n;j++,i++)
                {
                    if(gap==0)
                        dp[i][j]=true;
                    else if(gap==1)
                         dp[i][j]=(s[i]==s[j]);
                    else
                        dp[i][j]=(s[i]==s[j])&& dp[i+1][j-1];
                }
            }
           //cout<<dp[0][n-1];
         int a=min_cut_rec(s,0,n-1,dp,cut_dp);
        //cout<<count<<endl;
            return a;
    }
    
    */
    
  int min_cut_rec(string &s1,int si,vector<int>&cut_dp,vector<vector<bool>>&ispall)
  {
      if(ispall[si][s1.size()-1])
          return cut_dp[si]=0;
      
      
      if(cut_dp[si]!=-1)
          return cut_dp[si];
      
      
      int min1=(int)1e9;
      
      for(int i=si;i<s1.size();i++)
      {
          if(ispall[si][i])
          {
              min1=min(min1,min_cut_rec(s1,i+1,cut_dp,ispall)+1);
          }
      }
      
      return cut_dp[si]=min1;
  }
    
     int minCut(string s) {
         
          int n=s.size();
        
          vector<vector<bool>>dp(n,vector<bool>(n,false));
          vector<int>cut_dp(n,-1);
        
          
            for(int gap=0;gap<n;gap++)
            {
                for(int i=0,j=gap;j<n;j++,i++)
                {
                    if(gap==0)
                        dp[i][j]=true;
                    else if(gap==1)
                         dp[i][j]=(s[i]==s[j]);
                    else
                        dp[i][j]=(s[i]==s[j])&& dp[i+1][j-1];
                }
            }
           //cout<<dp[0][n-1];
         return min_cut_rec(s,0,cut_dp,dp);
        //cout<<count<<endl;
           // return a;           
     }

     //leetcode 1671
      vector<int> lis_lr(vector<int>&nums)
    {
        
        vector<int>dp(nums.size(),0);
        
           for(int i=0;i<nums.size();i++)
           {
               dp[i]=1;
               
               for(int j=i-1;j>=0;j--)
               {
                   if(nums[i]>nums[j])
                   {
                       dp[i]=max(dp[i],dp[j]+1);
                   }
               }
           }
        
        return dp;
    }
    vector<int> lis_rl(vector<int>&nums)
    {
        
        vector<int>dp(nums.size(),0);
        
           for(int i=nums.size()-1;i>=0;i--)
           {
               dp[i]=1;
               
               for(int j=i+1;j<nums.size();j++)
               {
                   if(nums[i]>nums[j])
                   {
                       dp[i]=max(dp[i],dp[j]+1);
                   }
               }
           }
        
        return dp;
    }
    
      
    int minimumMountainRemovals(vector<int>& nums) {
        
        
        vector<int>left=lis_lr(nums);
        vector<int>right=lis_rl(nums);
        
        
           int max1=0;
        
          for(int i=1;i<nums.size()-1;i++)
          {
              /*
		       If the below conditional statement is not given, then strictly increasing or strictly 
			   decreasing sequences will also be considered. It will hence fail in,
			   Test case: [10, 9, 8, 7, 6, 5, 4, 5, 4].
					---Thanks to @chejianchao for suggesting the test case.
				We need to make sure both the LIS on the left and right, ending at index i, 
				has length > 1. 
		   */
               if(left[i]>1 && right[i]>1)
                 max1=max(max1,left[i]+right[i]-1);
          }
        
        
        return nums.size()-max1;
        
          
        
        
        
    }

    //leetcode  304
    class NumMatrix {
public:
    
     vector<vector<int>>pref;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        if(matrix.size()==0 || matrix[0].size()==0)
              return;
        
         pref.resize(matrix.size()+1);
        
         for(vector<int>&arr:pref)
         {
             arr.resize(matrix[0].size()+1,0);
         }
        
          
           for(int i=0;i<matrix.size();i++)
           {
               for(int j=0;j<matrix[0].size();j++)
               {
                   pref[i+1][j+1]=pref[i+1][j]+pref[i][j+1]+matrix[i][j]-pref[i][j];
               }
           }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        
        return pref[row2+1][col2+1] -pref[row1][col2+1]-pref[row2+1][col1]+pref[row1][col1];
    }
    };
       vector<vector<int>>pref_col;
    class NumMatrix1 {
public:
    
    NumMatrix1(vector<vector<int>>& matrix) {
        
        
         pref_col.resize(matrix.size());
         for(vector<int>&arr:pref_col)
         {
             arr.resize(matrix[0].size());
         }
        
          
         for(int i=0;i<matrix[0].size();i++)
          {
              pref_col[0][i]=matrix[0][i];
              
                for(int j=1;j<matrix.size();j++)
                {
                    pref_col[j][i]=pref_col[j-1][i]+matrix[j][i];
                    
                }
              
             
         }
        
    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
     
        
        int sum=0;
        
          for(int i=col1;i<=col2;i++)
          {
              if(row1==0)
                   sum+=pref_col[row2][i];
              else
                  sum+=pref_col[row2][i]-pref_col[row1-1][i];
               
              
             // cout<<sum<<" "<<endl;
          }
        
        
        return sum;
        
    }
    };

    //leetcode 1641
      int countVowelStrings(int n) {
         if(n==0)
             return 0;
        
         if(n==1)
             return 5;
        
           //t a_count=1,e_count=1,i_count=1,o_count=1,u_count=1;
          int sum=5;
          vector<int>a(5,1);
           int l=5;
       for(int j=2;j<=n;j++)
       {
           
          sum=l;
           l=0;
        for(int i=0;i<5;i++)
        {
            int temp=sum;
            sum=sum-a[i];
            a[i]=temp;
            l+=a[i];
        }
           
       }   
        
        return l;
    }

    // leetcode 264
     int nthUglyNumber(int n) {
        
        vector<int>dp(n);
        dp[0]=1;
        
        int i=0,j=0,k=0;
        
         for(int l=1;l<n;l++)
         {
              int a_2=dp[i]*2;
               int b_2=dp[j]*3;
             
               int c_2=dp[k]*5;
             
                   //int min1=(int)1e9;
                  
               dp[l]=min({a_2,b_2,c_2});
             
               if(a_2==dp[l])
               {
                   i++;
               }
             
              if(b_2==dp[l])
               {
                   j++;
               }
             
              if(c_2==dp[l])
               {
                   k++;
               }
            
               
             
              
             
         }
        
        return dp[n-1];
        
        
    }

    //leetcode 313
    // can also be solved using min heap
     int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        
        vector<int>dp(n);
        
          dp[0]=1;
        
          vector<int>indices(primes.size());
        
          for(int i=1;i<n;i++)
          {
              int min1=INT_MAX;
              
                for(int j=0;j<primes.size();j++)
                {
                    min1=min(min1,primes[j]*dp[indices[j]]);
                }
              
              for(int j=0;j<primes.size();j++)
                {
                     if(min1==(primes[j]*dp[indices[j]]))
                     {
                        indices[j]++; 
                     }
                }
              
              dp[i]=min1;
              
              
          }
        return dp[n-1];
    }

    //leetcode 139

        bool wordBreak(string s, vector<string>& word) {
        
        
        
        unordered_set<string>map;
        
           for(auto &str:word)
           {
               map.insert(str);
               
           }
        
        int n=s.size();
         vector<bool>dp(n+1);
        
          dp[0]=true;
        
          //s.insert('&',0);
        
          
          for(int i=1;i<=s.size();i++)
          {
              for(int j=i;j>=1;j--)
              {
                  if(map.find(s.substr(j-1,i-j+1))!=map.end())
                  {
                        dp[i]=dp[i] || dp[j-1];
                       //cout<<i<<" "<<dp[i]<<endl;
                       //cout<<dp[i]<<
                  }
                  
              }
          }
        //cout<<s.size()<<endl;
         // cout<<dp[s.size()]<<endl;
        
          return dp[s.size()];
        
    }

    //length bhi bata dega
    bool wordBreak(string s, vector<string>& word) {
        
        
        
        unordered_set<string>map;
        
           for(auto &str:word)
           {
               map.insert(str);
               
           }
        
        int n=s.size();
         vector<int>dp(n+1,0);
        
          dp[0]=1;
        
          //s.insert('&',0);
        
          
          for(int i=1;i<=s.size();i++)
          {
              for(int j=i;j>=1;j--)
              {
                  if(map.find(s.substr(j-1,i-j+1))!=map.end())
                  {
                        dp[i]+=dp[j-1];
                       // cout<<i<<" "<<dp[i]<<endl;
                       //cout<<dp[i]<<
                  }
                  
              }
          }
        //cout<<s.size()<<endl;
         // cout<<dp[s.size()]<<endl;
        
          return dp[s.size()]>0;
        
    }

    //https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

    	int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    
		    int n=str.size();
		    
		      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
		      
		      for(int i=1;i<=n;i++)
		      {
		          for(int j=1;j<=n;j++)
		          {
		              if(str[i-1]==str[j-1] && i!=j)
		              {
		                  dp[i][j]=dp[i-1][j-1]+1;
		              }
		              else
		                 dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		          }
		      }
		        
		        
		        return dp[n][n];
		}

        //leetcode 1277
          int countSquares(vector<vector<int>>& matrix) {
        
        
            int count=0;
        
               for(int i=1;i<matrix.size();i++)
               {
                   for(int j=1;j<matrix[0].size();j++)
                   {
                        if(matrix[i][j]==1)
                        {
                            matrix[i][j]=min({matrix[i][j-1],matrix[i-1][j-1],matrix[i-1][j]})+1;
                            count+=matrix[i][j];
       //                      cout<<count<<endl;
                        }
                   }
               }
        
          //cout<<count<<endl;
        
        
        for(int i=0;i<matrix.size();i++)
        {
            count+=matrix[i][0];
        }
        
        for(int i=1;i<matrix[0].size();i++)
        {
            count+=matrix[0][i];
        }
        
        
        
        
        return count;
    }

    //leetcode 650
     int min_step_rec(int n,int curr, int paste)
    {
        
        if(curr>=n)
        {
            return (curr==n)?0:(int)1e9;
        }
      
          int p=(int)1e9;
           if(paste>0)
           {
              p=min_step_rec(n,curr+paste,paste)+1;
           }
        
          int copy_paste=min_step_rec(n,curr+curr,curr)+2;
        
          return min(p,copy_paste);
        
    }
    int minSteps(int n) {
        
        if(n==1)
              return 0;
        return min_step_rec(n,1,0);
    }

    //leetcode 632
     int val(vector<int>& sat,int i,int j,vector<vector<int>>&dp)
    {
        
        if(j>=sat.size())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int incl=sat[j]*i+ val(sat,i+1,j+1,dp);
        
        int exc=val(sat,i,j+1,dp);
        
        return dp[i][j]=max(incl,exc);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        
          vector<vector<int>>dp(1000,vector<int>(1000,-1));
    
        return max(val(satisfaction,1,0,dp),0);
    }

    /*
      First thought that should come up in one's head is that I should sort the array. 
      Because in case you need to remove some elements they'll surely be the negative ones. 
      So you might or might not have to remove some elements from the beginning of the sorted array.
First solution is O(n^2) which would easily pass. But not much fast. 
It came out to be faster than 75% solutions only.
Next thought, can I optimize it further? Let's try to write down the sum if I start to take elements from the ith index.
 How would it look like?
ai + 2*ai+1 + 3*ai+2... We can further open it up and write it down as:
 S = (ai + ai+1 + ai+2 +. .. +) + (ai+1 + ai+2 + .. +) + .. + (an-1)
Wait, this looks something familiar. We can write each bracket as suffix sums. Right?
S = suff_i + suff_i+1 + suff_i+2 +.. + suff_n-1
You just need to find i such that this S is maximum. Which is pretty trivial I guess? 
You just have to maintain suffix of suffix array. And return the max of 0 and the maximum element in that array 
*/

int maxSatisfaction(vector<int>& sat) {
        
        sort(sat.begin(),sat.end());
          
        int max1=sat[sat.size()-1];
         for(int i=sat.size()-2;i>=0;i--)
         {
             sat[i]=sat[i+1]+sat[i];
             
         }
        for(int i=sat.size()-2;i>=0;i--)
         {
             sat[i]=sat[i+1]+sat[i];
            max1=max(max1,sat[i]);
             
         }
        
        return max(max1,0);
    }


      //leetcode  312
        
    int burst_ballon(vector<int>&nums,int si,int ei,vector<vector<int>>&dp)
    {
        
       // cout<<si<<" "<<ei<<endl;
        
        if(dp[si][ei]!=-1)
              return dp[si][ei];
        
        int lval=(si==0)?1:nums[si-1];
        
        int rval=(ei==nums.size()-1)?1:nums[ei+1];
        
        
        int max1=0;
        for(int cut=si;cut<=ei;cut++)
        {
            //cout<<si<<" "<<ei<<" "<<cut<<endl;
            int l_ans=(cut==si)?0:burst_ballon(nums,si,cut-1,dp);
            
            int r_ans=(cut==ei)?0:burst_ballon(nums,cut+1,ei,dp);
            
            max1=max(max1,l_ans+lval*nums[cut]*rval+r_ans);
            
        }
        
        
        return dp[si][ei]=max1;
    }
    
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
    
  int max_dp(vector<int>&nums,int si,int ei,vector<vector<int>>&dp)    
  {
      
      for(int gap=0;gap<=ei;gap++)
      {
          for(int i=0,j=gap;j<=ei;j++,i++)
          {
                
              int lval=(i==0)?1:nums[i-1];
        
          int rval=(j==nums.size()-1)?1:nums[j+1];
              int max1=0;
              for(int cut=i;cut<=j;cut++)
              {
                  int l_ans=(cut==i)?0:dp[i][cut-1];//burst_ballon(nums,si,cut-1,dp); 
                   
            
            int r_ans=(cut==j)?0:dp[cut+1][j];//burst_ballon(nums,cut+1,ei,dp);
              
            max1=max(max1,l_ans+lval*nums[cut]*rval+r_ans);
                 // cout<<cut<<" "<<l_ans<<" "<<r_ans<<" "<<max1<<endl;
                   
              }
              
              dp[i][j]=max1;
          }
      }
      
      
      return dp[0][ei];
  }
    int maxCoins(vector<int>& nums) {
        
        
        
        int n=nums.size();
          vector<vector<int>>dp(n,vector<int>(n,0));
        int a= max_dp(nums,0,n-1,dp);
         print2D(dp);
        
          return a;
    }

    //https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1#

    //good concept

    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    
    vector<long>kadane(n);
    
      long cmax=0;
     //  long omax=-(int)1e12;
       
        for(long i=0;i<n;i++)
        {
            cmax=max(cmax+a[i],a[i]);
            //=max(omax,cmax);
             kadane[i]=cmax;     
        }
    
    
        
          
          long w_max=0;
          for(int i=0;i<k;i++)
            w_max+=a[i];
           
            //cout<<w_max<<endl;
          long o_max=w_max;
          
          for(int i=k;i<n;i++)
          {
              w_max=w_max-a[i-k]+a[i];
              //cout<<w_max<<endl;
              if(kadane[i-k]>0)
                o_max=max(o_max,w_max+kadane[i-k]);
             else
               o_max=max(o_max,w_max);
          }
          
          
    
      return o_max;
       
    
}


//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#

 int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        
          vector<vector<int>>dp(m+1,vector<int>(n+1,0));
          
          
          for(int i=1;i<=m;i++)
          {
              for(int j=1;j<=n;j++)
              {
                  if(X[i-1]==Y[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                    
                  else
                   {
                       dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                   }
              }
          }
          
          return m+n-dp[m][n];
    }


    //leetcode 87
    //very tough
     unordered_map<string,bool>map;
    
    bool isScramble(string s1, string s2) {
      
        
        if(s1.size()!=s2.size())
              return false;
        
        
        if(map.find(s1+s2)!=map.end())
             return map[s1+s2];
        
        
        if(s1==s2)
             return map[s1+s2]=true;
        
        
        
        int len=s1.size();
         vector<int>count(26,0);
        
        for(int i=0;i<len;i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        
        for(int i=0;i<26;i++)
        {
            if(count[i]!=0)
                return map[s1+s2]=false;
        }
        
        
        for(int i=1;i<=len-1;i++)
        {
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
            {
                return map[s1+s2]=true;
            }
            
            if(isScramble(s1.substr(0,i),s2.substr(len-i)) && isScramble(s1.substr(i),s2.substr(0,len-i)))
            {
                return map[s1+s2]=true;
            }
            
        }
        
        return map[s1+s2]=false;
    }
    