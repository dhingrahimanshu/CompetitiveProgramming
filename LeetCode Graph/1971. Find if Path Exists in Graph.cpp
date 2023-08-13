class Solution {
public:

    bool dfs(int node , int target , vector<int> adj[] , vector<int> & vis){
        if(node==target){
            return 1;
        }
        vis[node]=1;
        bool flag = false;
        for(auto &it : adj[node]){
            if(vis[it])continue;
            flag|=dfs(it , target , adj , vis);
        }
        return flag;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n , 0);
        for(auto & it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(source , destination , adj , vis);
    }
};
