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
