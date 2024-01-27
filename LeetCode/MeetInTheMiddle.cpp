class Solution {
public:
    void helper(int start , int end ,long long int sum, vector<int> &nums , vector<long long int> & arr){
        if(start > end){
            arr.push_back(sum);
            return ;
        }
        helper(start+1 , end , sum + nums[start] ,nums , arr);
        helper(start +1 , end , sum , nums , arr);

    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = (int)nums.size();
        vector<long long int> arr , arr2;
        helper(0 ,n/2 ,0, nums , arr);
        helper((n/2) +1 , n-1 ,0, nums , arr2);
        long long int ans = 2e9;
        sort(arr2.begin() , arr2.end());
        for(int i=0 ;i<arr.size();i++){
            int req = goal - arr[i];
            auto it = upper_bound(arr2.begin() , arr2.end() , req);
            if(it == arr2.end())--it;
                ans = min(ans , abs(goal - (arr[i] + *it)));
                if(it!=arr2.begin()){
                    --it;
                    ans = min(ans , abs(goal - (arr[i] + *it)));
                }
                
            }
        
        return ans;
    }
};
