#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define unsigned long int u_int;
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

// coin change permutation
//{2,3,5,7}, tar=10


int coin_permutation(vector<int>&nums,int tar,string s)
{
      if(tar==0)
      {
          cout<<s<<endl;
          return 1;
      }


      int count=0;

      for(int i=0;i<nums.size();i++)
      {
          if(tar-nums[i] >=0)
           count+= coin_permutation(nums,tar-nums[i],s+to_string(nums[i])+" ");
      }


      return count;
}

int coin_permutation_memo(vector<int>&nums,int tar,vector<int>&dp)
{
      if(tar==0)
      {
          //cout<<s<<endl;
          return dp[tar]=1;
      }



      if(dp[tar]!=-1)
         return dp[tar];



      int count=0;

      for(int i=0;i<nums.size();i++)
      {
          if(tar-nums[i] >=0)
           count+= coin_permutation_memo(nums,tar-nums[i],dp);
      }


      return dp[tar]=count;
}

int coin_permutation_dp(vector<int>&nums,int tar,vector<int>&dp)
{

    for(int j=0;j<=tar;j++)
    {
      if(j==0)
      {
          //cout<<s<<endl;
           dp[j]=1;
          continue;
      }

      int count=0;

      for(int i=0;i<nums.size();i++)
      {
          if(j-nums[i] >=0)
             count+= dp[j-nums[i]];//coin_permutation_memo(nums,tar-nums[i],dp);
      }

    
      dp[j]=count;

    }

    return dp[tar];
}

 int coinChangePermutation_DP(vector<int>&arr, int Tar, vector<int>&dp) {
        dp[0] = 1;
        for (int tar = 0; tar <= Tar; tar++) {
            for (int ele : arr) {
                if (tar - ele >= 0) {
                    dp[tar] += dp[tar - ele];
                }
            }
        }

        return dp[Tar];
    }

int coin_combination(vector<int>&nums,int tar,string s,int idx)
{
      if(tar==0)
      {
          cout<<s<<endl;
          return 1;
      }


      int count=0;

      for(int i=idx;i<nums.size();i++)
      {
          if(tar-nums[i] >=0)
           count+= coin_combination(nums,tar-nums[i],s+to_string(nums[i])+" ",i);
      }


      return count;
}

int coin_combination_memo(vector<int>&nums,int tar,int li,vector<vector<int>>&dp)
{

      if(tar==0)
      {
         // cout<<s<<endl;
          return dp[li][tar]=1;
      }

       if(dp[li][tar]!=-1)
            return dp[li][tar];


      int count=0;

      for(int i=li;i>=0;i--)
      {
          if(tar-nums[i] >=0)
           count+= coin_combination_memo(nums,tar-nums[i],i,dp);
      }


      return dp[li][tar]=count;
}




  int coin_change_1dp(int Tar, vector<int>& coins,vector<int>&dp)
    {
      //  dp[0]=1;
          for(int &ele:coins)
          {
              for(int i=0;i<=Tar;i++)
              {
                  if(i==0)
                  {dp[i]=1;
                   continue;
                  }
                  
                  if(i-ele>=0)
                      dp[i]+=dp[i-ele];
                      
              }
          }
        
        return dp[Tar];
    }


  int change1(int amount, vector<int>& coins) {
        
        vector<int>dp(amount+1,0);
        
        return coin_change_1dp(amount,coins,dp);
        
    }





 int coinChangecombination_1DP(vector<int>&arr, int Tar, vector<int>&dp) {
        dp[0] = 1;
        for (int ele : arr){
            
            for (int tar = 0; tar <= Tar; tar++)  {
                if (tar - ele >= 0) {
                    dp[tar] += dp[tar - ele];
                }
            }
        }

        return dp[Tar];
    }
int main()
{
    vector<int>arr={2,3,5,7};
   int tar=10;     
  int n =arr.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1)); 
//       vector<int>dp(tar+1,-1);
//       cout<<"coin permutation"<<endl;
//       cout<<coin_permutation(arr,tar,"")<<endl;

