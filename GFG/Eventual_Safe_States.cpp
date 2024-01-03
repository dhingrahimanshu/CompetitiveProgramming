class Solution {
  public:
    
    vector<int> vis;
    vector<int> terminal;
    
    bool dfs(int node , vector<int>adj []){
        if(vis[node]){
            return terminal[node];
        }
        if(terminal[node]){
            vis[node]=true;
            terminal[node] = true;
            return true;
        }
        
        
        vis[node] = true;
        bool flag =true;
        for(auto it : adj[node]){
            flag&= dfs(it , adj);
        }
        terminal[node]= flag;
        return flag;
        
    }
    
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        vis.resize(V , 0);
        terminal.resize(V , 0);
        for(int i=0 ;i<V;i++){
            terminal[i] =(int)adj[i].size()==0;
        }
        for(int i =0 ;i<V;i++){
            if(vis[i])continue;
            dfs(i , adj);
            
        }
        for(int i =0 ;i<V;i++){
            if(terminal[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
