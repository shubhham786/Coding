#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compareTo(vector<int>&arr,int i, int j,bool isMaxheap) {
        if(isMaxheap)
            return arr[i] > arr[j];
        else
            return arr[i] < arr[j];
    } 
 void downhepify(vector<int>&arr,int i,bool isMaxheap,int li)
 {
     int maxl=i;
     int lci=2*i+1;
     int rci=2*i+2;

     if(lci<= li && compareTo(arr,lci,maxl,isMaxheap))
     {
         maxl=lci;
     }
     if(rci<= li && compareTo(arr,rci,maxl,isMaxheap))
     {
         maxl=rci;
     }

     if(maxl!=i)
     {
         swap(arr[maxl],arr[i]);
         downhepify(arr,maxl,isMaxheap,li);
     }


 }

void heapsort(vector<int>&arr,bool isMaxheap)
{
    //int n=arr.size();
    int li = arr.size() - 1;
    for (int i = li; i >= 0; i--)
        downhepify(arr,i,isMaxheap,li);

    while (li >= 0)
    {
        swap(arr[0], arr[li--]);
        downhepify(arr,0,isMaxheap,li);
    }

} 

int main()
{
    vector<int> arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };

      heapsort(arr,true);

      for(int i:arr)
      {
          cout<<i<<" ";
      }

}
