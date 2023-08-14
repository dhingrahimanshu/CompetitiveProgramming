class dsu{
public:
	vector<int> arr,size , par;

	dsu(int n){
		for(int i = 0;i<=n;i++){
			arr.push_back(i);
			par.push_back(i);
			size.push_back(1);
		}
		
	}
	int get(int a){
		if(a!=par[a]){
			par[a] = get(par[a]); 	 
		}
		return par[a];
	}
	bool get(int a , int b){
	
		
		a = get(a);
		
		b  = get(b);
		
		return a==b;
	}

	void union_set(int a, int b){
		a = get(a);
		b = get(b);
		if(size[a]>size[b]){
			swap(a,b);
		}
		par[a]=b;
		size[b]+=size[a];
	}

};


