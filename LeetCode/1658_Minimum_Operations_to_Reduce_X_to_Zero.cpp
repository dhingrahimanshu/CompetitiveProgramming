class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = (int) nums.size();
        vector<int> prefix(n+1 , 0) , suffix(n);
    
        for(int i = 1;i<=n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        suffix[n-1] = nums[n-1];
        unordered_map <int,int> temp;
        temp[suffix[n-1]] =1;
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1]+ nums[i];
            temp[suffix[i]] = n-i;
        }
        int ans = INT_MAX;
        for(int i = 0;i<=n;i++){
            int a = prefix[i];
            int re = x-a;
            if(re==0){
                ans = min(ans , i);
                continue;
            }
            int find = temp[re];
            if(find==0)continue;
            int xx = n -find+1;
            
            if(xx>i){
                ans = min(ans , find + i);
            }
        }
        if(ans==INT_MAX) ans =-1;
        return ans;
    }
};
