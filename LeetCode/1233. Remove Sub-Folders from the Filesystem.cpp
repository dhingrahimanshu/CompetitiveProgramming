class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st;

        sort(folder.begin(), folder.end());

        for (auto & it : folder) {
            string temp;
            bool flag = true;
            for (int i = 0; i<it.size();) {
                while(i<it.size() && it[i]!='/') {
                    temp += it[i];
                    i++;
                }
                
                if (st.find(temp) != st.end()) {
                    flag = false;
                    break;
                }
                temp += it[i];
                i++;
            }
            if (flag) {
                st.insert(it);
            }
            
        }



        vector<string> ans;
        for (auto  &it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};