//     coin_permutation_memo(arr,tar,dp);
 
//     cout<<"dp_memo"<<endl;
//     print1D(dp);

//     vector<int>dp1(tar+1,-1);
   
//    cout<<"dp_tabulation"<<endl;
//     coin_permutation_dp(arr,tar,dp1);
//     print1D(dp1);

//       cout<<"***********"<<endl;

//       cout<<"coin combination"<<endl;
//        cout<<coin_combination(arr,10,"",0)<<endl;

}
//questions
//leetcode 518
 int change1_memo(int tar,int li, vector<int>& coins,vector<vector<int>>&dp)
    {
        if(tar==0)
        {
            return dp[li][tar]=1;
        }
        
         if(dp[li][tar]!=-1)
            return dp[li][tar];
        
        int count=0;
        for(int i=li;i>=0;i--)
        {
             if(tar-coins[i]>=0)
                 count+=change1_memo(tar-coins[i],i,coins,dp);
        }
        
        
        return dp[li][tar]=count;
    }
    
    
  int change(int amount, vector<int>& coins) {
        
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        
        return change1_memo(amount,coins.size()-1,coins,dp);
        
    }

     int coin_change_1dp(int Tar, vector<int>& coins,vector<int>&dp)
    {
      //  dp[0]=1;
          for(int &ele:coins)
          {
              for(int i=0;i<=Tar;i++)
              {
                  if(i==0)
                  {dp[i]=1;
                   continue;
                  }
                  
                  if(i-ele>=0)
                      dp[i]+=dp[i-ele];
                      
              }
          }
        
        return dp[Tar];
    }
  int change(int amount, vector<int>& coins) {
        
        vector<int>dp(amount+1,0);
        
        return coin_change_1dp(amount,coins,dp);
        
    }

    //leetcode 377
     
    
    // int combinationSum4(vector<int>& nums, int Tar) {
        
    //     vector<u_int>dp(Tar+1,0);
       
        
    //     dp[0] = 1;
    //     for (int tar = 0; tar <= Tar; tar++) {
    //         for (int ele : nums) {
    //             if (tar - ele >= 0) {
    //                 dp[tar] += dp[tar - ele];
    //             }
    //                }
    //     }


        
    //     return (u_int)dp[Tar];
    // }

    //leetcode 322
     int count(vector<int>& coins, int tar,vector<int>&dp)
    {
        if(tar==0)
        {
            return dp[tar]=0;
        }
        
        if(dp[tar]!=-1)
            return dp[tar];
        
        int count1=(int)1e9;
        
        for(int i=0;i<coins.size();i++)
        {
            if(tar-coins[i]>=0)
                count1=min(count1,count(coins,tar-coins[i],dp)+1);
        }
        
        return dp[tar]=count1;
     
}


