class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        vector<vector<int>> ans;
        for(int i = 2;i<=n/2;i++){
            int j = n-i;
            if(prime[i] && prime[j]){
                ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};
