#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


int binary_search(vector<int>&arr,int data)
{
    int n=arr.size(),s=0,e=n-1;


       while(s<=e)
       {
           int mid=(s+e)/2; //s+ (e-s)/2;

           if(arr[mid]==data)
             return mid;

           else if(arr[mid]>data)
             e=mid-1;
            else
              s=mid+1;   
       }


       return -1;
}

int first_index(vector<int>&arr,int data)
{
    int n=arr.size(),s=0,e=n-1;

    int index=-1;
       while(s<=e)
       {
           int mid=(s+e)/2; //s+ (e-s)/2;

           if(arr[mid]==data){
            // return mid;

              index=mid;
              e=mid-1;
           }
           else if(arr[mid]>data)
             e=mid-1;
            else
              s=mid+1;   
       }


       return index;
}

int last_index(vector<int>&arr,int data)
{
    int n=arr.size(),s=0,e=n-1;

    int index=-1;
       while(s<=e)
       {
           int mid=(s+e)/2; //s+ (e-s)/2;

           if(arr[mid]==data){
            // return mid;

              index=mid;
              s=mid+1;
           }
           else if(arr[mid]>data)
             e=mid-1;
            else
              s=mid+1;   
       }


       return index;
}

//leetcode 34
vector<int> searchRange(vector<int>& nums, int target) {
            
        return {first_index(nums,target),last_index(nums,target)};
    }


    int insert_at_location(vector<int>&arr,int data)
    {
        int n=arr.size(),s=0,e=n-1;

          while(s<=e)
          {
              int  mid=(s+e)/2;

              if(arr[mid]<=data)
              {
                  s=mid+1;
              }
              else
               e=mid-1;
          }

          return s;
    }
//if element present return last index else return position where to be inserted
    int perfectPosOfElement(vector<int> &arr, int data)
    {
        int n=arr.size(),s=0,e=n-1;

            while(s<=e)
            {
                int mid=(s+e)/2;

                if(arr[mid]<=data)
                {
                    s=mid+1;
                }
                else 
                 e=mid-1;
            }


            int insertposition=s;
            int  lastindex=s-1;

        return (last_index>=0 && arr[lastindex]==data)?lastindex:insertposition;
    }

    int nearestElement(vector<int> &arr, int data)
{
    if (arr.size() == 0)
        return 0;

    int n = arr.size();
    if (data <= arr[0] || data >= arr[n - 1])
        return data <= arr[0] ? arr[0] : arr[n - 1];

    int si = 0, ei = n - 1;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] <= data)
            si = mid + 1;
        else
            ei = mid - 1;
    }

    return data - arr[ei] <= arr[si] - data ? arr[ei] : arr[si];
}
//leetcode 74

   bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        
          int s=0,e=n*m-1;
       
          while(s<=e)
          {
              int mid=(s+e)/2;
              
              int r=mid/m;
              int c=mid%m;
              
              if(matrix[r][c]==target)
                  return true;
              else if(matrix[r][c]>target)
                  e=mid-1;
              else
                  s=mid+1;
          }
              
        return false;
    }

    //leetcode 240
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int n=matrix.size(),m=matrix[0].size(),r=n-1,c=0;
        
          while(r>=0 && c<m)
          {
              int ele=matrix[r][c];
              
              if(ele==target)
                  return true;
              
              else if(ele<target)
                   c++;
              else
                  r--;
          }
        
        return false;
    }

//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// just like merge sort with slight modofication
long long int inversion(long long arr[], int si,int ei,int mid)
{
    int lsi=si,lei=mid;
    int rsi=mid+1,rei=ei;
      
    long count=0;
    long sorted_array[ei-si+1];
    int k=0;

      while(lsi<=lei && rsi<=rei)
      {
          if(arr[lsi]>arr[rsi])
           {
               count+=(lei-lsi+1);
               sorted_array[k++]=arr[rsi++];

           }
           else
              sorted_array[k++]=arr[lsi++];
      }

      while(lsi<=lei)
       sorted_array[k++]=arr[lsi++];

     while(rsi<=rei)
       sorted_array[k++]=arr[rsi++];
      
       k=0;
       for(int i=si;i<=ei;i++)
       {
          arr[i]=sorted_array[k++];
       }

       return count;
}
long long int inversionCount1(long long arr[], int si,int ei)
{
    if(si>=ei)
      return 0;
   
    int mid=(si+ei)/2;
     
      long LCI=inversionCount1(arr,si,mid); //LCI: left count inversion
     long RCI=inversionCount1(arr,mid+1,ei);

     return LCI+RCI+inversion(arr,si,ei,mid);
}
long long int inversionCount(long long arr[], long long N)
{

     return  inversionCount1(arr,0,(int)N-1);   
}

