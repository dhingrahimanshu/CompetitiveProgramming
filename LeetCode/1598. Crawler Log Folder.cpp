class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        
        for(auto & it : logs){
            if(it.size() == 2){
                if(it[0]!='.')ans++;
            }else{
                if(it[0]!='.'){
                    ans++;
                }else{
                    ans = max(0, ans - 1);
                }
            }
        }

        return ans;
    }
};
