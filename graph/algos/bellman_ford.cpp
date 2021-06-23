#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;


// Bellman Ford.
    // {{u,v,w}.....}
 void bellmanFord(int src, vector<vector<int>> edges, int N) {
        vector<int>dis(N,(int)1e9);
        

        dis[src] = 0;
        bool isNegativeCycle = false;

        for (int EdgeCount = 1; EdgeCount <= N; EdgeCount++) {
             vector<int>ndis(N);
            for (int i = 0; i < N; i++)
                ndis[i] = dis[i];

            for (vector<int> e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dis[u] != (int) 1e9 && dis[u] + w < ndis[v]) {
                    if (EdgeCount == N) {
                        isNegativeCycle = true;
                        break;
                    }

                    ndis[v] = dis[u] + w;
                }
            }

            dis = ndis;
        }

 }
