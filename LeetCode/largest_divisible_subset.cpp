class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n ,0) , lds2 , parent(n ,0);
        int lds =0;
        sort(nums.begin()   , nums.end());
        for(int i=0;i<n;i++){
            int pre =0;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && ans[j]>pre){
                    parent[i] = j;
                    pre = ans[j];
                }
            }
            ans[i] = 1 + pre;
            lds = max(lds , ans[i]);
            if(ans[i]==1){
                parent[i] =i;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(lds == ans[i]){
                int x = i;
                while(parent[x]!=x){
                    lds2.push_back(nums[x]);
                    x = parent[x];
                }
                lds2.push_back(nums[x]);
                break;
                
            }
        }
        return lds2;
        
    }
};
