class Solution {
public:

    string ans;
    unordered_set<string> check;
    void helper(string & uf  , int i , int n){
        if(i==n){
            if(check.find(uf)==check.end()){
                ans = uf;
            }
            return;
        }
        uf+='0';
        helper( uf , i+1 , n);
        uf.pop_back();
        if(ans.size()!=0){
            return;
        }
        uf+='1';
        helper(uf , i+1 , n);
        uf.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        for(auto & it : nums){
            check.insert(it);
        }
        string s;
        helper( s, 0 , nums.size());
        return ans;
    }   
};
