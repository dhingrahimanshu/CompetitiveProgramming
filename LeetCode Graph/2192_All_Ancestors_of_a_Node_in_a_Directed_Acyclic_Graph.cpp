class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n);
        vector<int> indegree(n ,0);
        vector<int> adj[n];
        queue <int> pending;
        for(int i=0 ;i<(int)edges.size();i++){
            indegree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i =0 ;i<n;i++){
            if(indegree[i]==0){
                pending.push(i);
            }
        }
        while((int)pending.size()){
            int node = pending.front(); pending.pop();
            for(auto &it : adj[node]){
                ans[it].insert(node);
                for(auto &it2 : ans[node]){
                    ans[it].insert(it2);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    pending.push(it);
                }
            }
        }

        vector<vector<int>> ans2(n);
        for(int i =0;i<n;i++){
            for(auto &it : ans[i]){
                ans2[i].push_back(it);
            }
        }
        return ans2;
    }
};
