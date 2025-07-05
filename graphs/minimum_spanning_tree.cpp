#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // Prims algorithm //
        // int sum=0;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        // vector<int> vis(V,0);
        // pq.push({0,0});
        // while(!pq.empty()){
        //     auto it=pq.top();
        //     pq.pop();
        //     int node=it.second;
        //     int wt=it.first;

        //     if(vis[node]==1) continue;
        //     vis[node]=1;
        //     sum+=wt;

        //     for(auto it:adj[node]){
        //         int adjNode=it[0];
        //         int nodewt=it[1];
        //         if(!vis[adjNode]){
        //             pq.push({nodewt,adjNode});
        //         }

        //     }
        // }
        // return sum;

        // Kruskals algorithm //
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; ++i)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                if (i < adjNode) // avoid duplicate edges
                    edges.push_back({wt, {i, adjNode}});
            }
        }

        DisjointSet ds(V);
        int mstWt = 0;
        sort(edges.begin(), edges.end());
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};
