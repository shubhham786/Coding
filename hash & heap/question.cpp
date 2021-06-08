#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

//leetcode 215
int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq; // min heap
        
        
        
        for(int i:nums)
        {
            pq.push(i);
            
            if(pq.size()>k)pq.pop();
        }
        
        
        return pq.top();
    } 

int findKthsmallest(vector<int>& nums, int k) {
        
        priority_queue<int>pq; // max heap
        
        
        
        for(int i:nums)
        {
            pq.push(i);
            
            if(pq.size()>k)pq.pop();
        }
        
        
        return pq.top();
    }

//leetcode 215
int findKthLargest(vector<int>& nums, int k)
{
    int li=nums.size()-1;

    for(int i=li;i>=0;i--)
    {
        dowhepify(nums,i,li);
    }

    while(k-->1)
    {
        swap(nums[li--],nums[0]);

        dowhepify(nums,0,li);
    }

    return nums[0];

}
    
  void dowhepify(vector<int>&arr,int pi,int li)
  {
      int maxi=pi;
       int lci=2*pi+1;
       int rci=2*pi+2;

      if(lci<=li && arr[lci]>arr[maxi])
      {
          maxi=lci;
      }

       if(rci<=li && arr[rci]>arr[maxi])
      {
          maxi=rci;
      }

      if(maxi!=pi)
      {
          swap(arr[maxi],arr[pi]);
          dowhepify(arr,maxi,li);
      }


  }      

  //leetcode 703
  class KthLargest {
public:
    
    
  
    priority_queue<int,vector<int>,greater<int>>pq;
    int z;
    KthLargest(int k, vector<int>& nums) {
        
        z=k;
        
        
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)pq.pop();
            
        }
        
    }

    
    
    int add(int val) {
    
           pq.push(val);
        
           if(pq.size()>z)pq.pop();
        
        return pq.top();
        
    }
};




