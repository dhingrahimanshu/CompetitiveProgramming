class Solution {
  public:
    vector<int> ans, vis;
    
    void dfs(int node , int par , vector<int> adj[]){
        ans.push_back(node);
        vis[node]=1;
        for(auto it : adj[node]){
            if(vis[it])continue;
            dfs(it , node , adj);
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vis.resize(V , false);
        dfs(0 , -1 , adj);
        return ans;
    }
};
