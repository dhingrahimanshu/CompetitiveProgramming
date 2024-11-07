class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int)s.size();
        vector<int> st;
        st.push_back(-1);

        for (int i = 0; i<n; i++) {
            if (st.empty() || s[i] == '(') {
                st.push_back(i);
            } else {
                if (st.back()!=-1 && s[st.back()] =='(') {
                    st.pop_back();
                } else {
                    st.push_back(i);
                }
            }
        }
        st.push_back(n);
        int ans = 0;
        for (int i = st.size() - 2; i>=0;i--) {
            ans = max(ans, st[i+1] - st[i] - 1);
        }
        return ans;

    }
};
