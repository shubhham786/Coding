#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;


//leetcode 925
  bool isLongPressedName(string name, string typed) {
        
        int s=name.size();
        
        int e=typed.size();
        
        
          int i=0;
        int j=0;
        
          while(i<s && j<e)
          {
              if(name[i]!=typed[j])
                  return false;
                  
              int count=0;
              while(name[i]==typed[j])
              {j++;
               count++;
              }
              
                while(name[i]==name[i+1])
                {
                    i++;
                    count--;
                }
              
               if(count<=0)
                   return false;
              
              i++;
          }
        
        //cout<<i<<" "<<s<<" "<<j<<" "<<e<<endl;
        return (i!=s||j!=e)?false:true;
    }

//https://www.lintcode.com/problem/903/

//Range queries

vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here

        vector<int>up(length,0);

          for(vector<int>&a:updates)
          {
              up[a[0]]+=a[2];

              if(a[1]+1<length)
                up[a[1]+1]+=-a[2];
          }

//  for(int i=0;i<length;i++)
//            {
//               // up[i]=up[i]+up[i-1];

//               cout<<up[i]<<" ";
//            }

        
           for(int i=1;i<length;i++)
           {
               up[i]=up[i]+up[i-1];
           }

           return up;
    }

    //https://www.codechef.com/COOK103B/problems/MAXREMOV

    int main() {
	// your code goes here
	
	int t;
	cin>>t;
	 while(t-->0)
	 {
	     int n,k;
	     cin>>n>>k;
	     
	     vector<vector<int>>up(n,vector<int>(2));
	     
	      int max1=0;
	      
	      for(int i=0;i<n;i++)
	      {
	           int l,r;
	           
	           cin>>l>>r;
	           up[i][0]=l;
	           up[i][1]=r;
	           
	           max1=max(max1,r);
	             
	      }
	      
	      
	      vector<int>u(max1+1);
	      
	        for(vector<int>&a:up)
          {
              u[a[0]]+=1;

              if(a[1]+1<max1+1)
                u[a[1]+1]+=-1;
          }
          
          vector<int>pr_k(max1+1);
          vector<int>pr_k_1(max1+1);
          
          int k_count=0;
          if(u[0]==k){
           k_count++;
           pr_k[0]=1;
           
          }
          if(u[0]==k+1)
            pr_k_1[0]=1;
          
           for(int i=1;i<max1+1;i++)
           {
               u[i]=u[i]+u[i-1];
               
                if(u[i]==k){
                 pr_k[i]=pr_k[i-1]+1;
                  k_count++;
                }
                else
                  pr_k[i]=pr_k[i-1];
                  
                 if(u[i]==k+1)
                   pr_k_1[i]=pr_k_1[i-1]+1;
                 else
                   pr_k_1[i]=pr_k_1[i-1];
           }
           
           int ans=0;
           for(int i=0;i<n;i++)
           {
               if(up[i][0]!=0)
                ans=max(ans,k_count-(pr_k[up[i][1]]-pr_k[up[i][0]-1])+(pr_k_1[up[i][1]]- pr_k_1[up[i][0]-1]));
               
               else
                  ans=max(ans,k_count-(pr_k[up[i][1]])+(pr_k_1[up[i][1]]));
               
           }
/*          
            for(int i=0;i<max1+1;i++)
            {
                cout<<u[i]<<" "<<pr_k[i]<<" "<<pr_k_1[i]<<endl;
            }
*/         
cout<<ans<<endl;
          
	 }
	return 0;
}

//leetcode 899

string orderlyQueue(string s, int k) {
     
          string ans=s;
         
         if(k==1)
         {
             int l1=s.length();
             
               int k=1;
               
              string l=s;
               while(k<l1)
               {
                  l= l.substr(1,l1-1)+l[0];
                   k++;
                   ans=min(ans,l);
               }
             
             return ans;
         }
        
        else
        {
            sort(s.begin(),s.end());
            
            return s;
        }
        
    }

