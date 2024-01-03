class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        vector<int> arr(k+1 , 0);
        
        int n = nums.size();
        
        for(auto & it : nums){
            arr[it%k]++;
        }
        for(int i =1 ;i<=k/2;i++){
            if(arr[i] != arr[k-i])return 0;
        }
        return 1;
    }
};
