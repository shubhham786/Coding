#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void print1D(vector<string> &arr)
{
    for (string ele : arr)
    {
        cout <<ele<<" ";
    }
    cout << endl;
}

void print2D(vector<vector<string>> &arr)
{
    for (vector<string> &ar : arr)
    {
        print1D(ar);
    }
}
   //leetcode 516
    //largest pallindrome sequence

     int longestPalindromeSubseq(string &s,int i,int j,vector<vector<int>>&dp)
      {
           if(i>=j)
        {
            return dp[i][j]=(i==j)?1:0;
        }
          
          if(dp[i][j]!=0)
                return dp[i][j];
          
          int count=0;
          if(s[i]==s[j])
          {
              count=longestPalindromeSubseq(s,i+1,j-1,dp);
              
              return dp[i][j]=count+2;
          }
          else
          {
              int l=longestPalindromeSubseq(s,i+1,j,dp);
              int k=longestPalindromeSubseq(s,i,j-1,dp);
              
              return dp[i][j]=max(l,k);
          }
      }
    // int longestPalindromeSubseq(string s) {
        
    //     vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        
    //     int l=longestPalindromeSubseq(s,0,s.size()-1,dp);

    //    // print2D(dp);
    //     cout<<l<<endl;
    //       return l;
    // }

   
     int dp__ll(string &s,int I,int J,vector<vector<int>>&dp)
    {
        
        
     int n=s.size();
        
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(i>=j)
                {
                 dp[i][j]=(i==j)?1:0;
                     continue;
                 }
          
         
          
         // int count=0;
          if(s[i]==s[j])
          {
              dp[i][j]=dp[i+1][j-1]+2;//longestPalindromeSubseq(s,i+1,j-1,dp);
              
              //dp[i][j]=count+2;
          }
          else
          {
              int l=dp[i+1][j];//longestPalindromeSubseq(s,i+1,j,dp);
              int k=dp[i][j-1];//longestPalindromeSubseq(s,i,j-1,dp);
              
               dp[i][j]=max(l,k);
          }
          } 
            }
        
       
      
        
        return dp[I][J];
    }
