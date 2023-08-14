void solve() {
	ll n,m; cin>>n>>m;
	vector<pair<ll,ll>> adj[n+1];
	for(int i =0 ;i<m;i++){
		ll u,v,w; cin>>u>>v>>w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	vector<ll> dis(n+1 , 1e18) , par(n+1 , 0);
	dis[1] =0;par[1]=-1;
	int a = 1;	

	priority_queue<pair<ll,ll>> pending;
	pending.push({ -0 , 1});

	while(pending.size()){
		pair<ll,ll> f = pending.top(); pending.pop();

		for(auto it : adj[f.second]){
			ll x = it.second + dis[f.second];
			if(x>=dis[it.first])continue;
			par[it.first] = f.second;
			dis[it.first] = x;
			pending.push({-x , it.first});
		}
	}

	vector<ll>ans;
	int d = n;
	while(d!=-1){
		if(d==0){
			cout << -1 <<endl;
			return;
		}
		ans.push_back(d);
		d = par[d];
	}

	reverse(all(ans));
	print(ans);

}



