class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<int> pending;
        vector<int> dis(V , INT_MAX);
        pending.push(S);
        dis[S]=0;
        while(pending.size()){
            int f = pending.top(); pending.pop();
            for(auto it : adj[f]){
                int cur = it[0];
                int x = dis[f] + it[1];
                if(x>=dis[cur])continue;
                dis[cur]=x;
                pending.push(cur);
            }
        }
        return dis;
    }
};
