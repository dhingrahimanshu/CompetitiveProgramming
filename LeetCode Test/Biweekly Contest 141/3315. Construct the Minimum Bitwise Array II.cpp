typedef long long ll;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (auto & it : nums) {
            ll temp = 2e9;
            for (ll i = 0;(1ll<<i) < it;i++) {
                ll a = it - (1ll<<i);
                ll b = (a + 1);
                if ((a|b) == it) {
                    temp = min(temp, a);
 
                }
            }
            if (temp == 2e9) {
                temp = -1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


