#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
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



//day2

//leetcode 871
   int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        
            priority_queue<int>pq;
        
        
        int count=0;
             for(int i=0;i<stations.size();i++)
             {
                 //cout<<stations[i][0]<<endl;
                 if(stations[i][0]<=startFuel)
                 {
                    // cout<<"i"<<i<<endl;
                     pq.push(stations[i][1]);
                    // cout<<pq.size()<<endl;
                 }
                 else
                 {
                    
                     while(pq.size()!=0 && startFuel<stations[i][0])
                     {
                         count++;
                         startFuel+=pq.top();
                        // cout<<startFuel<<endl;
                         pq.pop();
                     }
                     
                     if(startFuel>=stations[i][0])
                         pq.push(stations[i][1]);
                     else
                         return -1;
                 }
             }
        
       //  return count;
        
          //cout<<pq.size();
        
           while(target>startFuel && pq.size()!=0)
           {
               //cout<<count<<endl;
               count++;
               startFuel+=pq.top();
               pq.pop();
           }
        
           if(target>startFuel)
               return -1;
               
        return count;
        
    }
    

    //leetcode 914
      int GCD(int x, int y) 
   { 
     if (y == 0) 
        return x; 
        
     return GCD(y, x % y);  
      
   }
    bool hasGroupsSizeX(vector<int>& deck) {
        
        
        
        
           unordered_map<int,int>map;
        
            for(int ele:deck)
            {
                map[ele]++;
            }
        
        int gcd=map[deck[0]];
        for(auto l:map)
        {
            gcd=GCD(gcd,l.second);
        }
        
        if(gcd>=2)
            return true;
        else
            return false;
        
    }

    //https://practice.geeksforgeeks.org/problems/check-arithmetic-progression1842/1#
    
     bool checkIsAP(int arr[], int n)
    {
        // code here
        unordered_map<int,int>map;
          //vector<int>map;
        int min1=(int)1e9;
        int min2=(int)1e9;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=min1){
               min2=min1;
               min1=arr[i];
            }
            else if(arr[i]<=min2)
              min2=arr[i];
              
              map[arr[i]]++;
        }
        
        int d=min2-min1;
        //cout<<d<<endl;
        //cout<<min1<<" "<<min2<<endl;
        //bool flag=false;
        if(d==0)
        {
            if(map.size()>1)
               return false;
            
            else
              return true;
        }
        else
        {
            int z=min1;
           while(n-->0)
           { 
               //cout<<z<<endl;
               if(map.find(z+d)!=map.end())
               {
                   map.erase(z);
                   z=z+d;
               }
               else
               {
                   //cout<<"size"<<map.size()<<endl;
                   return map.size()==1;
               }
           }
           
           return true;
        }
          
          
            
        
    }