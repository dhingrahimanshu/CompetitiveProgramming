//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<int> ans , indegree(n ,0);
        vector<int> adj[n];
        for(int i =0 ;i<m;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue <int> pending;
        for(int i=0 ;i<n;i++){
            if(indegree[i]==0)pending.push(i);
        }
        
        while(pending.size()){
            int node = pending.front(); pending.pop();
            ans.push_back(node);
            for(auto & it : adj[node]){
                if( (--indegree[it]) == 0){
                    pending.push(it);
                }
            }
        }
        if(ans.size() != n){
            ans.clear();
        }
        return ans;
    }
};
