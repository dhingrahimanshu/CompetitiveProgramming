const ll uf = (1ll<<40)-1;

class segTree{
public:
	ll size;
	vector<ll> seg;
	segTree(ll n){
		size = 1;
		while(size < n) size*=2ll;
		seg.resize(2*size , uf);
	}
	void build(vector<ll> &arr , ll node , ll st , ll en){
		if(st+1 == en){
			if(st<sz(arr)){
				seg[node]= arr[st];
			}
			return;
		}
		ll mid = (st + en)/2;
		build(arr , 2*node +1 ,st , mid);
		build(arr , 2*node +2 ,mid , en);
		seg[node] = seg[2*node +1]&seg[2*node +2];
	}
	void build(vector<ll>& arr){
		build(arr , 0 , 0 , size);
	}

	void set(ll node ,ll ind , ll val , ll st , ll en){
		if(st+1 == en){
			seg[node]= val;
			return;
		}
		ll mid = (st + en)/2;
		if(ind <mid){
			set(2*node +1 , ind , val , st , mid);
		}else{
			set(2*node +2 , ind , val , mid , en);
		}
		seg[node] = seg[2*node +1]&seg[2*node +2];
	}
	void set(ll ind , ll val){
		set(0 , ind , val , 0 , size);
	}
	ll AA(ll node , ll l , ll r ,ll st , ll en){
		if(l<=st && r>=en)return seg[node];
		if(l>=en || r<=st)return uf;
		ll mid = (st + en)/2;
		ll a = AA(2*node +1, l  , r , st , mid);
		ll b = AA(2*node +2 , l , r, mid , en);

		return a&b;
	}
	ll AA(ll l , ll r){
		return AA(0 , l , r , 0 , size);
	}

};
