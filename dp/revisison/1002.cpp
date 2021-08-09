#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
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