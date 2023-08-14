#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices];
    vector<int> dis(vertices, INT_MAX);
    for(auto &it : vec){
        adj[it[0]].push_back({it[1] , it[2]});
        adj[it[1]].push_back({it[0] , it[2]});
    }
    dis[source]=0;
    priority_queue<int> pending;
    pending.push(source);
    while(pending.size()){
        int f = pending.top(); pending.pop();
        for(auto it : adj[f]){
            int x = it.second + dis[f];
            if(x>=dis[it.first])continue;
            dis[it.first] = x;
            pending.push(it.first);
        }
    }
    return dis;
}
