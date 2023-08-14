class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1 , INT_MAX);

        vector<pair<int,int>> adj[n+1];
        for(auto &it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        queue<int> pending;
        dis[k]=0;
        dis[0]=0;
        pending.push(k);
        while(pending.size()){
            int f = pending.front(); pending.pop();
            for(auto it : adj[f]){
                int x = dis[f] + it.second;
                if(dis[it.first]<=x)continue;
                dis[it.first]=x;
                pending.push(it.first);
            }
        }


        int ans =0;
        for(auto it : dis){
            if(it==INT_MAX)return -1;
            ans = max(ans , it);
        }
        return ans;
    }
};
