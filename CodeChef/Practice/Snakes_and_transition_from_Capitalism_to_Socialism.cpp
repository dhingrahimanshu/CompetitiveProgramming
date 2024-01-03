void solve() {
	int n,m; cin>>n>>m;
	vector<vector<int>> grid;
	grid.resize(n , vector<int>(m));

	int ma = 0;
	for(int i =0 ;i<n;i++){
		for(int j =0 ;j<m;j++){
			cin>>grid[i][j];
			ma = max(ma , grid[i][j]);
		}
	}
	queue<pair<int,int>> pending;
	
	vector<vector<int>> lvl;
	lvl.resize(n , vector<int>(m , INT_MAX));
	for(int i =0 ;i<n;i++){
		for(int j =0 ;j<m;j++){
			if(grid[i][j]==ma){
				pending.push({i ,j});
				lvl[i][j]=0;
			}
		}
	}
	auto check=[](int x , int y, int n , int m){
		if(x<0 || y<0 || x>=n || y>=m)return false;
		return true;
	};
	int ans =0;

	while(pending.size()){
		pair<int,int> f = pending.front(); pending.pop();
		for(int i =-1;i<=1;i++){
			for(int j =-1;j<=1;j++){
				if(i==0 && j==0)continue;
				int x = f.first + i;
				int y = f.second +j;
				if(!check(x , y , n , m) || lvl[x][y]<=(lvl[f.first][f.second]+1))continue;
				lvl[x][y] = 1+ lvl[f.first][f.second];
				ans = max(ans, lvl[x][y]);
				pending.push({x , y});
			}
		}

	}
	cout << ans <<endl;



}
