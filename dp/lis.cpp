#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//LDS_downhill
    vector<int> LDS_LR(vector<int>&arr) {
        int n = arr.size();
        vector<int>dp(n);
        int len = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] > arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            len =max(len, dp[i]);
        }

        return dp;
    }

    vector<int>LDS_RL(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n);
        int len = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    dp[i] =max(dp[i], dp[j] + 1);
                }
            }

            len =max(len, dp[i]);
        }

        return dp;
    }

     int LBS_downhill(vector<int>& arr) {
        vector<int>LDS = LDS_LR(arr);
        vector<int>LIS = LDS_RL(arr);

        int len = 0;
        for (int i = 0; i < arr.size(); i++) {
            len = max(len, LDS[i] + LIS[i] - 1);
        }

        return len;
    }

    // leetcode 673
      int findNumberOfLIS(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int>dp(n);
          
        vector<int>count(n);
        
        
        int maxLen=0;
        int maxCount=0;
        
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            count[i]=1;
            
            for(int j=i-1;j>=0;j--)
            {
                if(arr[j]<arr[i])
                {                     
                    if(dp[i]==dp[j]+1)
                    {
                        count[i]+=count[j];
                       // dp[i]=dp[i];
                    }
                    
                    if(dp[j]+1>dp[i])
                    {
                        count[i]=count[j];
                        dp[i]=dp[j]+1;
                    }
                  
                 }
                
              
            }   
              if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxCount = count[i];
            } else if (maxLen == dp[i]) {
                maxCount += count[i];
            }
                
        }

        return maxCount;
        
    }

  
// Back engineering to print all the   of lis-->test on leetcode 673
void lis( vector<vector<int>>&map1,vector<int>&arr,int idx,int len,string ans)
{
    if(len==1)
    {
        cout<<to_string(arr[idx])+" ,"+ ans<<endl;
        return;
    }

         for(int i: map1[len-1])
         {
              if (i < idx && arr[i] < arr[idx]) {
                lis(map1, arr, i, len - 1,  to_string(arr[idx])+" ,"+ans );
            }
         }
        
      
}
void findNumberOfLIS1(vector<int>& arr) {
         
        int n = arr.size();
        vector<int> dp(n);
        int len = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            len =max(len, dp[i]);
        }

        vector<vector<int>>map1(len+1);

   
      for(int i=0;i<n;i++)
      {
          map1[dp[i]].push_back(i);
      }
     
    
    
      for( int i: map1[len])
      {
          lis(map1,arr,i,len,"");
      }


    
 }   


 // https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
        

int buildingBridges(vector<vector<int>> &arr)
{
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

// 354->same as buliding bridges
int  maxEnvelopes(vector<vector<int>> &arr)
    {
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