int count_dp(vector<int>& coins, int Tar,vector<int>&dp)
{
      for(int tar=0;tar<=Tar;tar++)
      {   
        if(tar==0)
        {
             dp[tar]=0;
              continue;
        }
        
       
        
        
        int count1=(int)1e9;
        
        for(int i=0;i<coins.size();i++)
        {
            if(tar-coins[i]>=0)
                count1=min(count1,dp[tar-coins[i]]+1);//count(coins,tar-coins[i],dp)+1);
        }
        
         dp[tar]=count1;
      }    
       
      return dp[Tar];
}
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,0);
        int l=count_dp(coins,amount,dp);
        return l==(int)1e9?-1:l;
    }


    //https://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/

    // coin change jaisa ho gaya hai
        int numberOfSolution(vector<int>&arr, int Tar) {
          vector<int>dp(Tar+1);

        for (int tar = 0; tar <= Tar; tar++) {
            for (int ele : arr) {
                if (tar - ele >= 0)
                    dp[tar] += dp[tar - ele];
            }
        }

        return dp[Tar];
    }

     int numberOfSolution(vector<int>arr, int Tar, int aTar, int idx, vector<int>&coff) {
        if (Tar == 0) {
            for (int i = 0; i < arr.size(); i++) {
                cout<<arr[i]<< "(" << coff[i] << ")";
                if (i != arr.size() - 1)
                    cout<<" + ";
            }

            cout<<" = " + aTar;

            return 1;
        }

        int count = 0;
        for (int i = idx; i < arr.size(); i++) {
            if (Tar - arr[i] >= 0) {
                coff[i]++;
                count += numberOfSolution(arr, Tar - arr[i], aTar, i, coff);
                coff[i]--;
            }
        }

        return count;
    }

     void numberOfSolution() {
        vector<int> arr = { 2, 3, 5, 7 };
        int tar = 10;
        vector<int>coeff(arr.size(),0);
        cout<<numberOfSolution(arr, tar, tar, 0,coeff);
    }

    //https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming#


    int isSubsetSum1(int N, int arr[], int sum,int idx,vector<vector<int>>&dp)
    {
        if(idx==N || sum==0)
        {
            return dp[idx][sum]=(sum==0)?1:0;
        }
        
        if(dp[idx][sum]!=-1)
             return dp[idx][sum];
        
        bool res=false;
        if(sum-arr[idx]>=0)
           res=res || (isSubsetSum1(N,arr,sum-arr[idx],idx+1,dp)==1);
        
         res=res || (isSubsetSum1(N,arr,sum,idx+1,dp)==1);
        
        return dp[idx][sum]= res?1:0;
    }
    
    
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        
        return isSubsetSum1(N,arr,sum,0,dp)==1;
    }

      int isSubsetSum2(int n, int arr[], int sum,vector<vector<int>>&dp)
    {
        if(n==0 || sum==0)
        {
            return dp[n][sum]=(sum==0)?1:0;
        }
        
        if(dp[n][sum]!=-1)
             return dp[n][sum];
        
        bool res=false;
        if(sum-arr[n-1]>=0)
           res=res || (isSubsetSum2(n-1,arr,sum-arr[n-1],dp)==1);
        
         res=res || (isSubsetSum2(n-1,arr,sum,dp)==1);
        
        return dp[n][sum]= res?1:0;
    }
    
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        
        return isSubsetSum2(N,arr,sum,dp)==1;
    }

     bool targetSum_DP(vector<int>&arr, int Tar) {
        int N = arr.size();

        vector<vector<bool>>dp(N + 1,vector<bool>(Tar+1));// = new boolean[][Tar + 1];

        for (int n = 0; n <= N; n++) {
            for (int tar = 0; tar <= Tar; tar++) {
                if (n == 0 || tar == 0) {
                    dp[n][tar] = (tar == 0);
                    continue;
                }

                if (tar - arr[n - 1] >= 0)
                    dp[n][tar] = dp[n][tar] || dp[n - 1][tar - arr[n - 1]];
                dp[n][tar] = dp[n][tar] || dp[n - 1][tar];
            }
        }

        return dp[N][Tar];
    }

    //leetcode 416
        bool canPartition(vector<int>& nums) {
         int sum=0;
        
        for(int &ele:nums)
            sum+=ele;
        
        
        if(sum%2==1)
            return false;
        
        int tar=sum/2;
        
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(tar+1));
        
        
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=tar;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=(j==0);
                    continue;
                }
                
                //cout<<i<<endl;
                if(j-nums[i-1] >=0)
                  dp[i][j]=dp[i][j] || dp[i-1][j-nums[i-1]];
                
                dp[i][j]=dp[i][j] || dp[i-1][j];
            }
        }
        
        
        return dp[n][tar];
    }

    //leetcode 494

     int findTargetSumWays(vector<int>& nums, int tar,int n)
    {
        if(n==0)
        {
            return (n==0 && tar==0)?1:0;
        }
        
        
          int count=0;
       
            count+=findTargetSumWays(nums,tar-nums[n-1],n-1);
        
          count+=findTargetSumWays(nums,tar+nums[n-1],n-1);
        
        return count;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
     return findTargetSumWays(nums,target,nums.size());
    }


        int findTargetSumWays(vector<int>& nums, int tar,int sum,int n,vector<vector<int>>&dp)
    {
        if(n==nums.size())
        {
            return  dp[n][sum]=(tar==sum)?1:0;
        }
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        
          int count=0;
       
            count+= findTargetSumWays(nums,tar,sum-nums[n],n+1,dp);
        
          count+=findTargetSumWays(nums,tar,sum+nums[n],n+1,dp);
        
        return dp[n][sum]=count;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        
        for(int &ele:nums)
            sum+=ele;
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*sum + 1,-1));
        
        
     return findTargetSumWays(nums,target+sum,sum,0,dp);
    }

     int targetSumTotalWays_DP(vector<int>&arr, int Tar) {
        int N = arr.size();
        vector<vector<int>>dp(N + 1,vector<int>(Tar+1));

        for (int n = 0; n <= N; n++) {
            for (int tar = 0; tar <= Tar; tar++) {
                if (n == 0 || tar == 0) {
                    dp[n][tar] = (tar == 0) ? 1 : 0;
                    continue;
                }

                if (tar - arr[n - 1] >= 0)
                    dp[n][tar] += dp[n - 1][tar - arr[n - 1]];
                dp[n][tar] += dp[n - 1][tar];
            }
        }

        return dp[N][Tar];
    }

    //https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

         int knapSack(int w, int wt[], int val[], int n,vector<vector<int>>&dp)
         {
             if(n==0 || w==0)
               return dp[n][w]=0;
               
               if(dp[n][w]!=-(int)1e9)
                 return dp[n][w];
                 
            int max_value=0;
            
            if(w-wt[n-1]>=0)
               max_value=knapSack(w-wt[n-1],wt,val,n-1,dp)+val[n-1];
            
            max_value=max(max_value,knapSack(w,wt,val,n-1,dp));
            
            
            return dp[n][w]=max_value;
         }

  int knapSack_dp(int W, int wt[], int val[], int N,vector<vector<int>>&dp)
         {
             for(int n=0;n<=N;n++)
             {
                 for(int w=0;w<=W;w++)
                 {

                
             
             if(n==0 || w==0)
               { dp[n][w]=0;
               continue;
               }
               
/*               if(dp[n][w]!=-(int)1e9)
                 return dp[n][w];
                 
*/            int max_value=0;
            
            if(w-wt[n-1]>=0)
               max_value=dp[n-1][w-wt[n-1]]+val[n-1];
            
            max_value=max(max_value,dp[n-1][w]);
            
            
            dp[n][w]=max_value;
                 }
             }

             return dp[N][W];
         }


    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       
       return knapSack_dp(W,wt,val,n,dp);
    }

    //https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1


       int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int>dp(W+1);
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                 int max_cost=0;
                 
                 if(j-wt[i]>=0)
                  max_cost=dp[j-wt[i]]+val[i];
                  
                  dp[j]=max(dp[j],max_cost);  
            }
        }
        
        return dp[W];
    }

    //leetcode 698

     bool canPartitionKSubsets(vector<int>& nums, int k,int idx, int sum_so,int tar,vector<bool>&vis)
    {
        if(k==0)return true;
        
        if(sum_so>tar)return false;
        
        if(sum_so==tar)
        {
            return canPartitionKSubsets(nums,k-1,0,0,tar,vis);
        }
        
        bool res=false;
        
          for(int i=idx;i<nums.size();i++)
          {
              if(vis[i])
                  continue;
              
              vis[i]=true;
              res=res||canPartitionKSubsets(nums,k,i+1,sum_so+nums[i],tar,vis);
              vis[i]=false;
          }
        
        return res;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int max_ele=0;
          for(int &ele:nums)
          {sum+=ele;
             max_ele=max(max_ele,ele);
          }
        
        if(sum%k!=0 || max_ele> sum/k )return false;
        
        vector<bool>vis(nums.size(),false);
        return canPartitionKSubsets(nums,k,0,0,sum/k,vis);
    }