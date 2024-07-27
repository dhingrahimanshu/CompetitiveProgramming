class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long n = (int)source.size();
        long long edges = (int)cost.size();

        vector<pair<long long,long long>> adj[26];
        for(int i = 0;i<edges;i++){
            adj[original[i] - 'a'].push_back({changed[i] - 'a',cost[i]});
        }
        vector<vector<long long>> dis(26,vector<long long>(26,1e17));
        
        for(int i = 0;i<26;i++){
            dis[i][i] = 0;
            queue<long long> pq;
            pq.push(i);
            while(pq.size()){
                long long node = pq.front(); pq.pop();
                for(auto & it : adj[node]){
                    if(dis[i][it.first] > (dis[i][node] + it.second)){
                        dis[i][it.first] = (dis[i][node] + it.second);
                        pq.push(it.first);
                    }
                }
            }

        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            if(dis[source[i]-'a'][target[i]-'a'] == 1e17)return -1;
            ans += dis[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }   
};
