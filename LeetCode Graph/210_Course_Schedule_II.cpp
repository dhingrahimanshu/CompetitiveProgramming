class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> ans;
        vector <int> adj[n];
        vector<int> indegree(n);
        for(auto & it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue <int> pending;
        for(int i =0 ;i<n;i++){
            if(indegree[i]==0){
                pending.push(i);
            }
        }
        while(pending.size()){
            int node = pending.front(); pending.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    pending.push(it);
                }
            }
        }

        if(ans.size()!=n)return {};
        return ans;
    }
};
