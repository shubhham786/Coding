#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

void reverse1(vector<int>&arr,int i,int j)
{
       while(i<j)
       {
           swap(arr[i++],arr[j--]);
       }
}

void rotate(vector<int>&arr,int k)
{
        int n=arr.size();

        k= (k%n + n)%n;

        reverse1(arr,0,n-1);
        reverse1(arr,0,n-k-1);
        reverse1(arr,n-k-1,n-1);
}



void seggragte_neg_pos(vector<int>& arr)
{
   
      int n=arr.size();
 // cout<<n<<endl;

      int ptr=-1;
       
       int i=0;

       while(i<n)
       {
          // cout<<i<<endl;
           if(arr[i]< 0)
           {
               //cout<<"1";
               //cout<<arr[ptr+1];
               swap(arr[++ptr],arr[i]);
           }

           i++;
       }

 //     cout<<"k"<<arr.size();
     
}


void segregate_zero_one(vector<int>&arr)
{
       int n=arr.size();

       int ptr=-1;

       int i=0;

       while(i<n)
       {
           if(arr[i]==0)
           {
               swap(arr[++ptr],arr[i]);
           }

           i++;
       }
}

//revise it
void seggrate_0_1_2(vector<int>&arr)
{
    int n=arr.size();
    int pt2=n-1;
    int pt1=-1;
    int itr=0;
    
    while(itr<=pt2)
    {
        if(arr[itr]==0)
           swap(arr[++pt1],arr[itr++]);
        else if(arr[itr]==2)
           swap(arr[pt2--],arr[itr]);//ek bar ruk ke check kar rahe hai
        else
          itr++;      
    }
      
      cout<<" "<<pt1<<" "<<itr<<" "<<pt2<<endl;
}
//https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1#
int max_sum(vector<int>&A,int N)
{
//Your code here

     int sum=0;
     int sum1=0;
     
     for(int i=0;i<N;i++)
     {
         sum+=A[i];
         sum1=sum1+i*A[i];
     }
     
     int max1=sum1;
     
     for(int i=1;i<N;i++)
     {
         sum1=sum1-sum+N*A[i-1];
         
        max1=max(max1,sum1);
     }
     
     return max1;

}
//leetcode 11
    int maxArea(vector<int>& height) {
        
        
        int n=height.size();
        
        int area=0;
        
        int i=0;
        int k=n-1;
        
        while(i<k)
        {
            int w=k-i;
            
            
            area=height[i]<height[k]?max(area,w*height[i++]):max(area,w*height[k--]);
            
        }
        
        return area;
    }

//leetcode 03
//sliding window (tough concept)
    int lengthOfLongestSubstring(string s) {
        
      int s1=0;
        int e1=0; 
        int e=s.size();
        
        int len=0;
        int count=0;
        
        vector<int>hash(128,0);
        while(e1<e)
        {
            
            if(hash[s[e1]]==1)
                count++;
            
            cout<<s[e1]<<" "<<hash[s[e1]]<<endl;
            hash[s[e1]]++;
            e1++;
            
            while(count>0)
            {
            
                if(hash[s[s1]]==2)
                    count--;
            
                hash[s[s1]]--;
                s1++;
            }
            
            len=max(len,e1-s1);
            
        }
        
        return len;
    }

//sliding window optimized case
// template type
 int lengthOfLongestSubstring(string s)
     {
         int s1=0;
         int e=s.size();
         
         int e1=0;
         int count=0;
         int len=0;
         int si,ei;
         vector<int>hash(128,0);//directly used char to int match  jab sare charcter  aa rahe hai
         while(e1<e)
         {
             if(hash[s[e1++]]++ > 0)count++;
             
             while(count>0)
                 if(hash[s[s1++]]-- >1)
                     count--;
             
            // len=max(len,e1-s1);

            // to print
             if(len <e1-s1)
             {
                 len=e1-s1;
                 si=s1;
                 ei=e1;
             }
         }
         
         return len;
     }