//leetcode 11
    int maxArea(vector<int>& height) {
     
        int max1=-(int)1e9;
        
        
         int si=0;
        int ei=height.size()-1;
        
         while(si<ei)
         {
             
             height[si]<height[ei]?max1=max(max1,height[si++]*(ei-si+1)):max1=max(max1,height[ei--]*(ei-si+1));
         }
        
        return max1;
    }

    //leetcode 977

        vector<int> sortedSquares(vector<int>& nums) {
        
        
        
        vector<int>ans(nums.size());
        
        
          int si=0;
          int ei=nums.size()-1;
        
        
          // int l=nums.size()-1;
        
           int l=nums.size()-1;
           while(l>=0)
           {
               if(abs(nums[si])>abs(nums[ei]))
               {
                   ans[l]=nums[si]*nums[si++];
                   
               }
               else
               {
                   ans[l]=nums[ei]*nums[ei--];
               }
               l--;
           }
        
        
        return ans;
    }

    //leetcode 189
        void rotate(vector<int>& nums, int k) {
        
        k=k%nums.size();
        
        if(k<0)
            k=nums.size()+k;
        
        
        
        reverse(nums.begin(),nums.end());
        
        reverse(nums.begin(),nums.begin()+k);
        
        reverse(nums.begin()+k,nums.begin()+nums.size());
        
    }

    //leetcode 556
     int nextGreaterElement(int n) {
        
        string s= to_string(n);
        
           int l=s.size()-1;
        
          while(l>=1 && s[l]<=s[l-1])l--;
        
            if(l==0)return -1;
          //cout<<l<<endl;
        
                int x=s[l-1]-'0';
            int z=l;
        
                int min1=(int)1e9;
        
            int y=0;
              while(z<s.size())
              {
                  if(s[z]-'0' >x)
                  {
                      if(s[z]-'0'<=min1)
                      {    min1=s[z]-'0';
                           y=z;
                      }
                      
                  }   
                      
                  
                  z++;
              }
                
        //cout<<y<<endl;
           if(y>0)
            swap(s[l-1],s[y]);
        
            reverse(s.begin()+l,s.end());
        
        
            return stol(s)>INT_MAX?-1:stoi(s);
               
    }

    //leetcode 169
     int majorityElement(vector<int>& nums) {
        
        
        int val=nums[0];
        int count=1;
        
          for(int i=1;i<nums.size();i++)
          {
              if(count>0){
               if(nums[i]==val)
               {
                  count++;
               }
                  else
                       count--;
                  
              }
              else
              {
                  val=nums[i];
                  count=1;
                  
              }
          }
        
        
        return val;
    }

    //leetcode 229
    
    vector<int> majorityElement_2(vector<int>& arr) {
        
        
        int count1=0;
        int count2=0;
        int val1,val2;
        
        for(int i=0;i<arr.size();i++)
        {
           
            if(arr[i]==val1){
                //val1=arr[i];
                count1++;
            }
            else if(arr[i]==val2)
            {  
               // val2=arr[i];
                  count2++;
            }
            else
            {
                //count1--;
                //count2--;
                 
                 if(count1==0){
                     val1=arr[i];
                     count1=1;
                 }
                else if(count2==0)
                {
                    val2=arr[i];
                    count2=1;
                }
                else
                {
                    count1--;
                    count2--;
                }
                    
            }
            
        }
        
        int c=0;
        int c1=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==val1)
                 c++;
            
            else if(arr[i]==val2)
                c1++;
        } 
        vector<int>ans;
        // cout<<c<<" "<<c1<<" "<<arr.size()/3<<endl;
        // cout<<val1<<" "<<val2<<endl;
        if(c>arr.size()/3)
            ans.push_back(val1);
        
        if(c1>arr.size()/3)
            if(val1!=val2)
             ans.push_back(val2);
        
        return ans;
    }

