class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> ans = {0};
        map <int,bool> check;
        for(int i=1;i<n;i++){
            int x = ans.back() -i;
            if(x<=0 || check[x]){
                ans.push_back(ans.back() + i);
            }else{
                ans.push_back(x);
            }
            check[ans.back()]++;
        }
        
        return ans;
    }
};
