#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<string>

using namespace std;

//leetcode 349
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        
        unordered_set<int>map;
        
        for(int &i:nums1)
        {
            map.insert(i);
        }
        
    vector<int>ans;
        
        for(int &j :nums2)
        {
            if(map.find(j)!=map.end())
            {
                //map[j]=false;
                map.erase(j);
                ans.push_back(j);
            }
                
        }
        
        
        return ans;
    }

    //leetcode 350
     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
            unordered_map<int,int>map;
        
        for(int &i:nums1)
        {
            map[i]++;
        }
        
    vector<int>ans;
        
        for(int &j :nums2)
        {
            if(map[j]-->0)
            {
                ans.push_back(j);
            }
                
        }
        
        
        return ans;
    }

    //128
     int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool>map;
        
        for(int i:nums)
        {
            map[i]=true;
        }
            
        
        int maxlen=0;
        for(auto &i:map)
        {
            
            
            
            if(i.second==true)
            {
                int len=1;
                
                int k=i.first;
                while(map.find(k+1)!=map.end() && map[k+1]!=false)
                {
                    map[k+1]=false;
                    len++;
                    k++;
                
                }
                  
                k=i.first;
                
                 while(map.find(k-1)!=map.end() && map[k-1]!=false)
                {
                    map[k-1]=false;
                    len++;
                    k--;
                
                }
                
                maxlen=max(len,maxlen);
                
                map[i.first]=false;
            }
        }
        
        
        return maxlen;
        
    }
    //leetcode 380
    class RandomizedSet {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int,int>map;
     vector<int>store;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(map.find(val)!=map.end())
            return false;
        else{
            
            map[val]=store.size();
            store.push_back(val);
           // n++;
            return true;
        
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
    
        if(map.find(val)==map.end())
            return false;
        else{
            if(store.size()==1)
            {
                map.erase(val);
                store.pop_back();
            }
            else
            {
                map[store[store.size()-1]]=map[val];
               swap(store[map[val]],store[store.size()-1]);
                
            map.erase(val);
             store.pop_back();
            }   
            return true;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int n=rand()%store.size();
        
        return  store[n];
    }
};
class RandomizedSet
{
public:
    unordered_map<int, int> map;
    vector<int> list;

    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (map.find(val) != map.end())
            return false;

        list.push_back(val);
        map[val] = list.size() - 1;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (map.find(val) == map.end())
            return false;

        int idx = map[val];
        int lidx = list.size() - 1;

        list[idx] = list[lidx];
        map[list[lidx]] = idx;

        list.pop_back();
        map.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int idx = rand() % list.size();
        return list[idx];
    }
};

//leetcode 895
class FreqStack {
public:
    
    unordered_map<int,int>map;
    vector<vector<int>>sta;
    int max_freq;
    FreqStack() {
        max_freq=0;
        sta.push_back({});
    }
    
    void push(int val) {
        
        int k= ++map[val];
        
        max_freq=max(max_freq,k);
        
        if(max_freq==sta.size())
            sta.push_back({});
        
        
        sta[k].push_back(val);
    }
    
    int pop() {
        
        int val=sta[max_freq].back();
        sta[max_freq].pop_back();
        
        if(sta[max_freq].size()==0)
        {
            sta.pop_back();
            max_freq--;
        }
        
        map[val]--;
        
        if(map[val]==0)
        {
            map.erase(val);
        }
        
        return val;
    }
};
class FreqStack {
public:
    class pair{
      
        public:
           int val=0;
        int freq=0;
        int idx=0;
        
        pair(int val,int freq,int idx)
        {
            this->val=val;
            this->freq=freq;
            this->idx=idx;
        }
    };
    
    
    class comp{
        
        public:
          
        bool operator()(const pair &a,const pair &b)const{
            
            if(a.freq==b.freq)
            {
                return b.idx>a.idx;
            }
            
            return b.freq>a.freq;
        }
    };
    unordered_map<int,int>map;
    
    priority_queue<pair,vector<pair>,comp>pq;
    int idx;
    FreqStack() {
     
        idx=0;
    }
    
    void push(int val) {//o(logn)
        map[val]++;
        
        pq.push(pair(val,map[val],idx++));
    }
    
    int pop() {//o(logn)
        pair l=pq.top();
        pq.pop();
        map[l.val]--;
         if(map[l.val]==0)
         {
             map.erase(l.val);
         }
        
        return l.val;
    } 
    
};
//leetcode 49
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>map;
        
        for(string &s:strs)
        {
           string str=s;
            
            sort(str.begin(),str.end());
            
            map[str].push_back(s);
        }
        
        for(auto &i:map)
        {
            ans.push_back(i.second);
        }
        
        return ans;
        
    }
    //leetcode 166
     string fractionToDecimal(int A, int B) {
        
        string ans="";
        long num=(long)A;
        long den=(long)B;
        bool neg=false;
        if(num<0){
            neg=true;
            num=abs(num);
            cout<<num;
        }
        if(den<0){
            if(neg==true)
                neg=false;
            else
                neg=true;
            
            den=abs(den);
            
           // cout<<sizeof(int);
        }
        if(neg==true)
            ans+="-";
        
        if(num==0)
            return "0";
        
        long num1=num/den;
        
        ans+=to_string(num1);
        
        unordered_map<int,int>map;
        
        long num2=num%den;
        
        if(num2==0)
          return ans;
        
        ans+=".";
        
        bool isrec=true;
         int val;
        while(num2>0 )
        {
            //while(num2<=den){
              num2=num2*10;
                
          
            if(map.find(num2)==map.end())
            {
               // jab tak ek authentic pattern nahi milta hai tab tak map me insert karte jaoo
                map[num2]=ans.size();
            }
            else
            {
              // mil gaya authentic pattern tu break kar do loop ko
                ans.insert(map[num2],"(");
                
                ans+=")";
                break;
                
                
            }
            
            // ans me add karte jaoo
            
            ans+=to_string(num2/den);
            num2=num2%den;
            
        }
        
        return ans;
     
        
    }

    //leetcode 149
    //max points on line
    //good question
    //considering unique elements
     int maxPoints(vector<vector<int>>& points) {
        

       // map[-1]=0;
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            int x=0;
                    unordered_map<double,int>map;
            for(int j=i+1;j<points.size();j++)
            {
                 double m;
                if((points[j][0]-points[i][0])!=0)
                   m=(double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                else
                    m=(int)1e9;
               
                if(map.find(m)==map.end())map[m]=1;
                
                else
                    map[m]++;
                
               // cout<<j<<" "<<i<<" "<<m<<" "<<map[m]<<endl;
                 
                x=max(x,map[m]);
            }
            ans=max(ans,x+1);
        }
        
       return ans;
       
     
    }
    