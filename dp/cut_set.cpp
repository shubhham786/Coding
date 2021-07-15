#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//  int matrixMultiplication(int arr[],int si, int ei,vector<vector<int>>&dp)
//      {
//          if(si+1==ei)
//            return dp[si][ei]=0;
           
           
//            if(dp[si][ei]!=-1)
//               return dp[si][ei];
              
//            int min_ans=(int)1e9;
           
//            for(int cut=si+1; cut<ei;cut++)
//            {
//                int lans=matrixMultiplication(arr,si,cut,dp);
//                int rans=matrixMultiplication(arr,cut,ei,dp);
               
               
//                int res=lans+rans+arr[si]*arr[cut]*arr[ei];
               
//                min_ans=min(min_ans,res);
//            }
           
           
//            return dp[si][ei]=min_ans;
//      }

//     int matrixMultiplication(int N, int arr[])
//     {
//         // code here
//         vector<vector<int>>dp(N,vector<int>(N,-1));
//         return matrixMultiplication(arr,0,N-1,dp);
//     }
//      int matrixMultiplication_dp(int n,int arr[],int Si, int Ei,vector<vector<int>>&dp)
//      {
         
//          for(int gap=1;gap<n;gap++)
//          {
//              for(int si=0,ei=gap;ei<n;si++,ei++)
//              {
//                      if(si+1==ei)
//                    { 
//                        dp[si][ei]=0;
//                         continue;
//                    }        
           
           
// /*           if(dp[si][ei]!=-1
//               return dp[si][ei];
// */              
//            int min_ans=(int)1e9;
           
//            for(int cut=si+1; cut<ei;cut++)
//            {
//                int lans=dp[si][cut];//matrixMultiplication(arr,si,cut,dp);
//                int rans=dp[cut][ei];//matrixMultiplication(arr,cut,ei,dp);
               
               
//                int res=lans+rans+arr[si]*arr[cut]*arr[ei];
               
//                min_ans=min(min_ans,res);
//            }
           
//            dp[si][ei]=min_ans;       
//              }
//          }
//        return dp[Si][Ei];      
     
// }

        
     

//     int matrixMultiplication(int N, int arr[])
//     {
//         // code here
//         vector<vector<int>>dp(N,vector<int>(N));
//         return matrixMultiplication_dp(N,arr,0,N-1,dp);
//     }

//      // cost of one multiplication is 3$ and cost of 1 addition is 5$.
//      int mcm_dp2(vector<int>arr, int SI, int EI, vector<vector<int>>&dp) {

//         int n = arr.size();
//         for (int gap = 1; gap < n; gap++) {
//             for (int si = 0, ei = gap; ei < n; si++, ei++) {
//                 if (si + 1 == ei) {
//                     dp[si][ei] = 0;
//                     continue;
//                 }

//                 int minAns = (int) 1e9;
//                 for (int cut = si + 1; cut < ei; cut++) {
//                     int lans = dp[si][cut];// mcm_memo(arr, si, cut, dp);
//                     int rans = dp[cut][ei];// mcm_memo(arr, cut, ei, dp);

//                     minAns = min(minAns, lans + arr[si] * (3 * arr[cut] + 5 * (arr[cut] - 1)) * arr[ei] + rans);
//                 }

//                 dp[si][ei] = minAns;
//             }
//         }

//         return dp[SI][EI];
//     }


// //    https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1#

       
//      pair<string,int> matrixChainOrder(int p[],int si, int ei,vector<vector<pair<string,int>>>&dp)
//      {
//          if(si+1==ei)
//           { 
//              pair<string,int>a;
//              a.first="";
//                a.first+='A'+si;
              
//              a.second=0;
             
//                return dp[si][ei]=a;
//           }
          
//           if(dp[si][ei].second!=0)
//           {
//                return dp[si][ei];
//           }
//             int max_ans=(int)1e9;
//             string s="";
//             for(int cut=si+1;cut<ei;cut++)
//             {
                
