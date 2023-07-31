class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        queue <int> pending;
        pending.push(0);
        vector <bool> vis(V , false);
        vis[0]=1;
        while(pending.size()){
            int x = pending.front(); pending.pop();
            ans.push_back(x);
            for(auto it : adj[x]){
                if(vis[it])continue;
                vis[it]=true;
                pending.push(it);
            }
        }
        return ans;
    }
};
