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