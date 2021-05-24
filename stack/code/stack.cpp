#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int>NGOR(vector<int> &a)
{
   
   vector<int> ans(a.size(),a.size());
  
   stack<int>s;

   s.push(0);
   for(int i=1;i<a.size();i++)
   {
        
        while(s.size()!=0 && a[i]>a[s.top()])
        {
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);


   } 
  
  return ans;




}

vector<int>NGOL(vector<int> &a)
{
   
   vector<int> ans(a.size(),-1);
  
   stack<int>s;

   s.push(a.size()-1);
   for(int i=a.size()-1;i>=0;i--)
   {
        
        while(s.size()!=0 && a[i]>a[s.top()])
        {
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);


   } 
  
  return ans;




}
vector<int>NSOR(vector<int> &a)
{
   
   vector<int> ans(a.size(),a.size());
  
   stack<int>s;

   s.push(0);
   for(int i=1;i<a.size();i++)
   {
        
        while(s.size()!=0 && a[i]<a[s.top()])
        {
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);


   } 
  
  return ans;




}
vector<int>NSOL(vector<int> &a)
{
   
   vector<int> ans(a.size(),-1);
  
   stack<int>s;

   s.push(a.size()-1);
   for(int i=a.size()-1;i>=0;i--)
   {
        
        while(s.size()!=0 && a[i]<a[s.top()])
        {
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);


   } 
  
  return ans;




}

//leetcode 503
vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        stack<int>a;
        int l=nums.size();
          vector<int>ans(l,-1);
           
        a.push(0);
        for(int i=1;i<2*l;i++)
        {
             
            while(a.size()!=0 && nums[i%l]>nums[a.top()] )
            {
                ans[a.top()]=nums[i%l];
                a.pop();
            }
           
            if(i<l)
              a.push(i);
        }
      
        
        
        return ans;
        
    }
void print(vector<int>a)
{
    for(int i:a)
    {
        cout<<i<<" ";
    }
}
//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
// my solution
vector <int> calculateSpan(int price[], int n)
    {
      vector<int>ans(n,-1);
      stack<int>a;
      a.push(n-1);
      for(int i=n-2;i>=0;i--)
      {
          
          while(a.size()!=0 && price[i]>price[a.top()] )
          {
              ans[a.top()]=a.top()-i;
              a.pop();
          }
          a.push(i);
      }
     
    
    
    for(int i=0;i<n;i++)
    {
        if(ans[i]==-1)
        {
            ans[i]=i-ans[i];
        }
    }

       return ans;
    } 

//leetcode 901
class StockSpanner{
stack<vector<int>>st;
    int day=0;
    StockSpanner() {
        
        st.push({-1,-1});
    }
    
    int next(int price) {
        
        while(st.top()[0]!=-1 && price>=st.top()[1])st.pop();
        
        int span=day -st.top()[0];
        st.push({day++,price});
        return span;
    }  
};

//leetcode 20
 bool isValid(string s) {
        
        
        stack<char>a;
      
      
        for(char i:s)
        {
            if(i=='(' || i=='{' || i=='[')
            {
                a.push(i);
            }
            else
            {
                if(a.size()==0)return false;
                
                else if(i==')' && a.top()!='(')return false;
                
                else if(i=='}' && a.top()!='{')return false;
                
                else if(i==']' && a.top()!='[')return false;
                
                else
                    a.pop();
                    
            }
            
        }
        
      return a.size()==0;
    }
//leetcode 946
 bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>s;
        
        int z=0,n=popped.size();
        
        for(int i:pushed)
        {
            s.push(i);
            
            while(s.size()!=0 && s.top()==popped[z])
            {
                s.pop();
                z++;
            }
        }
        
        return s.size()==0;
    }
//leetcode 1249
//my solution
// good question to use vector as stack
 string minRemoveToMakeValid(string s) {
        
        vector<int>a;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                a.push_back(i);
            }
           else if(a.size()!=0 && s[i]==')' && s[a.back()]=='(')
               a.pop_back();
           else if(s[i]==')')
               a.push_back(i);
           else
           {
               
           }
                
        }
        
    
        
        string ans="";
        
        int idx=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(idx<a.size() && a[idx]==i){
                  idx++;
                continue;
            }  
            
            ans+=s[i];
        }
        
        return ans;
    }
//leetcode 32
//can also be solved by kaden's algo
 int longestValidParentheses(string s) {
        int n=s.length();
        
        
        stack<int>s1;
        s1.push(-1);
        int length=0;
        for(int i=0;i<n;i++)
        {
            if(s1.top()!=-1 && s[s1.top()]=='(' && s[i]== ')')
            {
                s1.pop();
                length=max(length,i-s1.top());
               
            }
            else
              s1.push(i);
        }
        
        return length;
    }
//leetcode 735
vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>a;
        
        for(int i:asteroids)
        {
          
            if(i>0)
            {
                a.push(i);
                continue;
            }
            
            while(a.size()!=0 && a.top()>0 && a.top()< -i)a.pop();
            
            if(a.size()!=0 && a.top()==-i)
                a.pop();
            else if(a.size()==0 || a.top()<0)
                a.push(i);
            else{
                
            }
            
             
        }
        
        vector<int>ans(a.size(),0);
        int idx=a.size()-1;
        
         while(a.size()!=0)
         {
             ans[idx--]=a.top();
             a.pop();
         }
        
       return ans; 
        
    }








int main()
{
    vector<int>a={3,2,-1,4,5,-3,-7,-6,-4,6,5};
    vector<int>ans=NSOL(a);
    
    print(ans);


}
