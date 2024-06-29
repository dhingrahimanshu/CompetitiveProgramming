class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // tropological sort something
        // start with element with only indegree = 0;
        vector<set<int>> ans(n);

        vector<int> adj[n];
        vector<int> indegree(n);
        for(auto & it : edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> pending;
        for(int i =0 ;i<n;i++){
            if(!indegree[i]){
                pending.push(i);
            }
        }

        while((int)pending.size()){
            int node = pending.front(); pending.pop();
            for(auto & it : adj[node]){
                ans[it].insert(node);
                for(auto & it2 : ans[node]){
                    ans[it].insert(it2);
                }
                indegree[it]--;
                if(!indegree[it]){
                    pending.push(it);
                }
            }
        }


        vector<vector<int>> ans2(n);
        for(int i =0 ;i<n;i++){
            for(auto & it : ans[i]){
                ans2[i].push_back(it);
            }
        }
        return ans2;
    }
};