//leetcode 769
    int maxChunksToSorted(vector<int>& arr) {
     
        int max1=0;
        
        int ans=0;
        
           for(int i=0;i<arr.size();i++)
           {
               max1=max(max1,arr[i]);
               
               if(i==max1)
                   ans++;
           }
        
        return ans;
        
    }

    //leetcode 768
        int maxChunksToSorted(vector<int>& arr) {
        
        vector<int>suff_min(arr.size());
        
          vector<int>pref_max(arr.size());
        
        
          for(int i=0;i<arr.size();i++)
          {
              if(i==0){
                  pref_max[i]=arr[i];
                  suff_min[arr.size()-1]=arr[arr.size()-1];
              }
              else
              {
                  pref_max[i]=max(pref_max[i-1],arr[i]);
                  
                  suff_min[arr.size()-1-i]=min(suff_min[arr.size()-i],arr[arr.size()-1-i]);
              }
              
                  
          }
        
        int ans=0;
//          for(int i=0;i<arr.size();i++)
//           {
              
//                cout<<pref_max[i]<<" "<<suff_min[i]<<endl;
//           }
        
          for(int i=0;i<arr.size()-1;i++)
          {
              
              if(pref_max[i]<=suff_min[i+1])
                   ans++;
          }
        
        return ++ans;
        
    }

    //leetcode 628
        int maximumProduct(vector<int>& nums) {
        
        
        long max1,max2,max3=-(int)1e9;
        
        long min1,min2=(int)1e9;
        
        
          for(int i=0;i<nums.size();i++)
          {
              if(nums[i]>=max1)
              {
                  max3=max2;
                  max2=max1;
                  max1=nums[i];
              }
              else if(nums[i]>=max2)
              {
                  max3=max2;
                  max2=nums[i];
              }
              else if(nums[i]>max3)
                  max3=nums[i];
              
              
              
              if(nums[i]<=min1)
              {
                  min2=min1;
                  min1=nums[i];
              }
              else if(nums[i]<min2)
                  min2=nums[i];
          }
        
        
        return max(max1*min2*min1,max3*max2*max1);
    }

    //leetcode 747

       int dominantIndex(vector<int>& nums) {
        
        int max1=-(int)1e9,max2=-(int)1e9;
        int z=0;
          for(int i=0;i<nums.size();i++)
          {
              if(nums[i]>=max1)
              {
                   z=i;
                //  cout<<i<<endl;
                  max2=max1;
                  max1=nums[i];
                 //cout<<max1<<endl;
              }
              else if(nums[i]>max2)
              {
                  max2=nums[i];
              }
          }
        
        
          return max1>=2*max2?z:-1;
        
    }


    //leetcode 795
     int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
     
        
        int i=0;
        int j=0;
        
         int e=nums.size();
        
        int ans=0;
        int prev_ans=0;
          while(j<e)
          {
              if(nums[j]<=right && nums[j]>=left){
                  ans+=j-i+1;
                  prev_ans=j-i+1;
              }  
              else if(nums[j]>right)
              {   i=j+1;
                  prev_ans=0;
              }
              else
              {
                  ans+=prev_ans;
              }   
              
              j++;
              
          }
        
        return ans;
        
    }

    //leetcode 53
      int maxSubArray(vector<int>& nums) {
        
        int omax=-(int)1e9;
         int csum=0;
        
        
          for(int &ele:nums)
          {
              csum=max(ele,csum+ele);
              
              omax=max(omax,csum);
          }
        return omax;
    }

        int maxSubArray_02(vector<int>& nums) {
       
        int cmax=0;
        int omax=-(int)1e9;
        
          for(int &ele:nums)
          {
              if(cmax>=0)
                  cmax+=ele;
              else
                  cmax=ele;
              
              
              omax=max(cmax,omax);
          }
        
        return omax;
    }

    //lintcode 912 
     int minTotalDistance(vector<vector<int>> &grid) {
        // Write your code here

          vector<int>row;
          vector<int>col;

            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        row.push_back(i);
                        col.push_back(j);
                    }
                }
            }

            sort(row.begin(),row.end());
            sort(col.begin(),col.end());


              int x=row[row.size()/2];
              int y=col[col.size()/2];
              int dist=0;
              //cout<<x<<" "<<y<<endl;
               for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                       dist+= abs(i-x)+abs(j-y);
                    }
                }
            }

            return dist;
    }

    //leetcode 75
     void sortColors(vector<int>& nums) {
        
        
        int i=-1;
        int j=0;
        int k=nums.size()-1;
        
          while(j<=k)
          {
              if(nums[j]==0)
              {
                  swap(nums[++i],nums[j]);
                  j++;
              }
              else if(nums[j]==2)
              {
                  swap(nums[k--],nums[j]);
              }
              else
              {
                  j++;
              }
          }
    }

    //leetcode 905
     vector<int> sortArrayByParity(vector<int>& nums) {
        
        
        int i=-1;
         int j=0;
         int n=nums.size();
        
          while(j<n)
          {
              
              if(nums[j]%2==0)
              {
                  swap(nums[++i],nums[j]);
              }
              j++;
           }
        
        return nums;
    }

    //leetcode 763
     vector<int> sortArrayByParity(vector<int>& nums) {
        
        
        int i=-1;
         int j=0;
         int n=nums.size();
        
          while(j<n)
          {
              
              if(nums[j]%2==0)
              {
                  swap(nums[++i],nums[j]);
              }
              j++;
           }
        
        return nums;
    }

    //leetcode 829
        int consecutiveNumbersSum(int n) {
        
        
        int up=sqrt(2*n);
        //cout<<up<<endl;
        
        int count=0;
           for(int k=1;k<=up;k++)
            {
               
               if((n-((k-1)*k)/2)%k==0)
               {
                    count++;
                  // cout<<(n-((k-1)*k)/2)<<endl;
               }
           }
        
        
      return count;
    }

    //leetcode 509
      
    int fib(int n) {
     
        
         if(n==0 || n==1)
             return n;
        
          vector<vector<int>>f={{1,1},{1,0}};
         
          fib1(f,n-1);
          
        
        
        return f[0][0];  
          
    }
    
    void fib1( vector<vector<int>>&f,int n) {
     
        
         if(n==0 || n==1)
             return ;
        
           vector<vector<int>>m={{1,1},{1,0}};
         
          fib1(f,n/2);
          mutiply(f,f);
        
          if(n%2!=0)
             mutiply(f,m);
        
        
        
        //return f[0][0];  
          
    }
    
    
    void mutiply(vector<vector<int>>&F,vector<vector<int>>&M)
    {
        int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
    }

    //https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1#
    
    //sieve of eratosthenes


     vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        
        
    int l=sqrt(N);
    
      vector<int>arr(N+1,0);
      
      for(int i=2;i<=l;i++)
      {
          if(arr[i]==1)
            continue;
            
          for(int j=2*i;j<=N;j=j+i)
          {
           
                if(j%i==0)
                {
                   // cout<<"1"<<endl;
                    //cout<<j<<endl;
                    arr[j]=1;
                }
          }
      }
      
      vector<int>ans;
      
      for(int i=2;i<=N;i++)
      {
          if(arr[i]==0)
            ans.push_back(i);
      }
      
      
      return ans;
    }


    //lint code 508

       void wiggleSort(vector<int> &nums) {
        // write your code here 

         int n=nums.size();

           for(int i=1;i<n;i+=2)
           {
                
                if(nums[i-1]>nums[i])
                   swap(nums[i-1],nums[i]);

                if(i<n-1 && nums[i+1]>nums[i])
                  swap(nums[i+1],nums[i]);
                  

                 
           }


    }

    //leetcode 670
        int maximumSwap(int num) {
        
        
          string s= to_string(num);
        
         // cout<<s<<endl;
        
        
          vector<int>last_occ(10,-1);
        
           for(int i=0;i<s.size();i++)
           {
               last_occ[s[i]-'0']=i;
           }
          
        
        for(int i=0;i<s.size();i++)
        {
              int k=s[i]-'0';
              
                int l=9;
            
               while(l>k)
               {
                   if(last_occ[l]!=-1 && last_occ[l]>i)
                   {
                        //cout<<i<<endl;
                       swap(s[i],s[last_occ[l]]);
                        return stoi(s);        
                   }
                   l--;
               }
        }
        
        // cout<<s<<endl;
          return num;
        
    }

    //leetcode 1007
       int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
         
        int count1_1=0;
        int count1_2=0;
        int count2_1=0;
        int count2_2=0;
        
        int val1=tops[0];
        int val2=bottoms[0];
         
          for(int i=0;i<tops.size();i++)
          {
              if(tops[i]!=val1 && bottoms[i]!=val1)
              {
                  count1_1=(int)1e9;
                  count1_2=(int)1e9;
              }
              else
              {
                  if(tops[i]!=val1)
                      count1_1++;
                  
                   if(bottoms[i]!=val1)
                        count1_2++;
                  
              }
              
              if(tops[i]!=val2 && bottoms[i]!=val2)
              {
                  count2_1=(int)1e9;
                  count2_2=(int)1e9;
              }
              else
              {
                  if(tops[i]!=val2)
                      count2_1++;
                  
                   if(bottoms[i]!=val2)
                        count2_2++;
                  
              }
              
              
                  
          }
        
        int z=min({count1_2,count1_1,count2_1,count2_2});
        
   return z>=(int)1e9?-1:z;
    }

    //leetcode 881
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        
        
          int si=0;
          int e=people.size()-1;
        int count=0;
                       while(people[e]==limit)
                      {  
                         count++;
                           e--;
                       }    
           
        while(si<=e)
           {
              if(people[si]+people[e]> limit)
              {    e--;
                count++;
              }
              else
              {
                  count++;
                  e--;
                  si++;
              }
            
           }
        
        return count;
        
    }

    //leetcode 43
        string multiply(string num1, string num2) {
        
        
        int n=num1.size();
        int m=num2.size();
        
         if(num1=="0" || num2=="0")
              return "0";
        // vector<int>ans(n+m,0);
        
          string ans="";
        
          for(int i=0;i<n+m;i++)
              ans+='0';
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int val=(num1[i]-'0')*(num2[j]-'0');
                int finalval=val+(ans[i+j+1]-'0');
                
                int rem=finalval%10;
                int que=finalval/10;
                
                 ans[i+j+1]=(rem+'0');
                
                  int carry=(ans[i+j]-'0')+que;
                
                  ans[i+j]=(carry+'0');
                 
                
            }
        }
        
        
         