//leetcode 159
//lintcode 928
int lengthOfLongestSubstringTwoDistinct(string &s) {
        // Write your code here
          int s1=0;
         int e=s.size();
         
         int e1=0;
         int count=0;
         int len=0;
         int si,ei;
         vector<int>hash(128,0);//n
         while(e1<e)
         {
             if(hash[s[e1++]]++ ==0)count++;
             
             while(count>2)
                 if(hash[s[s1++]]-- ==1)
                     count--;
             
            // len=max(len,e1-s1);
             if(len <e1-s1)
             {
                 len=e1-s1;
                 si=s1;
                 ei=e1;
             }
         }
         
         return len;
    }
 //leetcode 76
 // best question of sliding window 
 string minWindow(string s, string t) {
        
        int len=(int)1e9;
        int e1=0;
        int s1=0;
        int e=s.size();
        int g=t.size();
        int gsi;
        if(e<g)return "";
        vector<int>hash(128,0);
        
        for(int i=0;i<g;i++)
        {
            hash[t[i]]++;
        }
        
        int count=t.size();
        
        while(e1<e)
        {
            if(hash[s[e1++]]-- >0)count--;
            
            while(count==0)
            {
                if(e1-s1<len)
                {
                    len=e1-s1;
                    gsi=s1;    
                }
                
                if(hash[s[s1++]]++ ==0)count++;
            }
        }
        
        return len==(int)1e9?"":s.substr(gsi,len);
    }   
 //https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
 
