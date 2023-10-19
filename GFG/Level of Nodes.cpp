class Solution
{
	public:
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    int ans = 0;
	    if(X==0)return 0;
	    queue <int> pending;
	    pending.push(0);
	    
	    vector<bool> vis(V,0);
	    while(pending.size()){
	        ans++;
	        
	        int n = (int) pending.size();
	        for(int i =0 ;i<n;i++){
	            int cur = pending.front(); pending.pop();
	            for(auto it : adj[cur]){
    	            if(vis[it])continue;
    	            if(it==X){
    	                return ans;
    	            }
    	            vis[it]=1;
    	            pending.push(it);
    	        }
	        }
	        
	        
	    }
	    
	    
	    
	    return -1;
	}
};
