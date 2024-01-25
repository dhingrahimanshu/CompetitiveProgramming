class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int> temp;
        vector<int> ans;
        int n = (int)nums.size();
        for(int i =0 ;i<k;i++){
            temp.insert(nums[i]);
        }
        ans.push_back(*(temp.rbegin()));   
        for(int i =k;i<n;i++){
            temp.erase(temp.find(nums[i-k]));
            temp.insert(nums[i]);
            ans.push_back(*(temp.rbegin()));
        }
        return ans;
    }
};
