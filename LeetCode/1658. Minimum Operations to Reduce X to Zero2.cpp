class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = 1e9;
        int n = (int)nums.size();
        vector<int> pref(nums.begin(), nums.end()), suf(nums.begin(),nums.end()); 
        for(int i = 1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        for(int i = n-2;i>=0;i--){
            suf[i] += suf[i+1];
        }
        reverse(suf.begin() , suf.end());
        for(int i = 0;i<n;i++){
            int left = x;
            if(i){
                left = x - pref[i-1];
            }
            if(left < 0){
                break;
            }
            if(left == 0){
                ans = min(ans, i);
                continue;
            }
            auto it = lower_bound(suf.begin(),suf.end(),left);
            if(it!=suf.end() && *it == left){
                // cout << i <<endl;
                int j = (it - suf.begin());
                if(i + j + 1 <= n){
                    ans = min(i + j + 1, ans);
                }
            }
        }

        return (ans == 1e9)?-1:ans;
    }
};