//            string s="";
        
//           for(int i=0;i<ans.size();i++)
//           {
//               if(i==0 && ans[i]==0)
//                   continue;
             
//                 s+=to_string(ans[i]);
//           }
        
        if(ans[0]=='0')
              return ans.substr(1);
        
       else
           return ans;
    }

    //pair differnce
    bool findPair(int arr[], int size, int n){
    //code
    
    
    sort(arr,arr+size);
    
      int si=0;
      int ei=1;
      
        while(ei<size && si<size)
        {
            if(arr[ei]-arr[si]==n)
              return true;
            
            else if(arr[ei]-arr[si]>n)
               si++;
            else
             ei++;
        }
        
        
        return false;
}

//leetcode 632
 vector<int> smallestRange(vector<vector<int>>& nums) {
        
        
        int range=(int)1e9;
        
          priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
          
          //number,x,y;
        
          int max1=-(int)1e9;
           int row=0;
          for(vector<int>&arr:nums)
          {
              
                max1=max(max1,arr[0]);
                pq.push({arr[0],row,0});
              
                row++;
          }
        
        //  cout<<max1<<endl;
          int size1=nums.size();
          int a;
        int b;
        
             while(pq.size()==size1)
             {
                 vector<int>ans=pq.top();
                 pq.pop();
                 int ele=ans[0];
                 //ut<<ele<<endl;
                 int x=ans[1];
                 int y=ans[2];
                 
                 if(range>max1-ele)
                 {
                     range=max1-ele;
                    a=max1;
                     b=ele;
                 }
                 
                 y++;
                 if(y<nums[x].size())
                 {
                     max1=max(max1,nums[x][y]);
                     
                     pq.push({nums[x][y],x,y});
                 }
                 
             }
        
        vector<int>res;
        res.push_back(b);
        res.push_back(a);
        
        return res;
       // return range;
    }

    //leetcode 152
     int maxProduct(vector<int>& nums) {
        
        int o_max=nums[0];
        
        
        int max_ending_here=nums[0];
        
        int min_ending_here=nums[0];
        
        
        
        for(int i=1;i<nums.size();i++)
        {
            int temp=max_ending_here;
            
            max_ending_here=max({nums[i],nums[i]*max_ending_here,nums[i]*min_ending_here});
            
            min_ending_here=min({nums[i],nums[i]*temp,nums[i]*min_ending_here});
            
            o_max=max(o_max,max_ending_here);
        }
        
        return o_max;
    }

    //https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

        int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	
    	int platform=0;
    	 int omax=0;
    	int i=0;
    	int j=0;
    	  while(j<n)
    	  {
    	     
    	       if(arr[j]<=dep[i])
    	       {
    	           platform++;
    	           omax=max(platform,omax);
    	           j++;
    	       }
    	       else
    	       {
    	           i++;
    	           platform--;
    	       }
    	  }
    	  
    	  return omax;
    }

    //leetcode 41
    int firstMissingPositive(vector<int>& nums) {
        
        
        int n=nums.size();
        
         
        
        for(int i=0;i<n;i++)
        {
            while((i+1)!=nums[i])
            {
                
                if(nums[i]<1 || nums[i]>n)
                      break;
                //cout<<i<<" "<<nums[i]<<endl;
                if(nums[nums[i]-1]!=nums[i])
                 swap(nums[i],nums[nums[i]-1]);
                else
                    break;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=(i+1))
                return i+1;
            
            
            
        }
        
        
        return n+1;
        
    }

    //leetcode 48
        void rotate(vector<vector<int>>& matrix) {
        
        
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix[0].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
       
        for(vector<int>&arr:matrix)
        {
            reverse(arr.begin(),arr.end());
        }
       
        
       
    }

    //leetcode 838
     string pushDominoes(string dom) {
       
        
    int n=dom.size();
        
        bool flag1=false;
                bool flag2=false;
        if(dom[n-1]=='.')
        {
            //cout<<dom[n+1]<<endl;
            dom+='R';
            flag2=true;
        }
        if(dom[0]=='.')
        {
              dom ='L'+dom;
            flag1=true;
        }
        
        
          
        
        int i=0;
        int j=1;
       while(i<dom.size() && j<dom.size())
       {
            while(dom[j]=='.')
            {
                j++;
            }
          // cout<<j<<endl;
           
           if(dom[i]=='L' && dom[j]=='L')
           {
               for(int k=i+1;k<j;k++)
                   dom[k]='L';
           }
           else if(dom[i]=='R' && dom[j]=='R')
           {
                for(int k=i+1;k<j;k++)
                {
                   // cout<<k<<endl;
                   dom[k]='R'; 
                }  
                   
           }
           else if(dom[i]=='R' && dom[j]=='L')
           {
               
               int len=j-i-1;
               
                 if(len%2!=0)
                 {
                     int w=0;
                     for(int k=i+1;k<j;k++)
                     {
                          if(w<len/2)
                            dom[k]='R';
                          else if(w>len/2)
                              dom[k]='L';
                         
                          w++;
                     }   
                 }
               else
               {
                  int w=0;
                     for(int k=i+1;k<j;k++)
                     {
                          if(w<len/2)
                            dom[k]='R';
                          else
                              dom[k]='L';
                         
                          w++;
                     }     
               }
           }
           
           i=j;
           j++;
       }
        
        if(flag1)
        {
            dom.erase(0,1);

        }
        
        if(flag2)
        {
            dom.pop_back();
        }
        
        //cout<<dom<<endl;
        
        return dom;
        
        
        
        
    }
    //leetcode 680
     bool validPalindrome(string s) {
        
        
        int count=0;
        
          int i=0;
           int ei=s.size()-1;
        
          while(i<=ei)
          {
              if(s[i]==s[ei])
              {
                  i++;
                  ei--;
              }
              else
              {
                  return ispla(s,i,ei-1) || ispla(s,i+1,ei); 
              }
          }
        
        return true;
        //return cpunt==1 s.size()%2==0?true:false;
    }
    
    bool ispla(string& s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
               {
                   i++;
                   j--;
               }
             else
                return false;
        }
               
        return true;       
    }

    //leetcode 891
        #define ll long long int
    int sumSubseqWidths(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        
        
        int mod=(int)1e9+7;
        long width=0;
        
        int n=nums.size();
         if(n==1)
             return 0;
        vector<ll>dp(n,1);
          for(int i=1;i<n;i++)
          {
              dp[i]=(2*dp[i-1])%mod;
              
          }
        
        for(int i=0;i<n;i++)
        {
            long val1=dp[i];
            long val2=dp[n-i-1];
            
            long fval=(((val1-val2+mod)%mod)*nums[i])%mod;
            
            width=(width+fval)%mod;
        }
        
        
        return (int)width;
    }

