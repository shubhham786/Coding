#include <iostream>
#include <vector>
#include<algorithm>
#include<list>
using namespace std;

void print1D(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout <<ele<<" ";
    }
    cout << endl;
}

void print2D(vector<vector<int>> &arr)
{
    for (vector<int> &ar : arr)
    {
        print1D(ar);
    }
}
//fibonaaci 
int fib_memo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return dp[n] = n;
    }

    if (dp[n] != -1)
        return dp[n];

    int ans = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
    return dp[n] = ans;
}

int fib_DP(int N, vector<int> &dp)
{

    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = n;
            continue;
        }

        int ans = dp[n - 1] + dp[n - 2]; // fib_01(n - 1, dp) + fib_01(n - 2, dp);

        dp[n] = ans;
    }

    return dp[N];
}

int fib_twoPointer(int N)
{
    int a = 0, b = 1;
    for (int n = 0; n < N; n++)
    {
        // System.out.print(a + " ");

        int sum = a + b;
        a = b;
        b = sum;
    }

    return a;
}

void fibo()
{
    int n = 8;
    vector<int> dp(n + 1, -1);

    cout << (fib_memo(n, dp)) << endl;
    cout << (fib_DP(n, dp)) << endl;
    cout << (fib_twoPointer(n)) << endl;

    print1D(dp);
}
//maze path memo

int maze_path_memo(int r, int c,int n,int m,vector<vector<int>>& dir,vector<vector<int>>&dp)
{
    if(r==n-1 && c==m-1)
    {
        return dp[r][c]=1;
    }

    if(dp[r][c]!=0)
        return dp[r][c];
    
    int ans=0;
    for(int i=0;i<dir.size();i++)
    {
       int r1=r+dir[i][0];
       int c1=c+dir[i][1];

        if(r1<n && c1<m )
            ans += maze_path_memo(r1,c1,n,m,dir,dp);
    }
  return dp[r][c]=ans;
}
//maze path dp
int maze_path_dp(int r, int c,int n,int m,vector<vector<int>>& dir,vector<vector<int>>&dp)
{
    for(int j=n-1;j>=r;j--)
    {
        for(int i=m-1;i>=c;i--)
        {
           if(j==n-1 && i==m-1)
           {
               dp[j][i]=1;
               continue;
           }

     
    
             int ans=0;
              for(int l=0;l<dir.size();l++)
             {
               int r1=j+dir[l][0];
                int c1=i+dir[l][1];

                if(r1<n && c1<m )
                    ans += dp[r1][c1];//maze_path_memo(r1,c1,n,m,dir,dp);
                 }
               dp[j][i]=ans; 
        }
    }
    return dp[0][0];
}
// maze path with jump
int maze_path_memo_jump(int r, int c,int n,int m,vector<vector<int>>& dir,vector<vector<int>>&dp)
{
    if(r==n-1 && c==m-1)
    {
        return dp[r][c]=1;
    }

    if(dp[r][c]!=0)
        return dp[r][c];
    
    int ans=0;
    for(int i=0;i<dir.size();i++)
    {
       for(int jump=0;jump<=max(n,m);jump++){ 
             int r1=jump+r+dir[i][0];
             int c1=jump+c+dir[i][1];

           if(r1<n && c1<m )
              ans += maze_path_memo_jump(r1,c1,n,m,dir,dp);
       }     
    }
  return dp[r][c]=ans;
}
//maze path with jump dp
int maze_path_dp_jump(int r, int c,int n,int m,vector<vector<int>>& dir,vector<vector<int>>&dp)
{
    for(int j=n-1;j>=r;j--)
    {
        for(int i=m-1;i>=c;i--)
        {
           if(j==n-1 && i==m-1)
           {
               dp[j][i]=1;
               continue;
           }

     
    
             int ans=0;
              for(int l=0;l<dir.size();l++)
             {
               
               

                for(int jump=0;jump<=max(n,m);jump++){ 
                    int r1=jump+j+dir[l][0];
                    int c1=jump+i+dir[l][1];

               if(r1<n && c1<m )
                 ans += dp[r1][c1];//maze_path_memo_jump(r1,c1,n,m,dir,dp);
            }     
        }
        dp[j][i]=ans;
    }
    
    }
    return dp[0][0];
}
void maze()
{
    int n=3;
    int m=3;
 vector<vector<int>>dir={{0,1},{1,0},{1,1}};
 vector<vector<int>>dp(n,vector<int>(m));
    cout<<maze_path_memo_jump(0,0,3,3,dir,dp)<<endl;
    print2D(dp);
    vector<vector<int>>dp1(n,vector<int>(m));
     cout<<maze_path_dp_jump(0,0,3,3,dir,dp1)<<endl;
    print2D(dp1);
}


//die throw
int die_throw(int i,int tar,vector<int>&dp)
{
    if(i==tar)
      return dp[i]=1;

      if(dp[i]!=-1)
        return dp[i];

   int ans=0;
        for(int j=1;j<=6;j++)
        {
            if(i+j<=tar) 
              ans+=die_throw(i+j,tar,dp);
        }

         return dp[i]=ans;
}
  int die_DP(int SP, int ep, vector<int>&dp) {
        for (int sp = ep; sp >= SP; sp--) {
            if (sp == ep) {
                dp[sp] = 1;
                continue;
            }

            int count = 0;
            for (int dice = 1; dice <= 6 && sp + dice <= ep; dice++) {
                count += dp[sp + dice];// boardPath_memo(sp + dice, ep, dp);
            }

            dp[sp] = count;
        }

        return dp[SP];
    }

int die_opti(int sp, int ep) {
        list<int> list1;

        for (sp = ep; sp >= 1; sp--) {
            if (sp >= ep - 1)
                list1.push_front(1);
            else {
                if (list1.size() <= 6)
                    list1.push_front(list1.front() * 2);
                else
                    {
                        list1.push_front(list1.front() * 2 - list1.back());
                      list1.pop_back();
                    }
            }
        }

        return list1.front();

}
void die()
{
   // vector<int>sample={1,2,3,4,5,6,7,8,9,10};

  int tar=10;
   vector<int>dp(tar+1,-1);

     int ans=die_opti(1,10);

   // print1D(dp);
      cout<<ans;


}

int main()
{
  //fibo();
  // maze();
   die();
    return 0;
}