//
long long InversionAcrossArray(vector<long long> &arr, int l, int r, int mid, vector<long long> &sortedArray)
{
    int lsi = l, lei = mid;
    int rsi = mid + 1, rei = r;

    int k = 0;
    long count = 0;
    while (lsi <= lei && rsi <= rei)
    {
        if (arr[lsi] > arr[rsi])
        {
            count += (lei - lsi + 1);
            sortedArray[k++] = arr[rsi++];
        }
        else
            sortedArray[k++] = arr[lsi++];
    }

    while (lsi <= lei)
        sortedArray[k++] = arr[lsi++];
    while (rsi <= rei)
        sortedArray[k++] = arr[rsi++];

    // for (k = 0; k < sortedArray.length; k++)
    // arr[k + l] = sortedArray[k];

    k = 0;
    for (int i = l; i <= r; i++)
        arr[i] = sortedArray[k++];

    return count;
}

long long inversionCount(vector<long long> &arr, int si, int ei, vector<long long> &sortedArray)
{
    if (si >= ei)
        return 0;

    int mid = (si + ei) / 2;
    long ICL = inversionCount(arr, si, mid, sortedArray); // IC : Inversion Count, L = left , R = Right
    long ICR = inversionCount(arr, mid + 1, ei, sortedArray);

    return (ICL + ICR + InversionAcrossArray(arr, si, ei, mid, sortedArray));
}

long long inversionCount(long long ar[], long N)
{
    if (N <= 1)
        return 0;

    vector<long long> arr;
    for (int i = 0; i < N; i++)
        arr.push_back(ar[i]);

    vector<long long> sortedArray(N, 0);
    return inversionCount(arr, 0, (int)N - 1, sortedArray);
}

//leetcode 33

    int search(vector<int>& arr, int tar) {
        
        
        int si=0,ei=arr.size()-1;
        
          while(si<=ei)
          {
              int mid=(si+ei)/2;
              
              if(arr[mid]==tar)
                  return mid;
              
             else if(arr[mid]>=arr[si])
             {
                 if(arr[si]<=tar && arr[mid]>tar)
                     ei=mid-1;
                 else
                     si=mid+1;
             }
              else
              {
                  if(arr[ei]>=tar && arr[mid]<tar)
                     si=mid+1;
                 else
                     ei=mid-1;
              }
          }
        
        return -1;
    }

    //leetcode 81
     bool search1(vector<int>& arr, int tar) {
         int si=0,ei=arr.size()-1;
        
          while(si<=ei)
          {
              int mid=(si+ei)/2;
              
              if(arr[mid]==tar || arr[si]==tar)//important step
                  return true;
              
             else if(arr[mid]>arr[si])
             {
                 if(arr[si]<tar && arr[mid]>tar)// si me equal to ka sign hata diya hai
                     ei=mid-1;
                 else
                     si=mid+1;
             }
              else if(arr[mid]<arr[ei])
              {
                  if(arr[ei]>=tar && arr[mid]<tar)
                     si=mid+1;
                 else
                     ei=mid-1;
              }
              else
              {
                  si++;
              }
          }
        
        return false;
        
    }

    //leetcode 153
      int findMin(vector<int>& arr) {
        
        int si=0,ei=arr.size()-1;
        
        if(arr[si]<arr[ei])
            return arr[si];
        
        
        while(si<ei)
        {
            int mid=(si+ei)/2;
            
             
            if(arr[mid]<arr[ei])//subarry is sorted then pivot  milne ke chances mid pe jayda hai
              ei=mid;
             
            else
                si=mid+1;
        }
        
        return arr[si];
        
    }

//SUM CATEGORY


//leetcode 167
//two sum
vector<int> twoSum(vector<int>& arr, int tar) {
        
        int si=0,ei=arr.size()-1;
    
         while(si<ei)
         {
             if(arr[si]+arr[ei]==tar)
                 return {si+1,ei+1};
             
             else if(arr[si]+arr[ei]>tar)
                 ei--;
             else
                 si++;
         }
    
        return {};
    }

//find all unique pair that sum to a target

