#include <bits/stdc++.h>

using namespace std;




class segTree{
public:
	int size;
	vector<long long int> seg;
	segTree(int n){
		size = 1;
		while(size < n) size*=2;
		seg.resize(2*size , 0ll);
	}

	void build(vector<int> & arr , int node , int st , int en){
		if(st+1 == en){
			if(st < (int)arr.size()){
				seg[node] = arr[st];
			}
			return;
		}
		int mid = (st + en)/2;
		build(arr , 2*node +1 , st , mid);
		build(arr , 2*node +2 , mid , en);
		seg[node] = seg[2*node +1] +seg[2*node +2];
	}

	void build(vector<int> & arr){
		build(arr , 0  , 0 , size);
	}

	void set(int node ,int ind , int val , int st , int en){
		if(st+1 == en){
			seg[node] = val;
			return;
		}
		

		int mid = (st + en)/2;
		if(ind < mid){
			set(2*node +1 , ind , val , st , mid);
		}else{
			set(2*node +2 , ind ,val , mid , en);
		}
		seg[node] = seg[2*node +1] + seg[2*node +2];
	}

	void set(int i , int v){
		set(0 , i , v , 0 , size);
	}
	long long int sum(int node ,int l , int r , int st , int en){
		if(st>=l && en<=r)return seg[node];
		if(l>=en || r<=st) return 0ll;

		int mid = (st + en)/2;
		long long a = sum(2*node +1 , l , r , st , mid);
		long long b = sum(2*node +2 , l , r, mid , en);
		return a+b;
	}


	long long int sum(int l , int r){
		return sum(0 , l ,  r , 0 , size);
	}

};



void solve(){
	int n,m; cin>>n>>m;
	vector<int> arr(n);
	for(auto & it : arr) cin>>it;

	// for(auto it : arr)cout << it <<" ";
	segTree ob(n);
	ob.build(arr);
	// for(auto it : ob.seg) cout << it <<" ";
	// cout <<endl;
	while(m--){
		int x , a , b; cin>>x>>a>>b;
		if(x==1){
			ob.set(a , b);
		}else{
			// cout << a <<" " << b <<" ";
			cout << ob.sum(a , b) <<endl;
		}
	}

}

int main(){
	solve();
}