class Solution{
public:
    void helper(int n , vector<int> & ans){
        if(n<=0){
            ans.push_back(n);
            return;
        }
        ans.push_back(n);
        helper(n-5 , ans);
        ans.push_back(n);
        
    }
    vector<int> pattern(int N){
        vector<int> ans;
        helper(N , ans);
        return ans;
    }
};
