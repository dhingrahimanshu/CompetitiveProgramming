class Solution{
	public:
	void dfs(int node , vector<vector<int>> & adj , vector<int> & vis , vector<int> & order){
	    if(vis[node])return;
	    vis[node]=1;
	    for(auto &it : adj[node]){
	        dfs(it , adj , vis , order);
	    }
	    order.push_back(node);
	}
	void dfs2(int node , vector<vector<int>> & adj , vector<int> & vis){
	    if(vis[node])return;
	    vis[node]=1;
	    for(auto & it : adj[node]){
	        dfs2(it , adj , vis);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<vector<int>> adj2(V);
        for(int i=0 ;i<V;i++){
            for(auto & it2 : adj[i]){
                adj2[it2].push_back(i);
            }
        }
        vector<int> order;
        vector<int> vis(V ,0);
        for(int i =0 ;i<V;i++){
            if(vis[i])continue;
            dfs(i , adj , vis , order);
        }
        reverse(order.begin() , order.end());
        
        fill(vis.begin() , vis.end() ,0);
        // for(auto it :vis){
        //     cout << it << ' ';
        // }cout <<endl;
        int ans =0;
        for(int i =0 ;i<V;i++){
            if(vis[order[i]])continue;
            // cout << 1 <<endl;
            dfs2(order[i] , adj2 , vis);
            ans++;
        }
        
        return ans;
        
    }
};