//                 pair<string,int>b=matrixChainOrder(p,si,cut,dp);
//                 pair<string,int>c=matrixChainOrder(p,cut,ei,dp);
                
//                 if(max_ans > b.second+c.second+p[si]*p[cut]*p[ei])
//                 {
//                     max_ans=b.second+c.second+p[si]*p[cut]*p[ei];
//                     s.erase();
//                     s="("+b.first+c.first+")";
//                 }
//             }
           
//             return dp[si][ei]={s,max_ans};
//      }
    
//     string matrixChainOrder(int p[], int n){

//    vector<vector<pair<string,int>>>dp(n,vector<pair<string,int>>(n));
//         pair<string,int>z=matrixChainOrder(p,0,n-1,dp);
        
//           return z.first;
//     }


//     //https://www.geeksforgeeks.org/minimum-maximum-values-expression/

//    #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>
// using namespace std;
//    class pair1{
        
//          public:
//               int min_value=(int)1e9;
//               int max_value=-(int)1e9;

//               string min_expression="";
//               string max_expression="";
//              int used=-1;
//               pair1(){

//               }

//               pair1(int min_value,int max_value)
//               {
//                   this->min_value=min_value;
//                   this->max_value=max_value;
//               }
             
//                pair1(int min_value,int max_value,string s1, string s2)
//               {
//                   this->min_value=min_value;
//                   this->max_value=max_value;
//                   this->min_expression=s1;
//                   this->max_expression=s2;
//               }
            
//     };

//    int evaluate(int a, int b, char ch)
//    {
//         //cout<<a<<" "<<b<<endl;
//        if(ch=='+')return a+b;
//        else
//           return a*b;
//    }

//     pair1 min_max(string s,int si, int ei, vector<vector<pair1>>&dp)
//     {
//          if(si==ei)
//          {
//              int val=s[si]-'0';
//              string s1="";
//              s1+=s[si];
             

//              pair1 ans1(val,val,s1,s1);
//              //ans1.used=0;
//              //cout<<val<<endl;
//              ans1.used=0;
//              return dp[si][ei]=ans1;
//          }

//        if(dp[si][ei].used!=-1)
//           return dp[si][ei];

//         pair1 ans;
//          for(int cut=si+1;cut<ei;cut+=2)
//          {
//              pair1 lans=min_max(s,si,cut-1,dp);
//              pair1 rans=min_max(s,cut+1,ei,dp);

//                 int max_value=evaluate(lans.max_value,rans.max_value,s[cut]);
//                   //cout<<"cut"<<" "<<cut<<" max_value "<<" "<<max_value<<endl;
//                 int min_value=evaluate(lans.min_value,rans.min_value,s[cut]);
//              if(ans.max_value<max_value)
//              {
//                  ans.max_value=max_value;//evaluate(lans.max_value,rans.max_value,s[cut]);
//                  ans.max_expression="("+lans.max_expression+" "+ s[cut]+" "+rans.max_expression+")";
//              }

//               if(ans.min_value>min_value)
//              {
//                  ans.min_value=min_value;//evaluate(lans.min_value,rans.min_value,s[cut]);
//              ans.min_expression="("+lans.min_expression+" "+s[cut]+" "+rans.min_expression+")";
//              }


//           }
//             ans.used=0;

//            return dp[si][ei]=ans;
//     }


//     int main()
//     {
//         string s="1+2*3+4*5";

//         int l=s.size();
//          cout<<l<<endl;
//           vector<vector<pair1>>dp(l,vector<pair1>(l));

//           pair1 ans=min_max(s,0,l-1,dp);

//           cout<<ans.min_value<<" "<<ans.min_expression<<endl;
//           cout<<ans.max_value<<" "<<ans.max_expression<<endl;

//           return 0;

//     }