class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here   
        vector<int>hash(126,0);
        int count=0;
        for(int i=0;i<str.size();i++)
        {
            if(hash[str[i]]==0){
                hash[str[i]]++;
                count++;   
            }
        }
        
        int s1=0,e1=0;
        int len1=str.size();
        int e=str.size();
        int gsi=0;
          while(e1<e)
          {
              if(hash[str[e1++]]-- >0)count--;
              
              while(count==0)
              {
                  if(e1-s1<len1){
                      len1=e1-s1;
                      gsi=s1;
                  }
                  //len1=min(len1,e1-s1);
                  
                  if(hash[str[s1++]]++ ==0)count++;
              }
          }
          
         
         return str.substr(gsi,len1);
    }
};
//leetcode 1456
  bool isvowel(char ch)
    {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        
        int l=s.size();
        
        int count=0;
        
        int s1=0;
        int e1=0;
        
       // vector<int>hash(126,0);
         int vow=0;
          int len=0;
        
          while(e1<l)
          {
              count++;
              if(isvowel(s[e1++]))vow++;
              
                
                // if(len==k)
                   //  break;
              
               if(e1-s1==k)
               {
                  len=max(len,vow);
                  
                   if(isvowel(s[s1++]))vow--;
               }
                 
                 if(len==k)
                    return k;
          }
        
        return len;
        
    }   
    //leectode 340
    //lint code 386
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here

          
        int count=0;
      
         vector<int>hash(126,0);

         int s1=0,e1=0;
         int l=s.size();
          int len=-(int)1e9;
            while(e1<l)
            {
                if(hash[s[e1++]]++ ==0)count++;

                  while(count>k)
                  {
                       
                       if(hash[s[s1++]]-- ==1)count--;

                     
                    
                    
                  }

                  len=max(e1-s1,len);

                  
            } 
        
        return len==-(int)1e9?0:len;
    }

    //leetcode 992
   // just similar to above question( was not able to solve it).
      int subarrayswithatmostk(vector<int>& nums, int k)
    {
         int count=0;
        int total=0;
        unordered_map<int,int>map;
        
        int s=0;
            int e=0;
        int l=nums.size();
        
        
        
          while(e<l)
          {
              if(map[nums[e++]]++ ==0)count++;
              
               while(count>k)
               {
                   if(map[nums[s++]]-- ==1)count--;
               }
              
             // if(count==k){
                
               total+=e-s;
          }
        
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
          return subarrayswithatmostk(nums,k)-subarrayswithatmostk(nums,k-1);
        
    }

    //leetcode 1248
        int numberOfSubarraysatmostk(vector<int>& nums, int k)
    {
        int si=0;
        int ei=0;
        
       // unordered_map<int,int>map;
        int count=0;
        int ans=0;
          int e=nums.size();
         
        
          while(ei<e)
          {
             
              if(nums[ei++]%2!=0) count++;
              
              
              while(count>k)
              {
                  if(nums[si++]%2!=0)count--;
              }
              
              
              ans+=ei-si;
          }
        
        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return numberOfSubarraysatmostk(nums,k)-numberOfSubarraysatmostk(nums,k-1);
        
    }

    //https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#

    class Solution{
    public:
    int longestKSubstr(string s, int k) {
    // your code here
       if(s.size()<k)
            return -1;
            
        int s1=0,e=0;
        int e1=s.size();
        
        int count=0;
        int len=-(int)1e9;
        
        vector<int>hash(126,0);
        while(e<e1)
        {
            if(hash[s[e++]]++==0)count++;
            
            if(count>k)
            {
                if(hash[s[s1++]]-- ==1)count--;
            }
            
            if(count==k)
            {
                len=max(len,e-s1);
            }
        }
        
        return len==-(int)1e9?-1:len;
    }
};
//leetcode 904
int totalFruit(vector<int>& tree) {
        
      ///  if(tree.size()<=2){
         //   return tree.size();
        //}
        
        int si=0;
        int ei=0;
        
        int e=tree.size();
        
        
          int count=0;
          int ans=-(int)1e9;
           vector<int>hash(40000+1,0);
           while(ei<e)
           {
               if(hash[tree[ei++]]++ ==0)count++;
               
                 while(count>2)
                 {
                     if(hash[tree[si++]]-- ==1)count--;
                 }
               
               //if(count==2)
               
                   ans=max(ans,ei-si);
               
           }
        
        return ans;
    }
    //leetcode 930
    //tes case [0,0,0,0,0,0],0 pe fastha tha wo nahi dekhe
    int numSubarraysWithSumatmostk(vector<int>& nums, int goal) {

        
        
        int si=0;
        int ei=0;
        int e=nums.size();
         int count=0;
          int ans=0;
        
           while(ei<e)
           {
              // if(nums[ei++]==1)count++;
               count+=nums[ei++];
               while(count>goal)
                    count-=nums[si++];
                   //if(nums[si++]==1)count--;
               
              // if(count==goal)
                    ans+=ei-si;
           }
        
        return ans;
    }
    
     int numSubarraysWithSum(vector<int>& nums, int goal){
         
         return numSubarraysWithSumatmostk(nums,goal)-(goal==0?0:numSubarraysWithSumatmostk(nums,goal-1));
     }

     //leetcode 485
     int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int si=0;
        int ei=0;
        
        int l=nums.size();
        int count=0;
        int len=0;
          while(ei<l)
          {
              if(nums[ei++]==0)count++;
              
              
              while(count>0)
                if(nums[si++]==0)count--;
              
              
              len=max(len,ei-si);
              
              
          }
        
        return len;
        
    }
        int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int si=0;
        int ei=0;
        
        int l=nums.size();
        int count=0;
        int len=0;
          while(ei<l)
          {
              if(nums[ei++]==0)si=ei;
              
              
             //if(count==1)
               //  si=ei;
              
              len=max(len,ei-si);
              
              
          }
        
        return len;
        
    }
    //leetcode 487
    //lintcode 883
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here

        int si=0;
        int ei=0;
        int l=nums.size();
        int len=0;

         int count=0;

         while(ei<l)
         {
             if(nums[ei++]==0)count++;

             while(count>1)
             {
                 if(nums[si++]==0)count--;
             }

             len=max(len,ei-si);
         }

         return len;
    }
    //optimized only for this case
      int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here

        int si=0,ei=0;
        int l=nums.size();
        int firstindexofzero=-1;
          int len=0;
          
          while(ei<l)
          {
              if(nums[ei++]==0)
              {
                  si=firstindexofzero+1;
                  firstindexofzero=ei-1;
              }


              len=max(len,ei-si);


          }

          return len;
    }
    //leetcode 1004
      int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here

        int si=0,ei=0;
        int l=nums.size();
        int firstindexofzero=-1;
          int len=0;
          
          while(ei<l)
          {
              if(nums[ei++]==0)
              {
                  si=firstindexofzero+1;
                  firstindexofzero=ei-1;
              }


              len=max(len,ei-si);


          }

          return len;
    }
    //leetcode 974
    //bad solution
    int subarraysDivByK(vector<int>& nums, int k) {
        
        vector<vector<int>>map(k);
       for(int i=0;i<k;i++)
           map[i]={i,0};
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int r;
            if(sum>=0)
               r=sum%k;
            else
                r=(sum%k +k)%k;
            
            map[r][1]++;
        }
        
        
        int count=0;
        
        for(auto &i :map)
        {
            //int z=i.first;
            vector<int>a=i;
            
            //if(z==0)
              //  count++;
            
            if(a[1]>1)
            {
                if(a[0]==0)
                    count+=a[1];
                
                
                count+= ((a[1])* (a[1]-1))/2;
            }
            else if(a[0]==0 && a[1]==1)
            {
                count++;
            }
              
            
        }
        return count;
        
    }
    //best solution
        int subarraysDivByK(vector<int>& nums, int k) {
        
        int ei=0,l=nums.size();
        
          vector<int>map(k,0);
          
           map[0]=1;
        int sum=0;
        int ans=0;
          while(ei<l)
          {
              sum+=nums[ei++];
              
              int r= (sum%k +k)%k;
              
              ans+=map[r];
              
              map[r]++;
          }
        
        return ans;
        
        
    }
     int longestsubarraysDivByK(vector<int>& nums, int k) {
        
        int ei=0,l=nums.size();
        
          vector<int>map(k,-2);
          
           map[0]=1;
        int sum=0;
        int len=0;
          while(ei<l)
          {
              sum+=nums[ei];
              
              int r= (sum%k +k)%k;
              
              //ans+=map[r];

              if(map[r]==-2)
                  map[r]=ei;
              else
                len=max(len,ei-map[r]);

                ei++;    
              //map[r]++;
          }
        
        return len;
        
        
    }

    //leetcode 560
    // subarry with given target
        int subarraySum(vector<int>& nums, int tar) {
        
        unordered_map<int,int>map;
        
        map[0]=1;
        int ei=0,l=nums.size();
        
          int sum=0;
        int ans=0;
        while(ei<l)
        {
            sum+=nums[ei++];
            
           // if(map.find(sum-tar)!=map.end())ans+=map[sum-tar];
            ans+=map.find(sum-tar)!=map.end()?map[sum-tar]:0; 
            map[sum]++;
        }
        
        return ans;
        
        
    }
    //https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1#
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        
        //unordered_map
        unordered_map<int,int>map1;
        map1[0]=1;
        
        int ei=0;
        int sum=0;
        long long int ans=0;
        
          while(ei<n)
          {
             int val=arr[ei++];
             sum+=val;
             if(val==0)sum+=-1;
             
             ans+=map1[sum];
             
             map1[sum]++;
          }
        
        return ans;
    }
    //https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1#
    //leetcode 525 
        int maxLen(int arr[], int N)
    {
        // Your code here
        
        unordered_map<int,int>map;
        map[0]=-1;
        
        int ei=0,len=0;
        int sum=0;
        while(ei<N)
        {
            int val=arr[ei];
            
            sum+=val;
            
            if(val==0)sum+=-1;
            
            //len=max(len,)
            
            if(map.find(sum)==map.end())
              map[sum]=ei;
            else  
              len=max(len,ei-map[sum]);
              
             
            ei++;
        }
        
        return len;
    }

  //leetcode 239

  //ist) time o(nlogn)  space 
  //one way
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
         
        priority_queue<vector<int>>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            
            if(pq.size()>=k)
            {
                 while(pq.size()!=0)
                 {
                     vector<int>a=pq.top();
                     
                       //pq.pop();
                       
                        if(a[1]>i-k)
                        {
                            ans.push_back(a[0]);
                            break;
                        }
                        else{
                            pq.pop();
                        }
                 }
            }
        }
        
        return ans;
        
    }
    //another way  
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    // {val, index}
    priority_queue<vector<int>> pq;

    int n = nums.size(), idx = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        while (pq.size() != 0 && pq.top()[1] <= i - k)
            pq.pop();

        pq.push({nums[i], i});

        if (i >= k - 1)
            ans.push_back(pq.top()[0]);
    }
    return ans;
}
 //method 2 (using list as dequeue)
     vector<int> maxSlidingWindow(vector<int>& nums, int k)
     {
         list<int>de;
         
         int n=nums.size();
         
         vector<int>ans;
         
         for(int i=0;i<n;i++)
         {
             
             while(de.size()!=0 && de.front()<=i-k)
                 de.pop_front();
             
             while(de.size()!=0 && nums[de.back()]<=nums[i])
                  de.pop_back();
             
             de.push_back(i);
             
             if(i>=k-1)
                 ans.push_back(nums[de.front()]);
         }
         
         return ans;
     }
