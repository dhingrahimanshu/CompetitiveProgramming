class Solution {
public:
    int ans =0;
    void helper(vector<string>&arr , set <char> &s , int level){
        if(level == arr.size()){
            ans = max(ans, (int)s.size());
            return;
        }
        helper(arr , s , level+1);
        set<char>temp(arr[level].begin() , arr[level].end());
        if(temp.size() != arr[level].size())return;
        bool flag = true;
        for(auto & it : arr[level]){
            if(s.find(it)!=s.end())flag = false;
        }
        
        if(flag){
            for(auto & it : arr[level]){
                s.insert(it);
            }
        }else{
            return;
        }
        helper(arr , s, level+1);
        for(auto & it : arr[level]){
            s.erase(it);
        }

    }
    int maxLength(vector<string>& arr) {
        set <char>s1;
        helper(arr , s1 ,0);
        return ans;
    }
};