vector<vector<int>> twoSum_return_unique_pair(vector<int>& arr, int tar) {
        
        int si=0,ei=arr.size()-1;
       vector<vector<int>>ans;
         while(si<ei)
         {
             if(arr[si]+arr[ei]==tar){
             
                 ans.push_back({si+1,ei+1});
                si++;
                ei--;
                 while(si<ei && arr[si]==arr[si-1])si++;
                 while(si<ei && arr[ei]==arr[ei+1])ei--;
             }
             else if(arr[si]+arr[ei]>tar)
                 ei--;
             else
                 si++;
         }
    
        return ans;
    }


    //leetcode 15
     int seggragate(vector<int>&arr,int si,int ei,int pivot)      
    {
         swap(arr[pivot],arr[ei]);
        
          int p=si-1;
          
          while(si<=ei)
          {
              if(arr[si]<=arr[ei])
                  swap(arr[++p],arr[si]);
              
              si++;
          }
        
        return p;
    }
    
    void quicksort(vector<int>&arr,int si,int ei)
    {
        if(si>ei)
            return;
        
        
        int l=ei-si+1;
        
        int pivot=rand()%l+si;
        
         int q=seggragate(arr,si,ei,pivot);
         
        quicksort(arr,si,q-1);
        quicksort(arr,q+1,ei);
        
    }
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        if(arr.size()==1 || arr.size()==0)
            return {};
        
        int el=arr.size()-1;
        quicksort(arr,0,el);
        
        for(int &i:arr)
            cout<<i<<" ";
        
       // int si=0;
        cout<<endl;
        
        vector<vector<int>>ans;
        for(int i=0;i<arr.size()-2;i++)
        {
            //cout<<i<<" ";
            
            if(i>=1 && arr[i]==arr[i-1])
                continue;
            
           // cout<<i<<endl;
            
            int si=i+1;
            int ei=el;
               while(si<ei)
             {
               if(arr[i]+arr[si]+arr[ei]==0){
             
                 ans.push_back({arr[i],arr[si],arr[ei]});
                si++;
                ei--;
                 while(si<ei && arr[si]==arr[si-1])si++;
                 while(si<ei && arr[ei]==arr[ei+1])ei--;
             }
             else if(arr[i]+arr[si]+arr[ei]>0)
                 ei--;
             else
                 si++;
           }
        }
        
        return ans;
        
    }

// generic way
vector<vector<int>> twoSum(vector<int>& arr, int tar,int si,int ei) {
        
        
       vector<vector<int>>ans;
         while(si<ei)
         {
             if(arr[si]+arr[ei]==tar){
             
                 ans.push_back({arr[si],arr[ei]});
                si++;
                ei--;
                 while(si<ei && arr[si]==arr[si-1])si++;
                 while(si<ei && arr[ei]==arr[ei+1])ei--;
             }
             else if(arr[si]+arr[ei]>tar)
                 ei--;
             else
                 si++;
         }
    
        return ans;
    }