//using dequeue stl
vector<int> maxSlidingWindow(vector<int>& nums, int k)
         {
             deque<int>de;
             
             int n=nums.size();
             
             vector<int>ans;
             
             for(int i=0;i<nums.size();i++)
             {
                 while(de.size()!=0 && de.front()<=i-k)
                     de.pop_front();
                 
                 while(de.size()!=0 && nums[de.back()]<=nums[i])
                     de.pop_back();
                 
                 de.push_back(i);
                 
                 if(i>=k-1)
                     ans.push_back(nums[de.front()]);
             }
             
             return ans;
         }

 // kadne's algo (if all -ve then return 0)
 int kadens_algo(vector<int>&arr)
 {
     int gsum=0,csum=0;

     for(int & ele:arr)
     {
         csum+=ele;

         if(gsum<csum)
            gsum=csum;

         if(csum<0)
           csum=0;

     }

     return gsum;
 }   
 // kadene algo generic 
 int kadens_algo_generic(vector<int>&arr)
 {
     int gsum=-(int)1e9,csum=0;


     for(int &ele:arr)
     {
         csum=max(ele,csum+ele);
         gsum=max(csum,gsum);
     }

     return gsum;
 }
 // print subarray
  int kadens_algo_sub(vector<int>&arr)
 {
     int gsum=0,csum=0,gei=0,gsi=0,csi=0;

     for(int i=0;i<arr.size();i++)
     {
         int ele=arr[i];
         csum+=ele;

         if(gsum<csum){
            gsum=csum;
            gsi=csi;
            gei=i;
         }
         if(csum<0){
           csum=0;
           csi=i+1;
         }  


     }

     return gsum;
 }
 int kadens_algo_generic_subarry(vector<int>&arr)
 {
     int gsum=-(int)1e9,csum=0,gedx=0,csdx=0,gsdx=0;


     for(int i=0;i<arr.size();i++)
     {
         int ele=arr[i];
         csum=csum+ele;
         if(ele>csum)
         {
             csum=ele;
             csdx=i;
         }
         //csum=max(ele,csum+ele);
         if(csum>gsum){
             gsum=csum;
             gsdx=csdx;
             gedx=i;
         }
         //gsum=max(csum,gsum);
     }

     return gsum;
 }     

 //leetcode 1191
 int mod=(int)1e9+7;
      
      int kadane_algo(vector<int>&arr,int k)
      {
          int s=arr.size();
          long gsum=0,csum=0;

          for(int i=0;i<s;i++)
          {
              int ele=arr[i];

              csum+=ele;//yahan pe mod nahi liye (point to be noted)
              
              if(csum>gsum)
                gsum=csum;

              if(csum<=0)
                 csum=0;  
          }

          return (int)(gsum % mod);
      }
     int kConcatenationMaxSum(vector<int>& arr, int k) {
     
     long prevsum=0,sum=0;
         for(int i=1;i<=3;i++)
         {
             sum=kadane_algo(arr,i);

             if(i==k)
                return sum%mod;

            
            
            if(i==3)
             return (int)((prevsum + (k-2)*(sum-prevsum))%mod);

            prevsum=sum; 
         }
        

    }

    //another better code
     int kadane_algo(vector<int>&arr,int k)
      {
          int s=arr.size();
          long gsum=0,csum=0;

          for(int i=0;i<s*k;i++)
          {
              int ele=arr[i%s];

              csum+=ele;//yahan pe mod nahi liye (point to be noted)
              
              if(csum>gsum)
                gsum=csum;

              if(csum<=0)
                 csum=0;  
          }

          return (int)(gsum % mod);
      }
     int kConcatenationMaxSum(vector<int>& arr, int k) {
     
     long prevsum=0,sum=0;
         for(int i=1;i<=3;i++)
         {
            prevsum=sum; 

             sum=(long)kadane_algo(arr,i);

             if(i==k)
                return sum;

            
            
           // if(i>=3)
             

         }
        
          return (int)((prevsum + (k-2)*(sum-prevsum))%mod);;
        
    }  

    //https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

    //GIVING TLE donot know why

    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        int gsum=-(int)1e9,csum=0;
          
         //for(int i=0;i<C;i++)
           // ans.push_back(M[0][i]);
            
     // cout<<R<<endl;
     
        for(int i=0;i<R;i++)
        {
               //fill_n(ans.begin(), C, 0);
               vector<int>ans(C,0);
            for(int j=i;j<R;j++)
            {
                csum=0;
                for(int k=0;k<C;k++)
                {
                    ans[k]+=M[j][k];
                    csum=max(ans[k],csum+ans[k]);
                    gsum=max(gsum,csum);
                    
                }
                //csum=kadnesalgo(ans);
                    //cout<<csum<<" "<<i<<" "<<j<<endl;
                  //  if(csum>gsum)
                    //  gsum=csum;
            }
        }
        
        return gsum;
    }   

    //To print the matrices
    vector<int> kadens_algo_generic_subarry01(vector<int>&arr)
   {
     int gsum=-(int)1e9,csum=0,gedx=0,csdx=0,gsdx=0;


     for(int i=0;i<arr.size();i++)
     {
         int ele=arr[i];
         csum=csum+ele;
         if(ele>csum)
         {
             csum=ele;
             csdx=i;
         }
         //csum=max(ele,csum+ele);
         if(csum>gsum){
             gsum=csum;
             gsdx=csdx;
             gedx=i;
         }
         //gsum=max(csum,gsum);
     }
      return {gsum,gsdx,gedx};
   }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        int gsum=-(int)1e9,csum=0;
        int gsri,geri,gsci,geci;
          
         //for(int i=0;i<C;i++)
           // ans.push_back(M[0][i]);
            
     // cout<<R<<endl;
    
        for(int i=0;i<R;i++)
        {
               //fill_n(ans.begin(), C, 0);
                vector<int>ans(C,0);
            for(int j=i;j<R;j++)
            {
                csum=0;
                for(int k=0;k<C;k++)
                {
                    ans[k]+=M[j][k];
                   // csum=max(ans[k],csum+ans[k]);
                    //gsum=max(gsum,csum);
                    
                }
   // vector<int> kadens_algo_generic_subarry01(vector<int>&arr)
                vector<int>a=kadens_algo_generic_subarry01(ans);
                    //cout<<csum<<" "<<i<<" "<<j<<endl;
                    if(a[0]>gsum)
                      {
                           gsum=a[0];
                           gsri=i;
                           geri=j;
                           gsci=a[1];
                           geci=a[2];
                      }
            }
        }
        
        for(int i=gsri;i<geri;i++)
        {
            for(int j=gsci;j<geci;j++)
            {
                cout<<M[i][j]<<" ";
            }
            cout<<endl;
        }
        return gsum;
    }
    //leetcode 781
     int numRabbits(vector<int>& ans) {

        
        vector<int>map(999+1,0);
        int ans1=0;
        
        for(int i=0;i<ans.size();i++)
        {
           
            if(map[ans[i]]++ ==0)ans1+=ans[i]+1;
            
            
            if(map[ans[i]]==(ans[i]+1))map[ans[i]]=0;
        }
        
        return ans1;
    }

    //leetcode 1074
      int subarray_tar(vector<int>&arr,int tar)
    {
        int ei=0,l=arr.size();
        
        int sum=0;
        int ans=0;
        
     unordered_map<int,int>map;
        map[0]=1;
        
        while(ei<l)
        {
            sum+=arr[ei++];
            
            ans+= map.find(sum-tar)!=map.end()?map[sum-tar]:0;
            
            map[sum]++;
        }
        
        return ans;
        
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
       int ans=0;
        
        int r=matrix.size();
        int c=matrix[0].size();
        
        
        for(int i=0;i<r;i++)
        {
            vector<int>q(c,0);
            
            for(int j=i;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    q[k]+=matrix[j][k];
                }
                
                ans+=subarray_tar(q,target);
            }
        }
        
        return ans;
        
    }
    //leetcode 922
     vector<int> sortArrayByParityII(vector<int>& nums) {
        
        for(int i=0,j=1;i<nums.size(),j<nums.size();i+=2,j+=2)
        {
            
            while(i<nums.size() && (nums[i]&1)==0)i+=2;
            while(j<nums.size() && (nums[j]&1)==1)j+=2;
            
            if(i<nums.size())swap(nums[i],nums[j]);
        }
        
        return nums;
        
    }
    //leetcode 1395
     
     //less[left] * greater[right] + greater[left] * less[right]
    int numTeams(vector<int>& rating) {
        
        int res=0;
        //un elements ko check karo jinke liye left and right dono exist karte hoon
        //isliye 1 se arr.size()-2 tak
       for(int i=1;i<rating.size()-1;i++)
       {
           vector<int>less(2); 
           //less[0]=a[j] >a[i] && j<i
           //less[1]=a[j]>a[i] && j>i
           vector<int>greater(2);
            //greater[0]=a[j]<a[i] && j<i
           //greater[1]=a[j]<a[i] && j>i
           
           for(int j=0;j<rating.size();j++)
           {
               if(rating[i]>rating[j])
                   ++greater[j>i];
               else if(rating[i]<rating[j])
                   ++less[j>i];
           }
           
           res+=less[0]*greater[1]+less[1]*greater[0];
       }
        
        return res;
        
    }
    //leetcode 31
    //https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

        
    /*The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.

1.Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2.Find the largest index l greater than k such that a[k] < a[l].
3.Swap the value of a[k] with that of a[l].
4.Reverse the sequence from a[k + 1] up to and including the final element a[n].
  */  
    void nextPermutation(vector<int>& nums) {
          
        int n=nums.size(),k,l;
        
          for(k=n-2;k>=0;k--)
          {
              if(nums[k]<nums[k+1])
                  break;
          }
        
        if(k<0)
            reverse(nums.begin(),nums.end());
        else
        {
            for(l=n-1;l>k;l--)
                if(nums[l]>nums[k])
                    break;
            
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
int main()
{
    
    vector<vector<int>>M(4,vector<int>(5));

     M={{1,2,-1,-4,-20},
{-8,-3,4,2,1},
{3,8,10,1,3},
{-4,-1,1,7,-6}};

 int gsum=maximumSumRectangle(4,5,M);
 
 

      //seggrate_0_1_2(arr);

//      cout<<arr.size();
     // for(int i:arr)
      //{
        //  cout<<i<<" ";
      //}
    

    return 0;
}

//leetcode 80
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0;
     //   int  count=0;
        
        int k=0,j=0;
        //int l1=0;
    while(i<n)
        {
           
                        
                 j=i+1;
                int l=nums[i];
                 while(j<n && nums[j]==l)
                 {
                  
                     j++;
                     //count++;
                     //cout<<j<<endl;
                     }
                
                if(j-i>=2)
                {
                    nums[k++]=nums[i];
                    nums[k++]=nums[i];
                }
                else
                    nums[k++]=nums[i];
                    
        
            
            
              i=j;
            
           
        }
        
        return k;
    }

