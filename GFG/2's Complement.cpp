class Solution{
public:
    string complement(string bi){
        string ans;
        
        for (auto & it : bi) {
            if (it == '1') ans += '0';
            else ans += '1';
        }
        
        for (int i = (int)ans.size() - 1;i>=0;i--) {
            if (ans[i] == '1') {
                ans[i] = '0';
                continue;
            }
            ans[i]='1';
            break;
        }
        
        return ans;
    }
};
