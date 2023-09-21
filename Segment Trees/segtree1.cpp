class segtree{
public:
	int size;
	vector<ll> sums;
	void init(int n){
		size = 1;
		while(size<n) size*=2;
		sums.assign(2*size , 0ll);
	}

	void set(int i , int v , int x  ,int lx , int rx){
		if(rx-lx ==1){
			sums[x] =v;
			return;
		}
		int m = (lx + rx)/2;
		if(i<m){
			set(i , v, 2*x +1 , lx , m);
		}else{
			set(i , v, 2*x +2 , m  , rx);
		}
		sums[x] = sums[2*x +1] + sums[2*x +2];
	}

	void set(int i , int v){
		set(i , v, 0 , 0 , size);
	}

	long long int sum(int l , int r , int x , int lx, int rx){
		if(r<=lx || l>=rx) return 0;
		if(lx>=l && rx<=r) return sums[x];

		int m = (lx + rx)/2;
		ll s1 = sum(l ,r , 2*x +1 , lx , m);
		ll s2 = sum(l , r , 2*x +2 , m , rx);

		return s1 +s2;
	}


	long long int sum(int l , int r){
		return sum(l , r , 0 , 0 , size);
	}

};

void solve() {
	int n,m; cin>>n>>m;
	segtree ob;
	ob.init(n);
	for(int i =0 ;i<n;i++){
		int v; cin>>v;
		ob.set(i , v);
	}
	while(m--){
		int x; cin>>x;
		if(x==1){
			int i,v; cin>>i>>v;
			ob.set(i , v);
		}else{
			int l , r; cin>>l>>r;
			cout << ob.sum(l , r)<<'\n';
		}
	}
}
