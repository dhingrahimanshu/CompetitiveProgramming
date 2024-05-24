class Solution {
public:
    int helper(int index , vector<string> & words , vector<int> & letters , vector<int> & used , vector<int> & score){
        for(int i =0;i<26;i++){
            if(used[i]<0)return 0;
        }
        if(index == words.size()){
            int ans =0;
            for(int i =0;i<26;i++){
                ans += score[i]*(letters[i] - used[i]);
            }
            return ans;
        }
        int ans = helper(index+1 , words , letters , used , score);

        bool flag = true;
        for(auto & it : words[index]){
            used[it-'a']--;
        }
        ans = max(ans , helper(index+1 , words , letters , used , score));
        for(auto & it : words[index]){
            used[it-'a']++;
        }

        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> a(26) , b(26);
        for(auto & it : letters){
            a[it-'a']++;
            b[it-'a']++;
        }
        return helper(0, words ,a , b,score);
    }
};
