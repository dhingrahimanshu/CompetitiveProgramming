class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int dis = n - 1;
        vector<int> ans;

        vector<int> adj[n];

        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        queue <int> pending;
        for (auto &it : queries) {
            adj[it[0]].push_back(it[1]);
            vector<int> dis(n, n);
            dis[0] = 0;
            pending.push(0);

            while (pending.size()) {
                int node = pending.front(); pending.pop();
                
                for (auto &it: adj[node]) {
                    if (dis[it] > 1 + dis[node]) {
                        pending.push(it);
                        dis[it] = 1 + dis[node];
                    }
                }
            }
            ans.push_back(dis[n-1]);
            
        }
        return ans;
    }
};
