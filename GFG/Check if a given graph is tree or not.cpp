class Solution {
  public:
    int count =0;
    bool dfs(int node ,int par , vector<int> & vis , vector<int> adj[]){
        count++;
        vis[node]=1;
        for(auto it : adj[node]){
            if(it== par)continue;
            if(vis[it])return 0;
            if(dfs(it , node , vis , adj)==0)return 0;
        }
        return 1;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        vector<int> vis(n ,0);
        vector<int> g[n];
        for(auto & it : adj){
            if(it[0] == it[1])return 0;
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        int ans = (dfs(0 ,-1 , vis, g))&(count==n);
        return ans;
    }
};
