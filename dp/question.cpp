#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//70
int climbStairs_memo(int n,vector<int>&dp) {
        
      if(n==0)
      {
          return dp[n]=1;
      }  
      
      if(n==1)
      {
          return dp[n]=1;
      }

      if(dp[n]!=0)
        return dp[n];

        int ans=0;

        ans+= climbStairs_memo(n-1,dp);
        ans+= climbStairs_memo(n-2,dp); 
      
      return dp[n]=ans;
        
    }

int climbStairs_dp(int n,vector<int>&dp) {
        
     for(int i=0;i<=n;i++)
     {
         if(i==0){
             dp[0]=1;
             continue;
         }
         if(i==1)
         {
             dp[1]=1;
             continue;
             
         }
         
        dp[i]=dp[i-1]+dp[i-2];
         
          
                 
     }
        return dp[n];
}

//746
 int minCostClimbingStairs_memo(int n,vector<int>& cost,vector<int>&dp) {
      if(n==0)
        return dp[n]=cost[n];

       if(n==1)
        return dp[n]=cost[n];
        
        if(dp[n]!=0)
           return dp[n];
    
          int cost1=(n==cost.size()?0:cost[n]);

        // cout<<cost1<<endl;
        //piche se call chalye hai
         return dp[n]=cost1+min(minCostClimbingStairs_memo(n-1,cost,dp),minCostClimbingStairs_memo(n-2,cost,dp));  
            
           
}
  int minCostClimbingStairs_dp(int n,vector<int>& cost,vector<int>&dp) {
     
    for(int i=0;i<=n;i++)
    { 
      if(i<=1)
      {
         dp[i]=cost[i];
           continue;
      }    
    
        
       
    
          int cost1=(i==cost.size()?0:cost[i]);

        // cout<<cost1<<endl;
         dp[i]=cost1+min(dp[i-1],dp[i-2]);//min(minCostClimbingStairs_memo(n-1,cost,dp),minCostClimbingStairs_memo(n-2,cost,dp));  

    }       

        return dp[n];   
}

//91
 
    int numDecodings_memo(string s,int idx,vector<int>&dp)
    {
        if(idx==s.length())return dp[idx]=1;
        
         if (dp[idx] != -1)
            return dp[idx];

        int chr1=s[idx]-'0';
        
        if(chr1==0)return dp[idx]=0;
        
        int count=0;
        
         count+=numDecodings_memo(s,idx+1,dp);
        
          if(idx<s.length()-1)
          {
              int ch2=chr1*10+ (s[idx+1]-'0');
              
              if(ch2<=26)
                  count+=numDecodings_memo(s,idx+2,dp);
          }
        
      return  dp[idx]=count;
        
        
        
    }
    
 int numDecodings_dp(string s,int IDX,vector<int>&dp)
    {
      for(int idx=s.length();idx>=IDX;idx--)
      {
        if(idx==s.length()){
          dp[idx]=1;
          continue;
        }
        
        int chr1=s[idx]-'0';
        
        if(chr1==0){
          dp[idx]=0;
          continue;
        }  
        int count=0;
        
         count+=dp[idx+1];//numDecodings_memo(s,idx+1,dp);
        
          if(idx<s.length()-1)
          {
              int ch2=chr1*10+ (s[idx+1]-'0');
              
              if(ch2<=26)
                  count+=dp[idx+2];//numDecodings_memo(s,idx+2,dp);
          }
        
        dp[idx]=count;
      }   
        
        return dp[IDX];
    }
   int numDecodings1(string s)
    {
        int a=1;
       
      int b=0;
        
        if(s[s.size()-1]!='0')
            b=1;
        
        for(int i=s.size()-2;i>=0;i--)
        {
             char ch=s[i];
             int count=0;
             
            if(ch!='0')
            {
                count+=b;
                
                char ch1=s[i+1];
                
                int l=(ch-'0')*10+(ch1-'0');
              //  cout<<l<<endl;
                if(l<=26 && l>=10)
                {
                    count+=a;
                }
                
            }
          
          //  cout<<i<<" "<<a<<" "<<b<<endl;
            a=b;
            b=count;
                  
        }
        
        return b;
      
    }
        int numDecodings(string s) {
       
       // cout<<s.size()<<endl;
        
//         vector<int>dp(s.size()+1,-100);
//       int z=numDecodings(s,0,dp);
//         print1D(dp);
//         return z;
        return numDecodings1(s);
        
    }     