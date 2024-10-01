class CustomStack {
public:
    int capacity = 0;
    int filled = 0;
    stack<pair<int,vector<pair<int,int>>>> st;
    CustomStack(int maxSize) {
        capacity = maxSize;
        filled = 0;
    }
    
    void push(int x) {
        if (filled == capacity) return;
        vector<pair<int,int>> temp;
        st.push({x, temp});
        filled++;
    }
    
    int pop() {
        if (filled == 0) return -1;
        filled--;
        pair<int,vector<pair<int,int>>> ele = st.top(); st.pop();
        int temp = ele.first;
        for(auto & it : ele.second) {
            temp += it.second;
            if(it.first > 1 && st.size()) {
                st.top().second.push_back({it.first -1, it.second});
            }
        }
        return temp;
    }
    
    void increment(int k, int val) {
        if (!st.size()) return;
        vector<pair<int,vector<pair<int,int>>>> tmp;
        while(st.size() > k) {
            tmp.push_back(st.top());
            st.pop();
        }
        st.top().second.push_back({k,val});
        for(int i = tmp.size()-1;i>=0;i--) {
            st.push(tmp[i]);
        }
    }
};
