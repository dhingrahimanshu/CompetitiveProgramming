class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = (int)arr.size();
        
        queue<int> pending;
        pending.push(0);
        vector<int> dis(n , n);
        dis[0]=0;

        unordered_map <int,vector<int>> pos;
        for(int i =0 ;i<n;i++){
            pos[arr[i]].push_back(i);
        }
        unordered_map <int,bool> hash;

        while(pending.size()){
            int x  = pending.front(); pending.pop();
            
            if((x-1)>=0 && (dis[x-1]>(dis[x] +1))){
                dis[x-1] = dis[x]+1;
                pending.push(x-1);
            }
            if((x+1)<n && (dis[x+1]>(dis[x] +1))){
                dis[x+1] = dis[x]+1;
                pending.push(x+1);
            }
            if(hash[arr[x]])continue;
            for(auto & it : pos[arr[x]]){
                if(dis[it]> dis[x]+1){
                    dis[it] = dis[x]+1;
                    pending.push(it);
                }
            }
            hash[arr[x]]=1;
        }
        return dis[n-1];
    }
};
