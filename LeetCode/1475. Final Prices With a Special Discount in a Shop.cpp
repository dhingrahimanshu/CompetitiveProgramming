class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = (int) prices.size();
        vector <int> ans (n , 0);
        stack <int> st;

        for (int i = 0; i < n; i++) {
            ans[i] = prices[i];

            if (st.empty() || prices[st.top()] < prices[i]) {
                st.push(i);
            } else {
                while (st.size() && prices[st.top()] >= prices[i]) {
                    ans[st.top()] -= prices[i];
                    st.pop();
                }
                st.push(i);
            }
        }

        return ans;
    }
};
