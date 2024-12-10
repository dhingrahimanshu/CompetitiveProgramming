class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set <int> st;

        for (auto &it: nums) {
            if (it < k) return -1;
            if (it == k) continue;
            st.insert(it);
        }
        return (int)st.size();
    }
};
