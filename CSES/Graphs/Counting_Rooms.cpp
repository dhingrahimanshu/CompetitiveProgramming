
vector<vector<int>> movements={{1 , 0} , {0 , 1} , {-1 , 0} , {0 ,-1}};

bool isvalid(int i , int j , int n , int m){
	if(i<0 || j<0 || i>=n || j>=m)return false;
	return true;
}

void dfs(vector<vector<char>> & grid , int i , int j , int n ,int m , vector<vector<bool>> & vis){
	vis[i][j]=true;
	for(auto & it : movements){
		int x = it[0] + i;
		int y = it[1]+j;
		if(!isvalid(x , y ,n , m ) || vis[x][y] || grid[x][y]=='#')continue;
		dfs(grid , x , y , n , m , vis);
	}

}


void solve() {
	int n ,m; cin>>n>>m;
	vector<vector<char>> grid;
	grid.resize(n , vector<char>(m));
	for(int i =0 ;i<n;i++){
		for(int j =0 ;j<m;j++){
			cin>>grid[i][j];
		}
	}
	int ans =0;
	vector<vector<bool>> vis;
	vis.resize(n , vector<bool>(m , 0));
	for(int i =0 ;i<n;i++){
		for(int j =0 ;j<m;j++){
			if(grid[i][j]=='#' || vis[i][j])continue;
			dfs(grid , i , j , n ,m,vis);
			ans++;
		}
	}
	cout << ans <<endl;

}



