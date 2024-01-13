class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hash(26 ,0) , hash2(26 ,0);
        int ans =0;

        for(auto & it : s){
            hash[it -'a']++;
        }
        for(auto & it : t){
            hash2[it - 'a']++;
        }
        for(int i =0 ;i<26;i++){
            ans += abs(hash[i] - hash2[i]);
        }

        return ans/2;
    }
};
