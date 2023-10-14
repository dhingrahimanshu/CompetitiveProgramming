class Solution {
public:
    static bool check2(string &s1 ,string & s2){
        int ans =0;
        for(int i =0 ;i<(int)s1.size();i++){
            ans+= (s1[i]!=s2[i]);
        }
        
        return ans==1;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> parent(n , -1);
        vector<int> dp(n , 0);
        int mi =100 , ma = 0;
        
        for(int i =0 ;i<n;i++){
            pair<int,int> check={-1 ,-1};
            for(int j =0;j<i;j++){
                if((int)words[i].size() == (int)words[j].size() && check2(words[i] , words[j]) && groups[i]!=groups[j]){
                    if(check.second < dp[j]){
                        check.first = j;
                        check.second = dp[j];
                    }
                }
            }
            if(check.first ==-1){
                dp[i] = 1;
            }else{
                dp[i] = 1+check.second;
                parent[i] = check.first;
            }
            
        }
        int temp = (max_element(dp.begin() , dp.end()) - dp.begin());
        vector<string> ans;
        while(temp!=-1){
            ans.push_back(words[temp]);
            temp = parent[temp];
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};
