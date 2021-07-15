#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//leetcode 300

//recusrive

  // back faith
    int global=1;
    int lengthOfLIS(vector<int>& nums,int n)
    {
        if(n==0)
             return 1;
        
        int ans=1;
        for(int i=n-1;i>=0;i--)
        {
            int l=lengthOfLIS(nums,i);
            
              if(nums[n]>nums[i]){
                   ans=max(ans,l+1);
                 //cout<<n<<" "<<i<<" "<<ans<<endl;
              }
        }
        
         global=max(global,ans);
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        
       int l=  lengthOfLIS(nums,nums.size()-1);
           return global;
    }

    // front faith
        int global=1;
    int lengthOfLIS(vector<int>& nums,int n)
    {
        if(n==nums.size()-1)
             return 1;
        
        int ans=1;
        for(int i=n+1;i<nums.size();i++)
        {
            int l=lengthOfLIS(nums,i);
            
              if(nums[n]<nums[i]){
                   ans=max(ans,l+1);
                 //cout<<n<<" "<<i<<" "<<ans<<endl;
              }
        }
        
         global=max(global,ans);
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        
       int l=  lengthOfLIS(nums,0);
           return global;
    }

    //memo
        int global=1;
    int lengthOfLIS(vector<int>& nums,int n,vector<int>&dp)
    {
        if(n==nums.size()-1)
             return dp[n]=1;
        
        if(dp[n]!=0)
            return dp[n];
        
        int ans=1;
        for(int i=n+1;i<nums.size();i++)
        {
            int l=lengthOfLIS(nums,i,dp);
            
              if(nums[n]<nums[i]){
                   ans=max(ans,l+1);
                 //cout<<n<<" "<<i<<" "<<ans<<endl;
              }
        }
        
         global=max(global,ans);
        return dp[n]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>dp(nums.size(),0);
       int l=  lengthOfLIS(nums,0,dp);
           return global;
    }

      int lengthOfLIS(vector<int>& nums,vector<int>&dp) {
         
         int max1=1;
         for(int i=0;i<nums.size();i++)
         {
             dp[i]=1;
              for(int j=i-1;j>=0;j--)
              {
                  if(nums[i]>nums[j])
                      dp[i]=max(dp[i],dp[j]+1);
              }
              
             max1=max(max1,dp[i]);
         }
        
         
         return max1;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>dp(nums.size());
        return lengthOfLIS(nums,dp);
    }




      // minimum Number of deletion to be performed to make array sorted (array
    // contain -1e7 <= ele <= 1e7)
     int minDeletion(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n); 
        int len = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] <= arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            len = max(len, dp[i]);
        }

        return n - len;
    }


    //https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#


    	int maxSumIS(int arr[], int n)  
	{  
	    int max1=1;
	    vector<int>dp(n);
	     
	     for(int i=0;i<n;i++)
	     {
	         dp[i]=arr[i];
	         
	         for(int j=i-1;j>=0;j--)
	         {
	             if(arr[i]>arr[j])
	             {
	                 dp[i]=max(dp[i],dp[j]+arr[i]);
	             }
	         }
	         
	         max1=max(max1,dp[i]);
	     }
	    
	    return max1;
	}



     // Maximum Sum Increasing Subsequence of Maximum Length.
    //  class sumlen{
    //     public:

    //        int len=1;
    //        int sum=0;
    //          sumlen(){

    //          }

    //         sumlen(int len1,int sum1)
    //         {
    //             this->len=len1;
    //             this->sum=sum1;
    //         }
       
    //  };

    // //  bool comp(sumlen a, sumlen b)
    // //  {
    // //      if(a.len>b.len)
    //           return true;
    //      else if(a.len==b.len)
    //           return a.sum>b.sum;  
    //      else 
    //      return false;     
               
    //  }

    //  sumlen maximumSumLIS(vector<int>&arr) {


    //     vector<sumlen>dp(arr.size());

    //        sumlen max1(1,arr[0]);

    //        for(int i=0;i<arr.size();i++)
    //        {
    //             sumlen z(1,arr[i]);
    //               dp[i]=z;
    //             // dp[i].len=1;
    //             // dp[i].sum=arr[i];
    //              for(int j=i-1;j>=0;j--)
    //             {
    //                 if(arr[i]>arr[j])
    //                 {
    //                     int len=dp[i].len;

    //                     if(len>dp[j].len+1)
    //                     {
    //                         dp[i]=dp[j];
    //                     }
    //                     else if(len=dp[j].len+1)
    //                     {
    //                         if(dp[i].sum>dp[j].sum)
    //                            dp[i].sum=dp[j].sum;
    //                     }
    //                 }
    //             }

    //             //max1=max(max1,dp[i],comp);
    //             if(max1.len<dp[i].len)
    //                {
    //                    max1=dp[i];
    //                }
    //             else if(max1.len==dp[i].len)
    //             {
    //                 max1.sum=max(max1.sum,dp[i].sum);
    //             }   
    //        }
    //     return max1;
    // }

    // int main()
    // {
    //     vector<int>arr={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};

    //     //    sumlen z(1,2);
              
    //     //      cout<<z.len;
    //     //      cout<<z.sum;
    //     //  sumlen l=maximumSumLIS(arr);

    //     //   cout<<l.len<<endl;

    //       return 0; 
    // }