/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//leetcode 347
vector<int>topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>map;
        
        for(int &i:nums)
        {
            map[i]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        
        for(auto &i:map)
        {
            pq.push(make_pair(i.second,i.first));
        }
        vector<int>ans;
        
           while(k-->0)
           {
               ans.push_back(pq.top().second);
               
               pq.pop();
               
           }
        
        
        return ans;
        
    }
    vector<int>topKFrequent(vector<int>& nums, int k){

        unordered_map<int,int>map;
        
        for(int &i:nums)
        {
            map[i]++;
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
      vector<int>ans;
    for(auto &i:map)
    {
    
        int ist=i.first;
        int second=i.second;
        pq.push({second,ist});

        if(pq.size()>k)pq.pop();
           
            }

        while(pq.size()!=0)//k-->0
        {
            vector<int>a=pq.top();
            ans.push_back(a[1]);
            pq.pop();
        }

        return ans;
    }

    //lletcode 973
      class comp
    {
        public:
             bool operator()(const vector<int>&a,const vector<int>&b)const{

             
             return (a[0]*a[0]+a[1]*a[1]) < (b[0]*b[0]+b[1]*b[1]);
         }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        int n=points.size();
        cout<<n<<endl;
        vector<vector<int>>ans;
        cout<<n-k<<endl;
        for(auto & i:points)
        {
            pq.push(i);
            
            cout<<pq.size()<<endl;
           if(pq.size()>(k))pq.pop();
                
        }
           
       // cout<<"x"<<pq.size()<<endl;
        while(k-->=1)
       {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        /*while(pq.size()!=0)
        {
            vector<int>ans1=pq.top();
            
            cout<<ans1[0]<<" "<<ans1[1]<<endl;
            pq.pop();
        }*/
        
        return ans;
        
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    //{d,x,y}
    priority_queue<vector<int>> pq; // maxPQ

    for (vector<int> &p : points)
    {
        int x = p[0];
        int y = p[1];
        pq.push({x * x + y * y, x, y});
        if (pq.size() > k)
            pq.pop();
    }

    vector<vector<int>> ans;
    while (pq.size() != 0)
    {
        vector<int> p = pq.top();
        pq.pop();
        int x = p[1];
        int y = p[2];

        ans.push_back({x, y});
    }

    return ans;
}
//leetcode 378
int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int l=n*m -1;
       // cout<<l<<endl;
        if(l==0)
           return matrix[0][0];
        
        
        priority_queue<int>pq;
           while(l>=0)
           {
               int row=l/m;
               int col=l%m;
               cout<<row<<" "<<col<<endl;
              //cout<<l<<endl;
               pq.push(matrix[row][col]);
               
               if(pq.size()>k)pq.pop();
               l--;
           }
        
        
        return pq.top();
        
    }

     int kthSmallest(vector<vector<int>>& matrix, int k){

        int n=matrix.size();
        int m=matrix[0].size();
        
        //{val,x,y}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({matrix[i][0],i,0});
        }
        
        int ans=0;
        while(k-->0)
        {
            vector<int>a=pq.top();
            pq.pop();
            int val=a[0];
            int x=a[1];
            int y=a[2];
            ans=val;
            y++;
            
            if(y<m)
            {
                pq.push({matrix[x][y],x,y});
            }
            
        }
        
        return ans;
        
        
        
    }   
 //leetcode 407 (good question)
     int trapRainWater(vector<vector<int>>& height) {
        
        int n=height.size();
        int m=height[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        //{height[i][j],i,j}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(i==0 || j==0 || i==n-1 || j==m-1)
                    {
                        vis[i][j]=true;
                        pq.push({height[i][j],i,j});
                    }
                }
            }
        
          vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
           int min_height=0;
           int water=0;
           while(pq.size()!=0)
           {
               vector<int>a=pq.top();
               pq.pop();
               
               min_height=max(a[0],min_height);
               water+=min_height-a[0];
               
               for(int i=0;i<dir.size();i++)
               {
                   int r=a[1]+dir[i][0];
                   int c=a[2]+dir[i][1];
                   
                   if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==false)
                   {
                       vis[r][c]=true;
                       
                       pq.push({height[r][c],r,c});
                   }
               }
               
           }
        
        return water;
    }
     int trapRainWater(vector<vector<int>>& height) {
        
        int n=height.size();
        int m=height[0].size();
        
       // vector<vector<bool>>vis(n,vector<bool>(m,false));
        //{height[i][j],i,j}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(i==0 || j==0 || i==n-1 || j==m-1)
                    {
                        //vis[i][j]=true;
                        pq.push({height[i][j],i,j});
                        height[i][j]=-1;
                    }
                }
            }
        
          vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
           int min_height=0;
           int water=0;
           while(pq.size()!=0)
           {
               vector<int>a=pq.top();
               pq.pop();
               
               min_height=max(a[0],min_height);
               water+=min_height-a[0];
               
               for(int i=0;i<dir.size();i++)
               {
                   int r=a[1]+dir[i][0];
                   int c=a[2]+dir[i][1];
                   
                   if(r>=0 && c>=0 && r<n && c<m && height[r][c]!=-1)
                   {
                       //vis[r][c]=true;
                       
                       pq.push({height[r][c],r,c});
                       height[r][c]=-1;
                   }
               }
               
           }
        
        return water;
    }   
    //leetcode 778
     int swimInWater(vector<vector<int>>& grid) {
        
        int n=grid.size();
        //int m=n;
        
        
        //{grid[i][j],i,j}
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        
        pq.push({grid[0][0],0,0});
        
        grid[0][0]=-1;
         int time=0;
         while(pq.size()!=0)
         {
          
             vector<int>a=pq.top();
             pq.pop();
               int height=a[0];
                int i=a[1];
             int j=a[2];
              cout<<i<<" "<<j<<" "<<time<<endl;
             //
             time+=max(0,height-time);
            cout<<" "<<time<<endl;
             if(i==n-1 && j==n-1)break;
             
              for(int d=0;d<4;d++)
              {
                 int x=i+dir[d][0];
                  int y=j+dir[d][1];
                  
                  if(x>=0 && y>=0 && x<n && y<n && grid[x][y]!=-1 )
                  {
                      pq.push({grid[x][y],x,y});
                      grid[x][y]=-1;
                  }
              }
             
             
         }
        
        return time;
        
    }
 //leetcode 632
 vector<int> smallestRange(vector<vector<int>>& arr) {
         int k=arr.size();
      //  int n=arr[0].size();  
        int max_val=-(int)1e9;
      int range=(int)1e9;
      //{val,x,y}
      
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
     // int max_val
     
     for(int i=0;i<k;i++)
     {
         max_val=max(max_val,arr[i][0]);
         pq.push({arr[i][0],i,0});
     }
     
     int si=-(int)1e9;
     int ei=(int)1e9;
     
      while(pq.size()==k)
      {
          vector<int>a=pq.top();
          pq.pop();
          int x=a[1];
          int y=a[2];
          int val=a[0];
          cout<<arr[x][y]<<" ";
           y++;
          
          
         
            
            if(max_val-val<range)
            {
                range=max_val-val;
                si=val;
                ei=max_val;
            }
          
           if(y<arr[x].size())
            {
                max_val=max(max_val,arr[x][y]);
                pq.push({arr[x][y],x,y});
            }
             
            
      }
      
      
      return {si,ei}; 
    }

    //leetcode 23
    //merge k sorted linked list
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
       class comp{
        
        public:
           
           bool operator()(const ListNode* a,const ListNode* b )const{
               
               return a->val >b->val;
           }
               
    };
    
    
 ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        ListNode* head=new ListNode(-1);
        
        ListNode* prev=head;
        
        priority_queue<ListNode *,vector<ListNode*>,comp>pq;
        
               for(int i=0;i<lists.size();i++)
               {
                   if(lists[i]!=nullptr)pq.push(lists[i]);
               }
     
     
         while(pq.size()!=0)
         {
               ListNode* ptr=pq.top();
               pq.pop();
               prev->next=ptr;
               prev=prev->next;
              if(ptr->next!=nullptr)pq.push(ptr->next);
         }
     
     
     return head->next;
    }   

    //leetcode 502
     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        priority_queue<vector<int>>pq1;
        
       
        for(int i=0;i<capital.size();i++)
        {
            pq.push({capital[i],profits[i]});
        }
        
        while(k-->0)
        {
            while(pq.size()!=0 && pq.top()[0]<=w)
            {
                pq1.push({pq.top()[1],pq.top()[0]});
                pq.pop();
            }
            
            if(pq1.size()>0)
            {
               vector<int>a=pq1.top();
                w+=a[0];
                pq1.pop();
                
            }
        }
        
        return w;
        
    }