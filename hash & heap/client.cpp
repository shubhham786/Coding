#include<iostream>
#include<vector>
#include<algorithm>
#include "heap.cpp"
using namespace std;
int main()
{
    vector<int> arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };
         heap pq(arr, false);

         while(pq.size()!=0)
         {
             cout<<pq.remove()<<" ";
         }
}
