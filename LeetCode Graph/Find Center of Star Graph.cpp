class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> adj[n+1];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i =1;i<=n;i++){
            if(adj[i].size()==n-1){
                return i;
            }
        }
        return -1;
    }
};
