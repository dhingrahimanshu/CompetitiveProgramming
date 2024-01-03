class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans =0;
        int n = (int)colors.size();
        for(int i=0 ;i<n;i++){
            int j =i;
            int ma =0;
            while(j<n && colors[i]==colors[j]){
                ans +=neededTime[j];
                ma = max(ma , neededTime[j]);
                j++;
            }
            ans-=ma;
            i = j-1;
        }
        return ans;
    }
};
