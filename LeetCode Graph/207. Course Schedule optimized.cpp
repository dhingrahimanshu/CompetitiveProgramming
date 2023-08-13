class Solution {
public:

    bool dfs(int node, vector<int> adj[] , vector<int>&color){
        color[node] = 1;
        bool flag = false;
        for(auto it : adj[node]){
            if(color[it]==1)return true;
            if(color[it]==2)continue;
            flag|=dfs(it , adj , color);
        }

        color[node]=2;
        return flag;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        
        }
        vector<int> color(numCourses , 0);
        for(int i =0;i<numCourses;i++){
            if(color[i]>0)continue;
            if(dfs(i , adj ,color))return false; 
        }

        return true;
    }
};
