class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> temper;
        sort(nums.begin(), nums.end());
        for(int i =2;i<nums.size();i++){
            int j =0 , k = i-1;
            while(j<k){
                int x = nums[j]+nums[k];
                if(x==-nums[i]){
                    temper.insert({nums[j] , nums[k] , nums[i]});
                    j++;
                    k--;
                }else if(x>-nums[i]){
                    k--;
                }else{
                    j++;
                }
            }
        }
        for(auto &it : temper){
            ans.push_back(it);
        }
        return ans;
    }
};
