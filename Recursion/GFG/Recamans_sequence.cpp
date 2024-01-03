class Solution{
public:
    vector<int> ans;
    vector<int> hash;
    int helper(int n){
        if(n==0){
            ans.push_back(0);
            return 0;
        }
        int a = helper(n-1);
        if(a-n > 0 && hash[a-n]==0){
            n = a-n;
        }else{
            n = a+n;
        }
        hash[n]=1;
        ans.push_back(n);
        return n;
    }
    vector<int> recamanSequence(int n){
        hash.resize(1001 , 0);
        helper(n-1);
        return ans;
    }
};
