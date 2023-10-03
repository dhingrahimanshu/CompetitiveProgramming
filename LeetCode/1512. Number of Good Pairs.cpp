class Solution {
public:
    int nsum(int n){
        n--;
        if(n<=0)return 0;
        return (n*(n+1))/2;
    }
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> hash(101 , 0);
        for(auto & it : nums){
            hash[it]++;
        }
        int ans =0;

        for(int i = 0;i<=100;i++){
            ans+=nsum(hash[i]);
        }

        return ans;
    }
};
