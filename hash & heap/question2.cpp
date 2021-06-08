#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//perfic sum concept

//leetcode 560
 int subarraySum(vector<int>& arr, int k) {
        
      unordered_map<int,int>map;

         map[0]=1;
        
         int count=0;
        int sum=0;
         for(int &j:arr)
         {
             sum+=j;
               if(map.find(sum-k)!=map.end())
               {
                   count+=map[sum-k];
               }

               map[sum]++;
         }
        
     return count;   
    }