//leetcode 849
 int maxDistToClosest(vector<int>& seats) {
        
        
      int i=0;
       int j=0;
        
        
        int max1=-(int)1e9;
        
          while(seats[i]==0)
          {
              i++;
          }
        max1=max(max1,i);
        int ei=seats.size()-1;
        j=i;
          while(seats[ei]==0)
          {
              ei--;
          }
        
        int l=seats.size()-ei-1;
        max1=max(max1,l);
        
        
            while(i<=ei && j<=ei)
            {
                if(seats[j]==1)
                {
                    //,j-i+1);
                    max1=max(max1,(int)floor((j-i)/2));
                    i=j;
                    j++;
                }
                else
                {
                    j++;
                }
            }
        
       
        return  max1; 
        
    }

    //1375
      int numTimesAllBlue(vector<int>& light) {
        
        
        
       int max1=1;
        
     int count=0;
        
         for(int i=0;i<light.size();i++)
         {
             max1=max(max1,light[i]);
             
               if(max1==i+1)
                   count++;
         }
        
        return count;
    }

    //leetcode-1031
        int maxSumTwoNoOverlap(vector<int>& nums, int l, int m) {
        
        if(l+m>nums.size())
              return 0;
        
        vector<int>ps(nums.size());
        
          ps[0]=nums[0];
        
          for(int i=1;i<nums.size();i++)
          {
              ps[i]=ps[i-1]+nums[i];
          }
        
        
        int omax=ps[l+m-1];
         int lmax=ps[l-1];
          int mmax=ps[m-1];
        
        
          for(int i=l+m;i<nums.size();i++)
          {
              lmax=max(lmax,ps[i-m]-ps[i-m-l]);
              mmax=max(mmax,ps[i-l]-ps[i-m-l]);
                //cout<<lmax<<" "<<mmax<<endl;
              omax=max({omax,lmax+ps[i]-ps[i-m],mmax+ps[i]-ps[i-l]});
              
          }
          
        
        return omax;
        
    }

    //https://www.lintcode.com/problem/920/
    class Interval {
        public:
       int start, end;
        Interval(int start, int end) {
          this->start = start;
          this->end = end;
      }
  };

    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code 
        

        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){

            return a.start <b.start;
        });

          for(int i=1;i<intervals.size();i++)
          {
              if(intervals[i].start<intervals[i-1].end)
                  return false;
          }

          return true;
    }


    //https://www.lintcode.com/problem/919/
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here

        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){

            return a.start <b.start;
        });

          priority_queue<int,vector<int>,greater<int>>pq;
       
             int count=1;
             pq.push(intervals[0].end);
          for(int i=1;i<intervals.size();i++)
          {
                  int end_time=pq.top();

                    if(end_time>intervals[i].start)
                        { 
                            count++;
                            pq.push(intervals[i].end);
                        }
                     else
                     {
                         pq.pop();
                         pq.push(intervals[i].end);

                     }             // return false;
          }


          return count;
    }