string sequenece(int i,int j, string &s,vector<vector<int>>&dp)
{
     if(i>=j)
     {
         if(i==j)
         return ""+s[i];
         else
          return "";
     }

      if(s[i]==s[j])
      {
          string l=sequenece(i+1,j-1,s,dp);

          return s[i]+l+s[j];
      }
      else{

          if(dp[i+1][j]>dp[i][j-1])
             return sequenece(i+1,j,s,dp);
          else
            return sequenece(i,j-1,s,dp);   
      }
}

 int longestPalindromeSubseq(string s) {
        
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        
        int l=dp__ll(s,0,s.size()-1,dp);

       // print2D(dp);
      

        cout<<sequenece(0,s.size()-1,s,dp)<<endl;
          return l;
    }
    //https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
      int mod=(int)1e9+7;
    long long int  countPS(string &str,int i, int j,vector<vector<long>>&dp)
    {
        if(i>=j)
        {
            return dp[i][j]=(i==j)?1:0;
        }
        
          if(dp[i][j]!=-1)
             return dp[i][j];
        //if(str[i-1]==str[j-1])
        
        long a=countPS(str,i+1,j-1,dp);
        long b=countPS(str,i+1,j,dp);
        long c=countPS(str,i,j-1,dp);
        
        return dp[i][j]=((str[i]==str[j])?b+c+1:b+c-a+mod)%mod;
    }
        long long int  countPS_dp(string &str,int I, int J,vector<vector<long>>&dp)
    {
        
        for(int gap=0;gap<str.size();gap++)
        {
            for(int i=0,j=gap;j<str.size();i++,j++)
            {
                
        
        
        if(i==j)
        {
           dp[i][j]=1;
             
             continue;
        }
        
          /*if(dp[i][j]!=-1)
             return dp[i][j];*/
        //if(str[i-1]==str[j-1])
        
        long a=dp[i+1][j-1];//countPS(str,i+1,j-1,dp);
        long b=dp[i+1][j];//countPS(str,i+1,j,dp);
        long c=dp[i][j-1];//countPS(str,i,j-1,dp);
        
         dp[i][j]=((str[i]==str[j])?b+c+1:b+c-a+mod)%mod;
            }
            
        }
        
        return dp[I][J];
    }
    
    long long int  countPS(string str)
    {
       int n=str.size();
       
    //    vector<vector<long>>dp(n,vector<long>(n,-1));
       
    //    return countPS(str,0,n-1,dp);
     vector<vector<long>>dp(n,vector<long>(n,0));
       
       return countPS_dp(str,0,n-1,dp);
    }
    // string ka hi dp bana liya humne
     string dp__lli(string &s,int I,int J,vector<vector<string>>&dp)
    {
        
        
     int n=s.size();
        
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(i>=j)
                {
                    if(i==j)
                      dp[i][j]=+s[i];
                    else
                    dp[i][j]="";

                     continue;
                 }
          
         
          
         // int count=0;
          if(s[i]==s[j])
          {
              dp[i][j]=s[i]+dp[i+1][j-1]+s[j];//longestPalindromeSubseq(s,i+1,j-1,dp);
              
              //dp[i][j]=count+2;
          }
          else
          {
              string l=dp[i+1][j];//longestPalindromeSubseq(s,i+1,j,dp);
              string k=dp[i][j-1];//longestPalindromeSubseq(s,i,j-1,dp);
              
               dp[i][j]=(l.size()>k.size()?l:k);
          }
          } 
            }
        
       
      
        print2D(dp);   
        return dp[I][J];
    }
    void longestPalindromeSubseq1(string s) {
        
        vector<vector<string>>dp(s.size(),vector<string>(s.size(),""));
        
        //return dp__lls,0,s.size()-1,dp);

        cout<<dp__lli(s,0,s.size()-1,dp);
    }
    int main()
    {
        longestPalindromeSubseq("aeggfab");

    }

    //leetcode 115
        
    int num_memo(string &s, string &t, int n, int m, vector<vector<int>>&dp)
    {
        if(m==0 && n>=0)
            return dp[n][m]=1;
        
        // if(n==0 && m!=0)
        //     return dp[n][m]=0;
        
        if(dp[n][m]!=-1)
             return dp[n][m];
        
          if(s[n-1]==t[m-1])
          {
              int c=num_memo(s,t,n-1,m-1,dp);
              
              int l=num_memo(s,t,n-1,m,dp);
              
              return  dp[n][m]=c+l;
          }
        else
        {
            return dp[n][m]=num_memo(s,t,n-1,m,dp);
        }
    }
       int num_dp(string &s, string &t, int N, int M, vector<vector<unsigned long>>&dp)
    {
        for(int n=0;n<=N;n++)
        {
            for(int m=0;m<=M;m++)
            {
                 if(m==0)
                 { dp[n][m]=1;
                   continue;
                 }
                if(n<m)
                {
                    dp[n][m]=0;
                    continue;
                }
        
        // if(n==0 && m!=0)
        //     return dp[n][m]=0;
        
        // if(dp[n][m]!=-1)
        //      return dp[n][m];
        
          if(s[n-1]==t[m-1])
          {
//               long c=dp[n-1][m-1];//num_memo(s,t,n-1,m-1,dp);
              
//               long l=dp[n-1][m];//num_memo(s,t,n-1,m,dp);
              
               dp[n][m]=dp[n-1][m-1]+dp[n-1][m];
          }
        else
             dp[n][m]=dp[n-1][m];//num_memo(s,t,n-1,m,dp)
            }
        }

       return (int)dp[N][M];
    }
    int numDistinct(string s, string t) {
        
        
        int n=s.size();
        int m=t.size();
        
        //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        vector<vector<unsigned long>>dp(n+1,vector<unsigned long>(m+1,0));
        return num_dp(s,t,n,m,dp);
    }

    //leetcode 1143
        int longestCommonSubsequence(int n,int m,string &s1, string &s2,vector<vector<int>>&dp)
    {
        if(n==0 || m==0)
            return dp[n][m]=0;
        
        if(dp[n][m]!=-1)
             return dp[n][m];
        
        
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=longestCommonSubsequence(n-1,m-1,s1,s2,dp)+1;
        }
        else
        {
            return dp[n][m]=max(longestCommonSubsequence(n-1,m,s1,s2,dp),longestCommonSubsequence(n,m-1,s1,s2,dp));
        }
        
        
        
    }
    int longestCommonSubsequence_dp(int N,int M,string &s1, string &s2,vector<vector<int>>&dp)
    {
           for(int n=0;n<=N;n++)
           {
               for(int m=0;m<=M;m++)
               {
        if(n==0 || m==0)
        {dp[n][m]=0;
         continue;
        }
        
        // if(dp[n][m]!=-1)
        //      return dp[n][m];
        
        
        if(s1[n-1]==s2[m-1])
        {
             dp[n][m]=dp[n-1][m-1]+1;//longestCommonSubsequence(n-1,m-1,s1,s2,dp)+1;
        }
        else
        {
             dp[n][m]=max(dp[n-1][m],dp[n][m-1]);
        }
           }
           }
        
        return dp[N][M];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        
        return longestCommonSubsequence(n,m,text1,text2,dp);
    }
    
    //leetcode 1035
         int longestCommonSubsequence_dp(int N,int M,vector<int>&s1, vector<int>&s2,vector<vector<int>>&dp)
    {
           for(int n=0;n<=N;n++)
           {
               for(int m=0;m<=M;m++)
               {
        if(n==0 || m==0)
        {dp[n][m]=0;
         continue;
        }
        
        // if(dp[n][m]!=-1)
        //      return dp[n][m];
        
        
        if(s1[n-1]==s2[m-1])
        {
             dp[n][m]=dp[n-1][m-1]+1;//longestCommonSubsequence(n-1,m-1,s1,s2,dp)+1;
        }
        else
        {
             dp[n][m]=max(dp[n-1][m],dp[n][m-1]);
        }
           }
           }
        
        return dp[N][M];
    }
  
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        
        return longestCommonSubsequence_dp(n,m,nums1,nums2,dp);
    }


