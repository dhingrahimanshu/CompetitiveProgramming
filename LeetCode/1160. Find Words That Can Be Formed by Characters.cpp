class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> hash(26 ,0);
        for(auto & it : chars){
            hash[it-'a']++;
        }
        int ans =0;
        for(auto & it : words){
            ans+= int(it.size());
            vector<int> hash2(26 ,0);
            for(auto & it2 : it){
                hash2[it2 - 'a']++;
            }
            for(int i=0 ;i<26;i++){
                if(hash[i]<hash2[i]){
                    ans-=(int)(it.size());
                    break;
                }
            }
        }
        return ans;
    }
};
