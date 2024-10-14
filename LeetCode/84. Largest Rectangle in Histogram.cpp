class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> arr(heights.begin(), heights.end());
        int ans = 0;
        stack<int> st;

        int n = (int)arr.size();

        vector<int> forward(n, n), backward(n,-1);
        for (int i = 0; i<n;i++) {
            if (!st.size() || arr[i] > arr[st.top()]) {
                st.push(i);
            } else {
                while (st.size() && arr[st.top()] > arr[i]) {
                    forward[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        

        while(st.size())st.pop();

        for (int i = n-1; i>=0;i--) {
            if (st.empty() || arr[i] > arr[st.top()]) {
                st.push(i);
            } else {
                while (st.size() && arr[st.top()] > arr[i]) {
                    backward[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        for (int i = 0; i<n;i++) {
            // cout << arr[i] << ' ' << forward[i] << ' ' <<  backward[i] << endl;
            ans = max(ans, arr[i]*(forward[i] - backward[i] - 1));
        }
        return ans;

    }
};