//leetcode 300

// recusrive

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

//leetcode 1458
     int maxDotProduct(vector<int>& nums1, vector<int>& nums2,int n,int m,vector<vector<int>>&dp)
     {
         
//          if(n-1==0)
//          {
//              int max1=-(int)1e8;
//              for(int j=0;j<m;j++)
//              {
//                  max1=max(max1,nums1[n-1]*nums2[j]);
//              }
             
//              return dp[n][m]=max1;
//          }
         
//           if(m-1==0)
//          {
//              int max1=-(int)1e8;
//              for(int j=0;j<n;j++)
//              {
//                  max1=max(max1,nums2[m-1]*nums1[j]);
//              }
             
//              return dp[n][m]=max1;
//          }
         
         
         if(n==0 || m==0)
              return dp[n][m]=-(int)1e8;
         
         if(dp[n][m]!=-(int)1e9)
             return dp[n][m];
         
         int val=nums1[n-1]*nums2[m-1];
         
         int accepted=maxDotProduct(nums1,nums2,n-1,m-1,dp)+val;
         
         int a=maxDotProduct(nums1,nums2,n,m-1,dp);
         
          int b=maxDotProduct(nums1,nums2,n-1,m,dp);
 
          return dp[n][m]=max(max(val,accepted),max(a,b));
     }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n=nums1.size();
        int m=nums2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-(int)1e9));
        
       return maxDotProduct(nums1,nums2,n,m,dp);
    }

        int maxDotProduct_dp(vector<int>& nums1, vector<int>& nums2,int N,int M,vector<vector<int>>&dp)
     {
         
//          if(n-1==0)
//          {
//              int max1=-(int)1e8;
//              for(int j=0;j<m;j++)
//              {
//                  max1=max(max1,nums1[n-1]*nums2[j]);
//              }
             
//              return dp[n][m]=max1;
//          }
         
//           if(m-1==0)
//          {
//              int max1=-(int)1e8;
//              for(int j=0;j<n;j++)
//              {
//                  max1=max(max1,nums2[m-1]*nums1[j]);
//              }
             
//              return dp[n][m]=max1;
//          }
         
     for(int i=0;i<=M;i++)
         dp[0][i]=-(int)1e8;
      
         for(int i=0;i<=N;i++)
             dp[i][0]=-(int)1e8;
         
       for(int n=1;n<=N;n++)
       {
           for(int m=1;m<=M;m++)
           {
               
           
       
        
//          if(dp[n][m]!=-(int)1e9)
//              return dp[n][m];
         
         int val=nums1[n-1]*nums2[m-1];
         
         int accepted=dp[n-1][m-1]+val;//maxDotProduct(nums1,nums2,n-1,m-1,dp)+val;
         
         int a=dp[n][m-1];//maxDotProduct(nums1,nums2,n,m-1,dp);
         
          int b=dp[n-1][m];//maxDotProduct(nums1,nums2,n-1,m,dp);
 
           dp[n][m]=max(max(val,accepted),max(a,b));
           }
       }
         
         return dp[N][M];
     }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n=nums1.size();
        int m=nums2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        
       int l= maxDotProduct_dp(nums1,nums2,n,m,dp);
