class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = (int)arr.size();
        vector<bool> vis(n ,0);
        queue <int> pending;
        pending.push(start);
        while(pending.size()){
            int x = pending.front(); pending.pop();
            if(vis[x])continue;
            vis[x]=1;
            if(x + arr[x] <n){
                pending.push(x + arr[x]);
            }
            if(x - arr[x] >=0){
                pending.push(x - arr[x]);
            }
        }
        

        for(int i=0 ;i<n;i++){
            if(vis[i] && !arr[i])return true;
        }
        return false;
    }
};
