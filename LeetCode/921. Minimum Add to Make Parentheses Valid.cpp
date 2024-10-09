class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto & it : s) {
            if (st.empty() || it == '(') {
                st.push(it);
            } else {
                if (st.top() == '(') {
                    st.pop();
                } else {
                    st.push(it);
                }
            }
        }
        return (int)st.size();
    }
};
