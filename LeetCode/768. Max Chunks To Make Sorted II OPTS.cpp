class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = (int) arr.size();

        stack <int> st;
        
        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top() < arr[i]){
                st.push(arr[i]);
            } else {
                int ma = arr[i];
                while (st.size() && st.top() > arr[i]) {
                    ma = max(ma, st.top());
                    st.pop();
                }
                st.push(ma);
            }
        }


        return (int) st.size();
    }
};