//https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1#


	int lis_lr(vector<int>&nums,vector<int>&dp)
	{
	   
	   int max1=1; 
	  for(int i=0;i<nums.size();i++)
	  {
	    //int max1=1;
	    dp[i]=1;
	    for(int j=i-1;j>=0;j--)
	    {
	        if(nums[i]>nums[j])
	        {
	            dp[i]=max(dp[i],dp[j]+1);
	        }
	    }
	    
	    max1=max(dp[i],max1);
	  }
	  
	  
	  return max1;
	}
	
	int lis_rl(vector<int>&nums,vector<int>&dp)
	{
	   
	   int max1=1; 
	  for(int i=nums.size()-1;i>=0;i--)
	  {
	    //int max1=1;
	    dp[i]=1;
	    for(int j=i+1;j<nums.size();j++)
	    {
	        if(nums[i]>nums[j])
	        {
	            dp[i]=max(dp[i],dp[j]+1);
	        }
	    }
	    
	    max1=max(dp[i],max1);
	  }
	  
	  
	  return max1;
	}
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    
	    
	    vector<int>dp(nums.size());
	    vector<int>dp1(nums.size());
	    
	   lis_lr(nums,dp);
	   lis_rl(nums,dp1);
	    int max1=1;
	    for(int i=0;i<nums.size();i++)
	    {
	        max1=max(max1,dp[i]+dp1[i]-1);
	    }
	    
	    
	    return max1;
	}

//https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence1857/1#


void lis_lr(int arr[],int n,vector<int>&dp)
{
    
    for(int i=0;i<n;i++)
    {
        dp[i]=arr[i];
        
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
               dp[i]=max(dp[i],dp[j]+arr[i]);
        }
    }
}

void lis_rl(int arr[],int n,vector<int>&dp)
{
    
    for(int i=n-1;i>=0;i--)
    {
        dp[i]=arr[i];
        
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
               dp[i]=max(dp[i],dp[j]+arr[i]);
        }
    }
}
int maxSumBS(int arr[] , int n )
{
    
    
    vector<int>dp(n);
    vector<int>dp1(n);
    
    lis_lr(arr,n,dp);
    lis_rl(arr,n,dp1);
    
    int max1=1;
    for(int i=0;i<n;i++)
    {
        max1=max(max1,dp[i]+dp1[i]-arr[i]);
    }
    
    
    return max1;
}


//leetcode 673
int lis_lr(vector<int>&nums,vector<int>&dp,vector<int>&count)
{
   
    int max_len=0;
    int no_of_max_lis=0;
    int n=nums.size();
    
       for(int i=0;i<n;i++)
       {
           dp[i]=1;
           count[i]=1;
           for(int j=i-1;j>=0;j--)
           {
               if(nums[i]>nums[j])
                  //dp[i]=max(dp[i],dp[j]+1);
                {
                      if(dp[j]+1>dp[i])
                      {
                          dp[i]=dp[j]+1;
                          count[i]=count[j];
                          
                      }
                     else if(dp[j]+1==dp[i])
                     {
                         count[i]+=count[j];
                     }
               }
               
                   
           }
           
           if(dp[i]>max_len)
           {
               max_len=dp[i];
               no_of_max_lis=count[i];
           }
           else if(max_len==dp[i])
           {
               no_of_max_lis+=count[i];
           }    
               
       }
    
      return no_of_max_lis;
    
    
}
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<int>dp(nums.size());
        vector<int>count(nums.size());
        return lis_lr(nums,dp,count);
    }


    void dfs_print(vector<vector<int>>&map, int idx, int len,vector<int>&nums,string s)
   {

       if(len==1)
         {
             cout<<s+to_string(nums[idx])+" "<<endl;
             return;
         }


       for(int i:map[len-1])
       {
           if(i<idx && nums[i]<nums[idx])
           {
               dfs_print(map,i,len-1,nums,s+to_string(nums[idx])+" ");
           }
       }
   }


    int print_all_lis(vector<int>&nums)
    {

        vector<int>dp(nums.size());

         int max1=1;
         for(int i=0;i<nums.size();i++)
         {
             dp[i]=1;
              for(int j=i-1;j>=0;j--)
              {
                  if(nums[i]>nums[j])
                      dp[i]=max(dp[i],dp[j]+1);
              }
              
             max1=max(max1,dp[i]);
         }
        
        vector<vector<int>>map(max1+1);


           for(int i=0;i<dp.size();i++)
           {
               map[dp[i]].push_back(i);

           } 


           for(int &i:map[max1])
           {
                 dfs_print(map,i,max1,nums,"");
           }
        
        //return 3;
         
    }

    // {{sp1,ep1},{sp2,ep2}.....}
int buildingBridges(vector<vector<int>> &arr)
{

    // important

    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
        return a[0] < b[0]; // this < other, default behaviour.
        // return b[0] < a[0];  // other < this, reverse default behaviour.
    });

    int n = arr.size();
    vector<int> dp(n, 0);
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j][0] < arr[i][0] && arr[j][1] < arr[i][1])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        len = max(len, dp[i]);
    }

    return len;
}


//leetcode 354
    int maxEnvelopes(vector<vector<int>>& env) {
        
        sort(env.begin(),env.end(),[](vector<int>&a,vector<int>&b){
            
            return a[0]<b[0];
        });
        
        
        vector<int>dp(env.size());
        
        
        int max1=1;
        for(int i=0;i<env.size();i++)
        {
            dp[i]=1;
            
            for(int j=i-1;j>=0;j--)
            {
                if(env[i][0]>env[j][0] && env[i][1]>env[j][1])
                    dp[i]=max(dp[i],dp[j]+1);
                
            }
            
            
            max1=max(max1,dp[i]);
        }
        
        
        
        
        return max1;
                     
        
    }


    int main()
    {
        vector<int>arr={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};


    }