//     //leetcode 132
//      int minCut_memo(string s,int si,vector<vector<bool>>&ispalindrome,vector<int>&dp)
//     {
//         if(ispalindrome[si][s.size()-1])
//         {
//             return dp[si]=0;
//         }
        
//         if(dp[si]!=-1)
//             return dp[si];
        
//         int min_ans=(int)1e9;
//         for(int cut=si;cut<s.size();cut++)
//         {
//             if(ispalindrome[si][cut])
//             {
//                 min_ans=min(min_ans,minCut_memo(s,cut+1,ispalindrome,dp)+1);
//             }
//         }
        
        
//         return dp[si]=min_ans;
//     }
    
//     int minCut_dp(string s,int SI,vector<vector<bool>>&ispalindrome,vector<int>&dp)
//     {
//         for(int si=s.size()-1;si>=0;si--)
//        {
//         if(ispalindrome[si][s.size()-1])
//         {
//              dp[si]=0;
//              continue;
//         }
        
//         // if(dp[si]!=-1)
//         //     return dp[si];
        
//         int min_ans=(int)1e9;
//         for(int cut=si;cut<s.size();cut++)
//         {
//             if(ispalindrome[si][cut])
//             {
//                 min_ans=min(min_ans,dp[cut+1]+1);//minCut_memo(s,cut+1,ispalindrome,dp)+1);
//             }
//         }
        
        
//          dp[si]=min_ans;
//        }

//        return dp[SI];
//     }
//     int minCut(string s) {
        
//         int n=s.size();
        
//         vector<vector<bool>>ispalindrome(n,vector<bool>(n));
        
        
//         for(int gap=0;gap<n;gap++)
//         {
//             for(int i=0,j=gap;j<n;i++,j++)
//             {
//                 if(gap==0)
//                     ispalindrome[i][j]=true;
                
//                 else if(gap==1)
//                     ispalindrome[i][j]= s[i]==s[j];
                
//                 else
//                     ispalindrome[i][j]= s[i]==s[j] && ispalindrome[i+1][j-1];
//             }
//         }
        
        
//         vector<int>dp(n,-1);
        
//         return minCut_memo(s,0,ispalindrome,dp);
        
        
//     }


//leetcode 312
  
    int maxCoins(vector<int>& nums,int si, int ei,vector<vector<int>>&dp)
    {
        if(dp[si][ei]!=-1)
             return dp[si][ei];
        
        int lval= si==0?1:nums[si-1];
        
        int rval= ei==nums.size()-1?1:nums[ei+1];
        
        int max_coins=0;
        for(int cut=si;cut<=ei;cut++)
        {
            int lans= cut==si?0:maxCoins(nums,si,cut-1,dp);
            
            int rans=cut==ei?0:maxCoins(nums,cut+1,ei,dp);
            
            max_coins=max(max_coins,lans+lval*nums[cut]*rval+rans);
        }
        
        return dp[si][ei]=max_coins;
    }
    int maxCoins(vector<int>& nums) {

        int s=nums.size();
        vector<vector<int>>dp(s,vector<int>(s,-1));
       return maxCoins(nums,0,nums.size()-1,dp);
    }

