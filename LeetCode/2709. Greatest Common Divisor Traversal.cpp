class DSU{
public:
    vector<int> par , size;
    DSU(){
        int n = 1e5;
        for(int i =0;i<=n;i++){
            par.push_back(i);
            size.push_back(1);
        }
    }
    int get(int u){
        if(u == par[u])return u;
        return par[u] = get(par[u]);
    }
    void union_set(int u , int v){
        u = get(u) , v= get(v);
        if(u == v)return;
        if(size[u]>= size[v]){
            size[u]+=size[v];
            par[v] = u;
        }else{
            size[v]+=size[u];
            par[u] =v ;
        }
    }
};

class Solution {
public:
    vector<int> prime;
    void sieve(){
        int n = 1e5 +1;
        prime.resize(n , 0);
        for(int i =2;i<n;i++){
            if(prime[i])continue;
            for(int j = 2*i ;j<n;j+=i){
                prime[j] = i;
            }
            prime[i]=i;
        }
    }
    void factors(int n ,DSU & ob){
        int temp =n;
        while(n>1){
            ob.union_set(temp , prime[n]);
            temp = prime[n];
            n = n/temp;
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1)return 1;
        DSU ob;
        sieve();
        for(auto &it : nums){
            if(it==1)return 0;
            factors(it , ob);
        }
       
        int f = ob.get(nums[0]);
        for(int i = 1;i<nums.size();i++){
            if(f != ob.get(nums[i]))return false;
        }
        return true;
    }
};
