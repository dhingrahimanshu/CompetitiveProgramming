class Solution {
public:
    int dp[10001];

    void sieve () {
        memset(dp, 0, sizeof dp);
        int n = 10000;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (dp[i]) continue;
            for (int j = 2 * i; j <= n; j += i) {
                dp[j] = 1;
            }
        }
    }

    vector <string> getChild (string s) {
        vector<string> ans;

        for (auto &it: s) {
            if (it < '9') {
                it++;
                ans.push_back(s);
                it--;
            }

            if (it > '0') {
                it--;
                ans.push_back(s);
                it++;
            }
        }

        return ans;
    }


    int minOperations(int n, int m) {
        sieve();
        if (!dp[n] || !dp[m]) return -1;
        vector <int> dis(10000, -1);

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[n] = n;
        pq.push({n, n});

        while (pq.size()) {
            pair <int,int> val = pq.top(); pq.pop();
            int node = val.second;
            int dist = val.first;

            for (auto &it: getChild(to_string(node))) {
                
                int child = stoi(it);
                // cout << node << ' ' << child << endl;

                if (!dp[child]) continue;
                // cout << node << ' ' << child << endl;
                if (dis[child] == -1 || (dist + child) < dis[child]) {
                    dis[child] = (dist + child);
                    pq.push({dis[child], child});
                }
            }
        }

        return dis[m];
    }
};
