class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())return 0;
        vector<int> hash(26 ,0) , hash2(26 ,0);

        for(auto &it : word1){
            hash[it - 'a']++;
        }
        for(auto & it : word2){
            hash2[it - 'a']++;
        }
        for(int i =0 ;i<26;i++){
            if(hash[i]!=hash2[i]){
                if(hash[i]==0){
                    if(hash2[i])return false;
                    continue;
                }
                if(hash2[i]==0)return false;
                for(int j =i+1 ;j<26;j++){
                    if(hash2[i]==hash[j]){
                        swap(hash[i] , hash[j]);  
                    }
                }
            }
        }
        for(int i=0 ;i<26;i++){
            if(hash[i]!=hash2[i])return false;
        }
        return true;
    }
};
