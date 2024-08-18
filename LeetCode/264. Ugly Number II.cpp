typedef long long ll;



class Solution {
    ll expo(ll a , ll b){
        if(b == 0)return 1;

        ll temp = expo(a, b/2);
        if(b%2){
            return a*temp*temp;
        }else{
            return temp*1ll*temp;
        }
    }

public:
    int nthUglyNumber(int n) {
        ll uf = 3e9;
        ll x1 = log2(uf);
        ll x2 = log(uf)/log(3);
        ll x3 = log(uf)/log(5);

        vector<ll> arr;
        for(int i = 0;i<=x1;i++){
            for(int j = 0;j<=x2;j++){
                ll x1 = expo(2, i);
                ll x2 = expo(3, j);
                if(x1*x2 > uf)continue;

                for(int k = 0;k<=x3;k++){
                    
                    ll x3 = expo(5, k);
                    if(x2*x3 > uf || x3*x1 > uf)continue;
                    ll temp = x1*x2*x3;
                    if(temp <= uf){
                        arr.push_back(temp);
                    }
                    
                }
            }
        }
        sort(arr.begin(), arr.end());
        // for(auto & it : arr)cout << it << ' ';
        // cout << endl;
        return arr[n - 1];
    }
};
