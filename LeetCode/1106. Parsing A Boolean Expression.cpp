class Solution {
public:

    bool helper (int l, int r, string & s) {
        if (l == r) {
            if (s[l]== 't') return true;
            if (s[r] == 'f') return false;
            assert(false);
        }
        assert((s[l]=='&' || s[l] =='|' || s[l] =='!'));

        if (s[l] == '!') {
            return !helper(l + 2, r-1, s);
        } else {
            int prev = l + 2;
            int open = 0;
            vector<int> ans;
            for (int i = l + 2; i<=r ; i++) {
                if (s[i] == '(') open ++;
                if (s[i] == ')') open --;

                if (s[i] == ',' && !open) {
                    ans.push_back(helper(prev, i - 1, s));
                    prev = i + 1;
                }
                
            }

            ans.push_back(helper(prev, r - 1, s));
            if (s[l] == '&') {
                bool ans2 = true;
                for (auto & it : ans)  {
                    ans2 &= it;
                }
                return ans2;
            } else {
                bool ans2 = false;
                for (auto &it : ans)  {
                    ans2 |= it;
                }
                return ans2;
            }
        }

        return 0;
    }
    bool parseBoolExpr(string expression) {
        int n = (int)expression.size();
        
        return helper(0, n-1, expression);;
    }
};
