class Solution {
public:
    
    int dfs(vector<pair<int,int>> adj[] , int root ,int par, vector<int> & green , vector<int> & red){
        int dis = 0;
        for(auto it : adj[root]){
            if(it.first==par)continue;
            // cout << it.first <<" ";
            // if(it.first==1){
            //     cout << "root of 1 : " << root <<" " << red[root] <<endl;
            // }
            if(it.second){
                red[it.first] = 1+ red[root];
                green[it.first] = green[root];
            }else{
                green[it.first] = 1+green[root];
                red[it.first] = red[root];
            }
            dis+= it.second +dfs(adj , it.first , root, green , red);
        }
        return dis;
    }
    
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        int m = (int)edges.size();
        vector<int> ans(n);
        vector<pair<int,int>> adj[n];
        for(int i =0 ;i<m;i++){
            int a= edges[i][0];
            int b = edges[i][1];
            adj[a].push_back({b , 0});
            adj[b].push_back({a , 1});
        }
        vector<int> green(n , 0),red(n , 0);
        
        int cost = dfs(adj , 0 , -1 , green , red);
        // cout <<endl;
        // cout << red[2] <<" " << green[2] <<endl;
        // cout << red[1] <<" " << green[1] <<endl;
        for(int i = 0;i<n;i++){
            ans[i] = cost - red[i]+green[i];
        }
        
        return ans;
    }
};
