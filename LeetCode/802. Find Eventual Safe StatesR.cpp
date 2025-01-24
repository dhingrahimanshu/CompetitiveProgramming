class Solution {
public:
    
    vector<int> ans;
    void dfs(int node ,int par, vector<vector<int>> & graph , vector<int> & vis , vector<int>&path){
        vis[node]=1;
        path.push_back(node);
        for(auto & it : graph[node]){
            if(vis[it]==1 || (vis[it]==2 && ans[it]==0)){
                for(auto & it : path){
                    ans[it]=0;
                }
                continue;
            }else if(vis[it]==2){
                continue;
            }else{
                dfs(it , node , graph , vis ,path );
            }
        }   
        path.pop_back();
        vis[node]=2;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        vector<int> vis(n , 0);
        ans.resize(n , 1);
        vector<int>path;
        for(int i =0 ;i<n;i++){
            if(vis[i])continue;
            dfs(i ,-1, graph , vis ,path);
                
        }
        vector<int> temp;
        for(int i =0 ;i<n;i++){
            if(ans[i])temp.push_back(i);
        }
        return temp;
    }
};
