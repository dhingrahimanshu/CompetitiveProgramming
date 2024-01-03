class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = INT_MAX;
        for(auto it : strs){
            n = min(n ,(int) it.size());
        }
        for(int i =0 ;i<n;i++){
            set<char>uf;
            for(int j =0 ;j<strs.size();j++){
                uf.insert(strs[j][i]);
            }
            if(uf.size()==1){
                ans += *uf.begin();
            }else{
                break;
            }
        }
        return ans;
    }
};
