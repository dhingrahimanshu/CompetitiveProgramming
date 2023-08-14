void solve() {
	int n ,m; cin>>n>>m;
	vector<pair<int,int>> adj[n];
	for(int i =0 ;i<m;i++){
		int u , v; cin>>u>>v; u--; v--;
		adj[u].push_back({v , 0});
		adj[v].push_back({u , 1});
	}
	vector<int> lvl(n , INT_MAX);
	lvl[0]=0;
	deque <int> pending;
	pending.push_back(0);

	while(pending.size()){
		int f = pending.front(); pending.pop_front();

		for(auto it : adj[f]){
			int x = lvl[f] + it.second;
			if(x<lvl[it.first]){
				if(it.second==0){
					pending.push_front(it.first);
				}else{
					pending.push_back(it.first);
				}
				lvl[it.first]=x;
			}
		}
	}
	if(lvl[n-1]==INT_MAX){
		lvl[n-1]=-1;
	}
	cout << lvl[n-1] <<endl;
}
