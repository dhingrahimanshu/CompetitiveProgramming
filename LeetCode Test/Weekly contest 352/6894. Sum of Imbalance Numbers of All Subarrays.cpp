class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =0 ;i<n;i++){
            unordered_set <int> temp;
            temp.insert(nums[i]);
            int cur=0;
            for(int j =i+1;j<n;j++){
                
                if(!temp.count(nums[j])){
                    if(!temp.count(nums[j]-1) && !temp.count(nums[j]+1)){
                        cur++;
                    }else if (temp.count(nums[j]-1) && temp.count(nums[j]+1)){
                        cur--;
                    }
                }
                temp.insert(nums[j]);
                ans+=cur;
            }
        }
        return ans;
    }
};
