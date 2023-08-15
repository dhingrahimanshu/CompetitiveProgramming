class dsu{
public:
	vector<int> size , mi , ma, par;
	dsu(int n){
		for(int i =0 ;i<=n;i++){
			size.push_back(1);
			par.push_back(i);
			mi.push_back(i);
			ma.push_back(i);
		}
	}
	int get(int a){
		if(a!=par[a]){
			par[a] = get(par[a]);
		}
		return par[a];
	}
	void union_set(int a , int b){
		a = get(a);
		b = get(b);
		if(size[a]>size[b]){
			swap(a,b);
		}
		if(par[a]==b || par[b]==a)return;
		par[a]=b;
		size[b]+=size[a];
		mi[b]=min(mi[b] , mi[a]);
		ma[b]=max(ma[b] , ma[a]);
	}
	int get2(int a){
		a = get(a);
		cout << mi[a] << ' ' << ma[a] <<" " << size[a] <<endl;
	}
};


void solve() {
	int n ,m; cin>>n>>m;

	dsu ob(n);
	for(int i =0 ;i<m;i++){
		string u; int a,b; cin>>u;
		if(u=="union"){
			cin>>a>>b;
			ob.union_set(a , b);
		}else{
			cin>>a;
			ob.get2(a);
		}

	}
}