//leetcode 452
    int findMinArrowShots(vector<vector<int>>& interval) {
         sort(interval.begin(),interval.end(),[](vector<int>&a,vector<int>&b){
                                                  
            return a[0]<b[0];
});
        
        int count=1;
        
       int max_start=interval[0][0];
        int min_end=interval[0][1];
        
          for(int i=1;i<interval.size();i++)
          {
              if(interval[i][0] >= max_start &&  interval[i][0] <=min_end)
              {
                  max_start=interval[i][0];
                    min_end=min(min_end,interval[i][1]);
              }
              else
              {
                  count++;
                  max_start=interval[i][0];
                  min_end=interval[i][1];
              }
          }
        
        return count;
    }

    //leetcode 57
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)  {
         intervals.push_back(newInterval);
         sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
                                                  
            return a[0]<b[0];
});
        vector<vector<int>>ans;
          ans.push_back(intervals[0]);
          int j=1;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=ans[j-1][1] && intervals[i][0] >=ans[j-1][0])
            {
                ans[j-1][1]=max(ans[j-1][1],intervals[i][1]);
            }
            else
            {
                j++;
                ans.push_back(intervals[i]);
            }
        }
        
        
        return ans;
    }

    //leetcode 986
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        
        int n=first.size();
        
         int m=second.size();
        
        
        if(n==0 || m==0)
            return {};
        
         int i=0,j=0;
        
          vector<vector<int>>ans;
          while(i<n && j<m)
          {
                
              if(first[i][1]>=second[j][0] && second[j][1] >=first[i][0])
              {
                  int si=max(first[i][0],second[j][0]);
                  int ei=min(first[i][1],second[j][1]);
                  ans.push_back({si,ei});
                  
                  
              }
              
              first[i][1] <second[j][1] ?i++:j++;
          }
        
        
           return ans;
        
    }