//        print2D(dp);
        
        return l;
    }


    //leetcode 72
        int minDistance(string &word1, string &word2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0)
            return dp[i][j]=(i!=0)?i:j;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
          int insert=minDistance(word1,word2,i,j-1,dp);
           int delete1=minDistance(word1,word2,i-1,j,dp);
          int replace=minDistance(word1,word2,i-1,j-1,dp);
        
        
        if(word1[i-1]==word2[j-1])
             return dp[i][j]=replace;
        else
            return dp[i][j]=min(min(insert,delete1),replace)+1;

        
    }
    int minDistance(string word1, string word2) {
        
        int i=word1.size();
        int j=word2.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return minDistance(word1,word2,i,j,dp);
        
        
        
    }

        
    int minDistance_dp(string &word1, string &word2,int I,int J,vector<vector<int>>&dp)
    {
        for(int i=0;i<=I;i++)
            dp[i][0]=i;
        
        for(int j=0;j<=J;j++)
            dp[0][j]=j;
        
        for(int i=1;i<=I;i++)
        {
            for(int j=1;j<=J;j++)
            {
                
        
        
        
        
        
        
                
          int insert=dp[i][j-1];//minDistance(word1,word2,i,j-1,dp);
           int delete1=dp[i-1][j];//minDistance(word1,word2,i-1,j,dp);
          int replace=dp[i-1][j-1];//minDistance(word1,word2,i-1,j-1,dp);
        
        
        if(word1[i-1]==word2[j-1])
             dp[i][j]=replace;
        else
             dp[i][j]=min(min(insert,delete1),replace)+1;
            }
        }
        
        return dp[I][J];
        
    }
    int minDistance(string word1, string word2) {
        
        int i=word1.size();
        int j=word2.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return minDistance_dp(word1,word2,i,j,dp);
        
        
        
    }

      // follow up
    // cost {inserCost,deleteCost,replaceCost}
     int minDistanceWithCost(string word1, string word2, vector<int>&cost, int n, int m, vector<vector<int>>&dp) {
        if (n == 0 || m == 0) {
            return dp[n][m] = (n != 0) ? n * cost[1] : m * cost[0];
        }

        if (dp[n][m] != -1)
            return dp[n][m];

        int insert = minDistanceWithCost(word1, word2, cost, n, m - 1, dp);
        int delete1 = minDistanceWithCost(word1, word2, cost, n - 1, m, dp);
        int replace = minDistanceWithCost(word1, word2, cost, n - 1, m - 1, dp);

        if (word1[n - 1] == word2[m - 1])
            return dp[n][m] = replace + 0;
        else
            return dp[n][m] = min(min(insert + cost[0], delete1 + cost[1]), replace + cost[2]);
    }


    //leetcode 44

    
    string helper(string& p)
    {
        if(p.size()==0)
            return "";
        
        
        string s="";
        
        int i=1;
        int l=p.size();
        s+=p[0];
        while(i<l)
        {
            while(i<l && (p[i-1]=='*') && (p[i]=='*')){
                  i++;
               // cout<<i<<endl;
            }
            
            if(i<l){
                s+=p[i];
             //   cout<<i<<endl;
            }
            i++;
        }
        
        return s;
        
    }
        
    
  //-1->not explored, 1->true,0-> false;
    bool isMatch_memo(string& s, string& l,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0)
        {
            if(i==0 && j==0)
                return dp[i][j]=1;
            else if(j==1 && l[j-1]=='*')
                return dp[i][j]=1;
            else
                return dp[i][j]=0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        char ch1=s[i-1];
        char ch2=l[j-1];
        if(ch1==ch2 || ch2=='?')
           return dp[i][j]=isMatch_memo(s,l,i-1,j-1,dp);
        
        else if(ch2=='*')
        {
            bool res=false;
            res=res||(isMatch_memo(s,l,i-1,j,dp)==1);// map to a charchter
            res=res||(isMatch_memo(s,l,i,j-1,dp)==1);// map to empty string
            
           return dp[i][j]=(res)?1:0;
        }
        else
            return dp[i][j]=0;
            
    }
    
           //-1->not explored, 1->true,0-> false;
    bool isMatch_dp(string& s, string& l,int I,int J,vector<vector<int>>&dp)
    {
        for(int i=0;i<=I;i++)
        {
            for(int j=0;j<=J;j++)
            {
                
        
        if(i==0 || j==0)
        {
            if(i==0 && j==0)
                 dp[i][j]=1;
            else if(j==1 && l[j-1]=='*')
                 dp[i][j]=1;
            else
             dp[i][j]=0;
            
            continue;
            
        }
        
        //if(dp[i][j]!=-1)
            //return dp[i][j];
        
        char ch1=s[i-1];
        char ch2=l[j-1];
        if(ch1==ch2 || ch2=='?')
            dp[i][j]=dp[i-1][j-1];//isMatch(s,l,i-1,j-1,dp);
        
        else if(ch2=='*')
        {
            bool res=false;
            res=res||(dp[i-1][j]==1);// map to a charchter
            res=res||(dp[i][j-1]==1);// map to empty string
            
           dp[i][j]=(res)?1:0;
        }
        else
            dp[i][j]=0;
            }
        }
        
        return dp[I][J];
    }
    bool isMatch(string s, string p) {
        
        string l=helper(p);
       
        
        int n=s.size();
        int m=l.size();
        
       // cout<<n<<" "<<m;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        
         return (isMatch_dp(s,l,n,m,dp)==1);
        
    }

    //leetcode 718
        int result=0;
     int findLength(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>>&dp)
     {
         if(i==0 || j==0)
         {
             return  dp[i][j]=0;
         }
         
         if(dp[i][j]!=-1)
             return dp[i][j];
         
       int a=findLength(nums1,nums2,i-1,j-1,dp);
       int b=findLength(nums1,nums2,i-1,j,dp);  
       int c=findLength(nums1,nums2,i,j-1,dp);
         
       if(nums1[i-1]==nums2[j-1])
       {
           result=max(result,a+1);
           
           return dp[i][j]=a+1;
       }
        else
        {
            result=max(max(result,a),max(b,c));
            
            return dp[i][j]=0;
        }
         
         
     }

         int findLength_dp(vector<int>& nums1, vector<int>& nums2,int I,int J,vector<vector<int>>&dp)
     {
        int result=0;
      for(int i=0;i<=I;i++)
      {
          for(int j=0;j<=J;j++)
          {
              
         
      
         if(i==0 || j==0)
         {
              dp[i][j]=0;
               continue;
         }
         
        //     return dp[i][j];
        
         
       int a=dp[i-1][j-1];//findLength(nums1,nums2,i-1,j-1,dp);
       int b=dp[i-1][j];//findLength(nums1,nums2,i-1,j,dp);  
       int c=dp[i][j-1];//findLength(nums1,nums2,i,j-1,dp);
         
       if(nums1[i-1]==nums2[j-1])
       {
           result=max(result,a+1);
           
            dp[i][j]=a+1;
       }
        else
        {
            result=max(max(result,a),max(b,c));
            
             dp[i][j]=0;
        }
          }
      }
        
         return result;
     }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        
        return findLength_dp(nums1,nums2,nums1.size(),nums2.size(),dp);
          
    }

    //leetcode 5
    string longestPalindrome(string s) {
      
        int l=s.size();
        
        int si=0;
        int len=0;
        vector<vector<int>>dp(l,vector<int>(l));
        
        for(int gap=0;gap<l;gap++)
        {
            for(int i=0,j=gap;j<l;i++,j++)
            {
                if(gap==0)
                { dp[i][j]=1;
                   
                }
                else if(gap==1)
                {
                    dp[i][j]= s[i]==s[j]?2:0;
                }
                else
                {
                    dp[i][j]= s[i]==s[j] && dp[i+1][j-1]!=0 ?dp[i+1][j-1]+2:0;
                    
                    
                }
                
                if(dp[i][j]>len)
                {
                    len=dp[i][j];
                    si=i;
                }
            }
        }
        
         return s.substr(si,len);
    }

    //leetcode 647
        int countSubstrings(string s) {
        
        int l=s.size();
        
        vector<vector<bool>>dp(l,vector<bool>(l,false));
        
        int count=0;
        for(int gap=0;gap<l;gap++)
        {
            for(int i=0,j=gap;j<l;i++,j++)
            {
                if(gap==0)
                    dp[i][j]=true;
                
                else if(gap==1)
                     dp[i][j]= s[i]==s[j];
                
                else
                    dp[i][j]= s[i]==s[j] && dp[i+1][j-1];
                
                if(dp[i][j])
                     count++;
                    
            }
        }
        
        return count;
    }

    //leetcode 940
    int distinctSubseqII(string s) {
        int mod=(int)1e9+7;
        
        
        
        s='$'+s;
        int l=s.size();
        
        vector<int>dp(l,0);
        cout<<dp.size()<<endl;
        dp[0]=1;
        
        vector<int>last_index(26,-1);
       //int idx=s[1]-'a';
        //cout<<last_index[idx]<<endl;
        for(int i=1;i<l;i++)
        {
            dp[i]=(2*dp[i-1])%mod;
            if(last_index[s[i]-'a']!=-1)
            {
                dp[i]=(dp[i]-dp[last_index[s[i]-'a']-1]+mod)%mod;
            }
            
            last_index[s[i]-'a']=i;
        }
        
        
        return dp[l-1]-1;
    }

    //leetcode 1312
       // just like longest pallindromic susbsequence
    
    int minInsertions(string& s,int i, int j,vector<vector<int>>&dp)
    {
        if(i>=j)
            return dp[i][j]= i==j?1:0;
        
        
        if(dp[i][j]!=-1)
             return dp[i][j];
        
        int ans=1;
        if(s[i]==s[j])
            ans=minInsertions(s,i+1,j-1,dp)+2;
        else
            ans=max(minInsertions(s,i+1,j,dp),minInsertions(s,i,j-1,dp));
        
        
        return dp[i][j]=ans;
    }
    
    
    int minInsertions(string s) {
        
     
        
         int l=s.size();
        
          vector<vector<int>>dp(l,vector<int>(l,-1));
        
        return l-minInsertions(s,0,l-1,dp);
        
          
        
    }

    //leetcode 1278
       
    int palindromePartition(string s, int k,int idx,vector<vector<int>>&dp,vector<vector<int>>&dp1) {
        
        
        if(s.size()-idx <=k)
        {
            return dp1[idx][k]= (s.size()-idx==k)?0:(int)1e9;
        }
        
        if(k==1)return  dp1[idx][k]= dp[idx][s.size()-1];
        
        if(dp1[idx][k]!=-1)
             return dp1[idx][k];
        
        int min_ans=(int)1e9;
        
        for(int i=idx;i<s.size()-1;i++)
        {
            int my_ans=dp[idx][i];
            
            int rec_ans=palindromePartition(s,k-1,i+1,dp,dp1);
            
            if(rec_ans!=(int)1e9)
                min_ans=min(min_ans,my_ans+rec_ans);
        }
        
        return dp1[idx][k]=min_ans;
    }
    int palindromePartition(string s, int k) {
        
        
        int l=s.size();
        //cout<<l<<endl;
        vector<vector<int>>dp(l,vector<int>(l,0));
        
        
        for(int gap=1;gap<l;gap++)
        {
            for(int i=0,j=gap;j<l;i++,j++)
            {
                if(gap==1)
                    dp[i][j]= (s[i]==s[j])?0:1;
                else
                    dp[i][j]= (s[i]==s[j])?dp[i+1][j-1]:dp[i+1][j-1]+1;
            }
        }
       // cout<<dp.size()<<endl;
        vector<vector<int>>dp1(l,vector<int>(k+1,-1));
        return palindromePartition(s,k,0,dp,dp1);
    }