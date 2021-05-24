#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void max_priority(vector<int>& arr)
{
      priority_queue<int>pq; //max priority queue

      for(int i:arr)
      {
          pq.push(i);
      }

     while(pq.size()!=0)
     {
         cout<<pq.top()<<" ";
           
            pq.pop();
     }
}
void min_priority(vector<int>& arr)
{
      priority_queue<int,vector<int>,greater<int>>pq; //min priority queue

      for(int i:arr)
      {
          pq.push(i);
      }

     while(pq.size()!=0)
     {
         cout<<pq.top()<<" ";
           
            pq.pop();
     }
}


class comparator{
     public:
        
         bool operator()(const vector<int>&a,const vector<int>&b)const{


             //return a[0]>b[0]; // operator overloaded ko overload kar rahe hai (this > other)// min pq
              return b[0]>a[0]; //max pq
         }

};
void two_d_priority_queue(vector<vector<int>>&arr)
{
   
      priority_queue<vector<int>,vector<vector<int>>,comparator>pq;

       for(vector<int>& i :arr)
      {
          pq.push(i);
      }

     while(pq.size()!=0)
     {

         vector<int>a=pq.top();

         cout<<"( "<<a[0]<<" "<<a[1]<<" )";
           cout<<endl;
            pq.pop();
     }
}


int main()
{
    vector<vector<int>>arr={{2, 5}, {1, -1}, {0, -4}, {-6, 3}, {6, 9}, {9, 40}};

    two_d_priority_queue(arr);
}