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

//leetcode 84
    vector<int>NSOR(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>s;
        vector<int>ans(n,n);
       
        
        for(int i=0;i<n;i++)
        {
            while(s.size()!=0 && heights[i]<heights[s.top()])
            {
                ans[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
    
      vector<int>NSOL(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>s;
        vector<int>ans(n,-1);
      
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()!=0 && heights[i]<heights[s.top()])
            {
                ans[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>ans1=NSOR(heights);
        vector<int>ans2=NSOL(heights);
       
        int max_area=0;
        
        for(int i=0;i<heights.size();i++)
        {
            max_area=max(max_area,(ans1[i]-ans2[i]-1)*heights[i]);
        }
        

          return  max_area;
        
        
        
        
    }
//method2
int largestRectangleArea_02(vector<int>& heights){
    
    int n=heights.size();
    
    stack<int>s;
    
        s.push(-1);
    
      int max_area=0;
          
    for(int i=0;i<n;i++)
    {
        
          while(s.top()!=-1 && heights[i]<=heights[s.top()])
          {
              int idx=s.top();
              s.pop();
              max_area=max(max_area,(i-s.top()-1)*heights[idx]);
        
          }
        
        s.push(i);
        
    }
    
    
          while(s.top()!=-1 )
          {
              int idx=s.top();
              s.pop();
              max_area=max(max_area,(n-s.top()-1)*heights[idx]);
        
          }
        
 
    
    return max_area;
}

//leetcode 85
//used upper coded code
      vector<int>NSOR(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>s;
        vector<int>ans(n,n);
       
        
        for(int i=0;i<n;i++)
        {
            while(s.size()!=0 && heights[i]<heights[s.top()])
            {
                ans[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
    
      vector<int>NSOL(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>s;
        vector<int>ans(n,-1);
      
        
        for(int i=n-1;i>=0;i--)
        {
             while(s.size()!=0 && heights[i]<heights[s.top()])
            {
                ans[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>ans1=NSOR(heights);
        vector<int>ans2=NSOL(heights);
       
        int max_area=0;
        
        for(int i=0;i<heights.size();i++)
        {
            max_area=max(max_area,(ans1[i]-ans2[i]-1)*heights[i]);
        }
        

          return  max_area;
        
        
        
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
        if(matrix.size()==0)
        {
            return 0;
        }
        int n=matrix.size();
        int m=matrix[0].size();
        
        int max_area=0;
         vector<int>a(m,0);
        for(int i=0;i<n;i++)
        {
            
             for(int j=0;j<m;j++)
             {
                 if(matrix[i][j]=='1')
                 {
                     a[j]+=1;
                 }
                 else
                 {
                     a[j]=0;
                 }
             }
            
            max_area=max(max_area,largestRectangleArea(a));
        }
        
        return max_area;
    }
//leetcode 221
          vector<int>NSOR(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>s;
        vector<int>ans(n,n);
       
        
        for(int i=0;i<n;i++)
        {
            while(s.size()!=0 && heights[i]<heights[s.top()])
            {
                ans[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
    
      vector<int>NSOL(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>s;
        vector<int>ans(n,-1);
      
        
        for(int i=n-1;i>=0;i--)
        {
             while(s.size()!=0 && heights[i]<heights[s.top()])
            {
                ans[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>ans1=NSOR(heights);
        vector<int>ans2=NSOL(heights);
       
        int max_area=0;
        
        for(int i=0;i<heights.size();i++)
        {
            int w=(ans1[i]-ans2[i]-1);
            int h=heights[i];
            max_area=max(max_area,(w<h)?w*w:h*h);
        }
        

          return  max_area;
        
        
        
        
    }
   
    int maximalSquare(vector<vector<char>>& matrix) {
         
        if(matrix.size()==0)
        {
            return 0;
        }
        int n=matrix.size();
        int m=matrix[0].size();
        
        int max_area=0;
         vector<int>a(m,0);
        for(int i=0;i<n;i++)
        {
            
             for(int j=0;j<m;j++)
             {
                 if(matrix[i][j]=='1')
                 {
                     a[j]+=1;
                 }
                 else
                 {
                     a[j]=0;
                 }
             }
            
            max_area=max(max_area,largestRectangleArea(a));
        }
        
        return max_area;
    }    
//leetcode 42
int trap(vector<int>& height) {
        
        int n=height.size();
        
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        int max1=INT_MIN;
        int max2=INT_MIN;
        for(int i=0;i<n;i++)
        {
            max1=max(max1,height[i]);
            left[i]=max1;
            max2=max(max2,height[n-i-1]);
            right[n-i-1]=max2;
            
        }
        
     

        int trap=0;
        
        for(int i=0;i<n;i++)
        {
            trap+=min(left[i],right[i])-height[i];
        }
   
        return trap;
    }
 
    //method2(using one stack)
    int trap(vector<int>& height) {
           
        int n=height.size();
        
        stack<int>st;
        int total=0;
        for(int i=0;i<n;i++)
        {
            while(st.size()!=0 && height[st.top()]<=height[i])
            {
                int id=st.top();
                st.pop();
                
                if(st.size()==0)
                    continue;
                
                
                int w=i-st.top()-1;
                int h=height[id];
                    
                total+= (min(height[st.top()],height[i])-h)*w;
                
                
            }
            st.push(i);
        }
        
        return total;
    } 
//method3 using 2 pointer
      int trap(vector<int>& height){
          
          int n=height.size();
          
          int lmax=0,rmax=0;
          int l=0,r=n-1;
          
          int total=0;
          while(l<r)
          {
              lmax=max(lmax,height[l]);
              rmax=max(rmax,height[r]);
              
              total+=lmax<rmax?lmax-height[l++]:rmax-height[r--];
          }
          
          return total;
      }




//leetcode 402
string removeKdigits(string num, int k) {
        
        
        vector<char>s;
        
        for(int i=0;i<num.length();i++)
        {
          
            
            int r=(num[i])-'0';
           // cout<<r<<endl;
          
            while(s.size()!=0 && (int)(s.back()-'0')>r && k>0)
            {
                cout<<"1*";
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
             // cout<<"front"<<s.back()<<endl;
        }
        
        //for decresing sequence
        
        while(k-->0)
        {
            s.pop_back();
        }
        
      
        
        bool flag=false;
        
        string ans="";
        
        for(char ch :s)
        {
            if(ch=='0' && flag==false)
            {
                continue;
            }
            
            flag=true;
           ans+=(ch);
        }
       
        if(ans=="")
            ans+='0';
        return ans;

}
//leetcode 316
 string removeDuplicateLetters(string s) {

        
        
        //sort(s.begin(),s.end());
        
        vector<char>st;
        
        vector<int>fre(26,0);
        
        for(int i=0;i<s.length();i++)
        {
            fre[s[i]-'a']++;
        }
        
        vector<bool>visited(26,false);
        for(int i=0;i<s.length();i++)
        {
            
            fre[s[i]-'a']--;
            
            if(visited[s[i]-'a']==false){
                 
            while(st.size()!=0 && fre[st.back()-'a']>0 && st.back()>s[i] >0)
            {
               
                
               // fre[s[i]-'a']--;
               visited[st.back()-'a']=false;
                    st.pop_back();
               
            }
             
             
                    
                st.push_back(s[i]);
                 visited[s[i]-'a']=true;
            }        
            
        }
        
         string ans="";
        
        for(char ch :st)
        {
           
           ans+=(ch);
        }
        
        return ans;
       
    }
//anthoer method
string removeDuplicateLetters(string s)
{

    string st = "";
    vector<bool> vis(26, false);
    vector<int> freq(26, 0);
    for (char ch : s)
        freq[ch - 'a']++;

    for (char ch : s)
    {
        freq[ch - 'a']--;
        if (vis[ch - 'a'])
            continue;

        while (st.length() != 0 && st.back() > ch && freq[st.back() - 'a'] > 0)
        {
            char rch = st.back();
            st.pop_back();
            vis[rch - 'a'] = false;
        }

        vis[ch - 'a'] = true;
        st.push_back(ch);
    }

    return st;
}    
//leetcode 155
class MinStack {
public:
    /** initialize your data structure here. */
            vector<vector<int>>*arr;
    //int a=INT_MAX;
   // int b=INT_MAX;
    MinStack() {
         arr=new vector<vector<int>>();

    }
    
    void push(int val) {
        
         if(arr->size()==0)
         {
             arr->push_back({val,val});
         }
    
       else{  
        arr->push_back({val,min(arr->back()[1],val)});
       }
      
    }
    
    void pop() {
     
      
        arr->pop_back();
    }
    
    int top() {
        
        
        return arr->back()[0];
    }
    
    int getMin() {
        
        return arr->back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */





int main()
{
    vector<int>a={3,2,-1,4,5,-3,-7,-6,-4,6,5};
    vector<int>ans=NSOL(a);
    
    print(ans);


}