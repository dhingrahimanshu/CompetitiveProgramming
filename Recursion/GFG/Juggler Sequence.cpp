class Solution{
public:
    vector<int> ans;
    void helper(int n){
        ans.push_back(n);
        if(n==1){
            return;
        }
        if(n%2){
            n = n*pow(n , 0.5);
        }else{
            n = pow(n , 0.5);
        }
        helper(n);
        
    }
    

    vector<int> jugglerSequence(int N){
        helper(N);
        return ans;
    }
};
