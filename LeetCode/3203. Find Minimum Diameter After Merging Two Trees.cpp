class Solution {
public:
    void dfs (int node, int par, vector <vector<int>> & adj, vector<int> &dis) {
        for (auto &it: adj[node]) {
            if (it == par) continue;
            dis[it] = 1 + dis[node];
            dfs(it, node, adj, dis);
        }
    }

    int getDiameter (int n, vector <vector<int>> & adj) {
        vector<int> dis(n);
        dis[0] = 0;
        dfs(0, -1, adj, dis);
        int node = 0, D = 0;

        for (int i = 0; i < n; i++) {
            if (dis[i] > D) {
                D = dis[i];
                node = i;
            }
        }
        dis = vector<int> (n, 0);
        dfs(node, -1, adj, dis);

        int diameter = 0;
        for (auto &it: dis) diameter = max(diameter, it);
        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector <vector<int>> adj(n);
        vector <vector<int>> adj2(m);
        
        for (int i = 0; i < n-1; i++) {
            adj[edges1[i][0]].push_back(edges1[i][1]);
            adj[edges1[i][1]].push_back(edges1[i][0]);
        }

        for (int i = 0; i < m-1; i++) {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }

        int diameter1 = getDiameter(n, adj);
        int diameter2 = getDiameter(m, adj2);

        // cout << diameter1 << ' ' << diameter2 << endl;
        
        return max({diameter1, diameter2, (int)(ceil(1.0*diameter1/(double)2) + ceil(1.0*diameter2/(double)2) + 1)});
    }
};