void prepare_ans(vector<vector<int>>& ans,vector<vector<int>>&smallans,int& fix_ele)
{
        
        for(vector<int>& j:smallans)
        {
            vector<int>ar;
             ar.push_back(fix_ele);
             for(int& i :j)
               ar.push_back(i);

            ans.push_back(ar);   
               
        }
}
  vector<vector<int>> threeSum1(vector<int>& arr, int tar,int si,int ei) { 

      vector<vector<int>>ans;

      for(int i=si;i<ei;)
      {
          vector<vector<int>>ans1=twoSum(arr,tar-arr[i],i+1,ei);
           prepare_ans(ans,ans1,arr[i]);

           i++;
           while(i<ei && arr[i]==arr[i-1])i++;
      } 
          
          return ans;
  } 
 vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();

        sort(arr.begin(),arr.end());
        
         int tar=0;
        return threeSum1(arr,tar,0,n-1);

    }

 vector<vector<int>> foursum1(vector<int>& arr, int tar,int si,int ei) { 

      vector<vector<int>>ans;

      for(int i=si;i<ei;)
      {
          vector<vector<int>>ans1=threeSum1(arr,tar-arr[i],i+1,ei);
           prepare_ans(ans,ans1,arr[i]);

           i++;
           while(i<ei && arr[i]==arr[i-1])i++;
      } 
          
          return ans;
  } 
     vector<vector<int>> fourSum(vector<int>& arr, int tar) {
        int n=arr.size();

        sort(arr.begin(),arr.end());
        

        return foursum1(arr,tar,0,n-1);
    }

    vector<vector<int>> Ksum(vector<int>& arr, int tar,int k,int si,int ei) { 

      if(k==2)
      {
          return twoSum(arr,tar,si,ei);
          
      }
   
      vector<vector<int>>ans;

      for(int i=si;i<ei;)
      {
          vector<vector<int>>ans1=Ksum(arr,tar-arr[i],k-1,i+1,ei);
           prepare_ans(ans,ans1,arr[i]);

           i++;
           while(i<ei && arr[i]==arr[i-1])i++;
      } 
          
          return ans;
  } 

  //two sum count
    int twosumcount(vector<int>& nums1,vector<int>& nums2,int tar)
    {
        //int si=0;
       // int n=nums1.size()-1;
        
        
        int count=0;
        
        unordered_map<int,int>map;
        
        for(int &ele:nums1)
        {
            map[ele]++;
            
        }
        
        for(int &ele:nums2)
        {
            if(map.find(ele-tar)!=map.end())
                count+=map[ele-tar];
        }
        
        count;
    }

    //leetcode 454

      int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
          unordered_map<int,int>map;
        
           for(int & ele:nums1)
               for(int &ele1:nums2)
                    map[ele+ele1]++;
        
        
           int count=0;
         int tar=0;
           for(int &ele2:nums3)
               for(int &ele3:nums4)
                   if(map.find(tar-(ele2+ele3))!=map.end())
                       count+=map[tar-(ele2+ele3)];
        
        
        return count;
    }

    //leetcode 658
     bool pos(vector<int>& arr,int x,int &pos1)
    {
        int si=0;
        int ei=arr.size()-1;
        
         while(si<=ei)
         {
             int mid=(si+ei)/2;
             
             if(arr[mid]==x){
                 pos1=mid;
                 return true;
             }  
             
             else if(arr[mid]>x)
                 ei=mid-1;
             else
                 si=mid+1;
             
         }
        
        pos1=si;
        
        return false;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int pos1=0;
        bool l=pos(arr,x,pos1);
          //cout<<pos1;  
            vector<int>ans;
         int i=pos1-1;
         int j=pos1;
        if(l==true){
            ans.push_back(x);
             i=pos1-1;
            j=pos1+1;
             k--;
        }  
           while(i>=0 && j<arr.size() && k-->0)
           {
               if(abs(arr[i]-x)<=abs(arr[j]-x))
                   ans.push_back(arr[i--]);
               else
                   ans.push_back(arr[j++]);
           }
        
           while(i>=0 && k-->0)
           {
               ans.push_back(arr[i--]);
           }
        
          while(j<arr.size() && k-->0)
          {
              ans.push_back(arr[j++]);
          }
               
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
            
    }

    //another_best _method
      int pos(vector<int>& arr,int x)
    {
        int si=0;
        int ei=arr.size()-1;
        
         while(si<=ei)
         {
             int mid=(si+ei)/2;
             
             if(arr[mid]==x){
            
                 return mid;
             }  
             
             else if(arr[mid]>x)
                 ei=mid-1;
             else
                 si=mid+1;
             
         }
        
        //pos1=si;
        
        return si;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
       // int pos1=0;
        int l=pos(arr,x);
          //cout<<pos1;  
        int n=arr.size();
        int lr=max(0,l-k);
        int rr=min(n-1,l+k);
           // vector<int>ans;
         
          while((rr-lr+1)>k)
          {
               if(x-arr[lr] > arr[rr]-x)
                   lr++;
               else
                   rr--;
          }
            
        return {arr.begin()+lr,arr.begin()+rr+1};
    }


    //O(log(n)+ k)
      vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       
        
          int n=arr.size();
        
            
           if(x<=arr[0])
               return {arr.begin(),arr.begin()+k};
           else if(x>=arr[n-1])
               return {arr.end()-k,arr.end()};
          else
          {
              int si=0,ei=n-k;
                
                  while(si<ei)
                  {
                      int mid=(si+ei)/2;
                      
                       if(abs(arr[mid]-x)>abs(arr[mid+k]-x))
                           si=mid+1;
                       else
                           ei=mid;
                  }
              
              return {arr.begin()+si,arr.begin()+si+k};
          }
    }

    //leetcode 300
        
    int insert_position(vector<int>&ans,int data)
    {
        int si=0,ei=ans.size()-1;
        
         while(si<=ei)
         {
             int mid=(si+ei)/2;
             
               if(ans[mid]<=data)
                   si=mid+1;
               else
                   ei=mid-1;
         }
        
        int laspos=si-1;
        return  laspos>=0 && data==ans[laspos]?laspos:si;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        
        
        vector<int>ans;
       // ans.push_back(nums[0]);
        
        for(int i=0;i<nums.size();i++)
        {
            int k=insert_position(ans,nums[i]);
            
            //if(ans[k]<nums[i])
              //  ans[k]=nums[k]
            //cout<<ans.size()<<" "<<k<<endl;
            //cout<<k<<endl;
             if(k==ans.size())
               ans.push_back(nums[i]); // 
            else
                ans[k]=nums[i];
        }
        
        return ans.size();
    }