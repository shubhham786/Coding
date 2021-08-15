#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/sherlock-and-cost/problem

int cost(vector<int> B) {
    
    int low_l=0,high_b_i=0;
    
      int ans=-(int)1e9;
      
        for(int i=1;i<B.size();i++)
        {
            int low, high;
            low=max(low_l,high_b_i+abs(B[i-1]-1));
            high=max(low_l+abs(B[i]-1),high_b_i+abs(B[i]-B[i-1]));
            
            ans=max(low,high);
             low_l=low;
             high_b_i=high;
            
        }
            
            return ans;
}

//https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1#

   long long sumSubstrings(string n){
        
        // your code here
         int mod=(int)1e9+7;
    
   
    
    int l=n.size();
    
    vector<long long>sum_of_digit(l,0);
    
      sum_of_digit[0]=n[0]-'0';
      long long sum=n[0]-'0';
       for(int i=1;i<l;i++)
       {
           sum_of_digit[i]=(((i+1)*(n[i]-'0'))%mod+ (10*sum_of_digit[i-1])%mod)%mod;
           sum=(sum+sum_of_digit[i])%mod;
       }
       
       return sum;
    }
