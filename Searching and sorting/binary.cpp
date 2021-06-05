#include<iostream>
#include<vector>

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