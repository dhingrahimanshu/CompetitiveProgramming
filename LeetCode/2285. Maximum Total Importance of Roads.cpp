class Solution {
public:

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(auto & it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans = 0;
        vector<long long> temp;
        for(int i=0;i<n;i++){
            temp.push_back(adj[i].size());
        }
        sort(temp.begin(),temp.end());
      
        for(int i=n;i>=1;i--){
            ans += (i*1ll*temp[i-1]);
        }
        return ans;
    }
};
