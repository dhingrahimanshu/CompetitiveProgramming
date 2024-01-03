class Solution {
public:

    bool dfs(int node, int root, vector<int> adj[] , vector<int> & vis){

        vis[node]=true;
        bool flag = true;
        for(auto &it : adj[node]){
            if(it==root)return false;
            if(vis[it])continue;
            flag&= dfs(it  , root, adj , vis);
        }
        return flag;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        
        }
        bool flag = true;
        for(int i =0;i<numCourses;i++){
            vector<int> vis(numCourses , false);
            flag&=dfs(i  , i , adj ,vis);
        }

        return flag;
    }
};
