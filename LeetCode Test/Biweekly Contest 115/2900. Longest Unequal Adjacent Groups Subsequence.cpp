class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans = {words[0]};
        int prev = groups[0];
        for(int i =1;i<n;i++){
            if(groups[i]!=prev){
                ans.push_back(words[i]);
                prev = groups[i];
            }
        }
        return ans;
    }
};
