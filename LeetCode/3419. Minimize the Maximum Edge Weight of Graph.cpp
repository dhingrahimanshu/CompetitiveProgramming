class Solution {
public:

    int isPossible (int node, vector <pair<int,int>> adj[], vector<bool> & vis, int minWeight) {
        vis[node] = true;   

        int ans = 1;

        for (auto &it: adj[node]) {
            if (vis[it.first]) continue;
            if (it.second > minWeight) continue;

            ans += isPossible(it.first, adj, vis, minWeight);
        }
        return ans;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int lo = 1, hi = 1e9;
        int ans = 1e9;

        vector <pair<int,int>> adj[n];

        for (auto &it: edges) {
            adj[it[1]].push_back({it[0], it[2]});
        }

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<bool> vis(n, false);
            if (isPossible(0, adj, vis, mid) == n) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return (ans == 1e9?-1:ans);
    }
};
