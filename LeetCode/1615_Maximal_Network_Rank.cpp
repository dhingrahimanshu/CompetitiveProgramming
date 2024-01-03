class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        map<pair<int,int>,int> arr;
        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
          adj[it[1]].push_back(it[0]);
            arr[{it[0],it[1]}]++;
            arr[{it[1], it[0]}]++;
        }
        int ans =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
               ans = max(ans , (int)adj[i].size() + (int)adj[j].size() - arr[{i,j}]);
            }
        }
        
        
       return ans;
    }
};
