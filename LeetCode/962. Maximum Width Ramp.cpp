class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> ans(n, -1);

        vector<int> st;

        for (int i = 0; i<n; i++) {
            if (st.empty() || nums[st.back()] > nums[i]) {
                st.push_back(i);
            } else {
                
                for (int j = (int)st.size() - 1;j>=0; j--) {
                    if (nums[st[j]] > nums[i]) break;
                    if (ans[st[j]] != -1) {
                        ans[i] = i - ans[st[j]];
                    } else {
                        ans[i] = i - st[j];
                    }
                }
    
                
            }
        }

        int mw = 0;
        for (auto & it : ans) {
            mw = max(mw, it);
        }
        return mw;
    }
};
