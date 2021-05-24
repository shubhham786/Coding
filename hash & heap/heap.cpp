#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class heap{

private:
     vector<int>arr;
     bool isMaxheap=true;


    void defaultvalue(bool isMaxheap)
    {
        this->isMaxheap=isMaxheap;
    }

    void constructheap()
    {
        int l=this->arr.size();
        for(int i=l-1;i>=0;i--)
        {
            downhepify(i);
        }
    }

public:
   
    heap()
    {
        defaultvalue(true);
    }

    heap(bool isMaxheap)
    {
        defaultvalue(isMaxheap);
    }

    heap(vector<int>a,bool isMaxheap)
    {
        defaultvalue(isMaxheap);

        for(int i=0;i<a.size();i++)
        {
            this->arr.push_back(a[i]);
        }

        constructheap();
    }

 bool compareTo(int i, int j) {
        if(isMaxheap)
            return this->arr[i] > this->arr[j];
        else
            return this->arr[i] < this->arr[j];
    }  
 int size()
 {
     return this->arr.size();
 }

bool isempty()
{
    return this->arr.size()==0;
}

int remove()
{
       int ele=this->arr[0];
       int n=this->arr.size();

        swap(this->arr[0],this->arr[n-1]);

        this->arr.pop_back();

          downhepify(0);

          return ele;

}


void add(int ele)
{
       int indx=this->arr.size();
      this->arr.push_back(ele);
      
         uphefiy(indx);

}
 void downhepify(int i)
 {
     int maxl=i;
     int lci=2*i+1;
     int rci=2*i+2;

     if(lci< this->arr.size() && compareTo(lci,maxl))
     {
         maxl=lci;
     }
     if(rci< this->arr.size() && compareTo(rci,maxl))
     {
         maxl=rci;
     }

     if(maxl!=i)
     {
         swap(this->arr[maxl],this->arr[i]);
         downhepify(maxl);
     }


 }

 void uphefiy(int indx){

     int par=(indx-1)/2;

     if(par<=0 && compareTo(indx,par))
     {
         swap(this->arr[par],this->arr[indx]);
          uphefiy(par);
     }
 }


};