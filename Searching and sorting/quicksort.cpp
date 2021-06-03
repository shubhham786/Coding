#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;


int seggragate(vector<int>&arr,int si,int ei,int pivot)
{
    swap(arr[pivot],arr[ei]);

    int p=si-1;
    int itr=si;

       
       while(itr<=ei)
       {
           if(arr[itr]<=arr[ei])
             swap(arr[++p],arr[itr]);

           itr++;  
       }

       return p;

}

void quicksort(vector<int>&arr,int si,int ei)
{

    if(si>ei)
       return ;
    
    int len=ei-si+1; 
   // randomized quicksort
    int pivot=rand()%len+si;// jo bhi location dena hai
       int l=seggragate(arr,si,ei,pivot);

       quicksort(arr,si,l-1);
       quicksort(arr,l+1,ei);


}

int main()
{
    vector<int>arr={-12, 2, 7, 4, 34, 23, 0, 1, -1, -50, 16, 23, 7, 4, 2, 3};

    quicksort(arr,0,arr.size()-1);
   // cout<<"1"<<endl;
    for(int & i:arr)
     cout<<i<<" ";
}