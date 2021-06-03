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