//leetcode 1039
     int minScoreTriangulation_memo(vector<int>& values,int si,int ei,vector<vector<int>>&dp)
     {
         if(ei-si <=1)
              return dp[si][ei]=0;
         
         
         if(dp[si][ei]!=-1)
               return dp[si][ei];
         
         
         int min_ans=(int)1e9;
         for(int cut=si+1;cut<ei;cut++)
         {
             int lans=minScoreTriangulation_memo(values,si,cut,dp);
             
             int rans=minScoreTriangulation_memo(values,cut,ei,dp);
             
             min_ans=min(min_ans,lans+values[si]*values[cut]*values[ei]+rans);
         }
         
         return dp[si][ei]=min_ans;
     }
    int minScoreTriangulation(vector<int>& values) {
        
        
        int l=values.size();
        
         vector<vector<int>>dp(l,vector<int>(l,-1));
        return minScoreTriangulation_memo(values,0,values.size()-1,dp);
    }



    //https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#
    
     class pairBoolean {
          public:
        int trueWays = 0;
        int falseWays = 0;
          
          int data=-1;
          pairBoolean()
          {
              
          }
        pairBoolean(int trueWays, int falseWays) {
            this->trueWays = trueWays;
            this->falseWays = falseWays;
        }
    };

     pairBoolean Evaluate(pairBoolean left, pairBoolean right, char ch) {
        int mod = 1003;
        int TotalWays = ((left.trueWays + left.falseWays) % mod * (right.trueWays + right.falseWays) % mod) % mod;

        pairBoolean ans(0,0);
        if (ch == '&') {
            ans.trueWays = (left.trueWays * right.trueWays) % mod;
            ans.falseWays = (TotalWays - ans.trueWays + mod) % mod;
        } else if (ch == '|') {
            ans.falseWays = (left.falseWays * right.falseWays) % mod;
            ans.trueWays = (TotalWays - ans.falseWays + mod) % mod;
        } else {
            ans.trueWays = (left.falseWays * right.trueWays) % mod + (left.trueWays * right.falseWays) % mod;
            ans.falseWays = (TotalWays - ans.trueWays + mod) % mod;
        }

        return ans;
    }

     pairBoolean booleanPare(string& str, int si, int ei, vector<vector<pairBoolean>>&dp) {
        if (si == ei) {
            char ch = str[si];
            pairBoolean ans(ch == 'T' ? 1 : 0, ch == 'F' ? 1 : 0);
             
             ans.data=0;

              return dp[si][ei]=ans;

        }

        if (dp[si][ei].data!=-1)
            return dp[si][ei];

        pairBoolean myAns(0,0);
        for (int cut = si + 1; cut < ei; cut += 2) {
            char ch = str[cut];
            pairBoolean lans = booleanPare(str, si, cut - 1, dp);
            pairBoolean rans = booleanPare(str, cut + 1, ei, dp);

            pairBoolean recAns = Evaluate(lans, rans, ch);
            myAns.trueWays = (myAns.trueWays + recAns.trueWays) % 1003;
            myAns.falseWays = (myAns.falseWays + recAns.falseWays) % 1003;
        }
         myAns.data=0;

        return dp[si][ei] = myAns;
    }

 int countWays(int N, string S) {
       // pairBoolean[][] dp = new pairBoolean[N][N];

       vector<vector<pairBoolean>>dp(N,vector<pairBoolean>(N));

        pairBoolean ans = booleanPare(S, 0, N - 1, dp);

        return ans.trueWays;
    }

// surya coding question
int mod=(int)1e9+7;

  int evaluate(char ch)
  {
      if(ch=='r')
         return 1;
      else 
         return -1;   
  }

    int possible_count(string &s,int up, int src, int dest,int idx)
    {
        if(idx==s.size())
         return 0;
      
        if(src==dest)
           return 1;

        // if(src >up && src<0)
        //    return 0;
           
                   
           int count=0;
           //if(idx<s.size())
             int x= evaluate(s[idx]);

             
            //cout<<x<<endl;
          if(src+x<=up && src+x>=0 )  
              count+=possible_count(s,up,src+x,dest,idx+1);
        

           count+=possible_count(s,up,src,dest,idx+1);

             return count%mod;   
    }

int distinctMoves(string s,int n,int x,int y)
{
    int l=s.size();

//    vector<vector<int>>dp(l,vector<int>(n+1,-1));
    return possible_count(s,n,x,y,0);
}
    int main()
    {
        string s="rrlrlr";
        int up=6;
        int src=1;
        int dest=3;

        cout<<distinctMoves(s,up,src,dest);
        return 0;
    }