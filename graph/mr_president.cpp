//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>par;

int find_par(int u)
{
	return par[u]==u?u:par[u]=find_par(par[u]);
}

int mr_president(int n,vector<vector<int>>edge,long k)
{
	for(int i=0;i<n;i++)
	{
		par.push_back(i);

	}


	vector<int>weights;
	long overallWeightSum = 0;

	  for(vector<int>&arr:edge)
	  {
              int p1=find_par(arr[0]);
			  int p2=find_par(arr[1]);

			   int w=arr[2];

			   if(p1!=p2)
			   {
				   par[p1]=p2;
                   weights.push_back(w);
				   overallWeightSum+=w;
				   n--;
			   }
	  }

	  if(n>1)return -1;//graph disconnected
      
	  if(overallWeightSum <= k) return 0;

	  int transform=0;

	  for(int j=weights.size()-1;j>=0;j--)
	  {
		  overallWeightSum = overallWeightSum - weights[j] + 1;
		transform++;

		if(overallWeightSum <= k) break;
	  }

	  return overallWeightSum <= k ? transform : -1;
}

int main()
{
	 ios_base::sync_with_stdio(false);
	long n,m,k;
	cin>>n>>m>>k;

	vector<vector<int>>edges;

	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;

		edges.push_back({u,v,w});
	}

	sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b)
	{
        return a[2]<b[2];
	});
 
  cout <<mr_president(n,edges,k)<<endl;
  return 0;

}