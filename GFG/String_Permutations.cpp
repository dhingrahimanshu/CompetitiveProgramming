vector<string> ans;
    void helper(string & s , int i , string temp){
        if(i==(int)s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j =i ;j<(int)s.size();j++){
            swap(s[j] , s[i]);
            helper(s , i+1 , temp+s[i]);
            swap(s[j] , s[i]);
        }
    }
    vector<string> permutation(string S)
    {
        helper(S , 0 , "");
        sort(ans.begin() , ans.end());
        return ans;
    }
