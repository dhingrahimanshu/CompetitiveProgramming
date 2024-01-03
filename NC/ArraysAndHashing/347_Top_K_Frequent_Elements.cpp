class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>hash(2e4 +10);
        for(int i =0 ;i<nums.size();i++){
            hash[nums[i] + 1e4]++;
        }
        vector<pair<int,int>> arr;
        for(int i =0 ;i<=2e4;i++){
            if(hash[i]){
                arr.push_back({i , hash[i]});
            }
        }
        auto mycmp=[](pair <int,int> p1 , pair <int,int> p2){
            return p1.second>p2.second;
        };
        sort(arr.begin(),arr.end() , mycmp);
        vector<int> ans;
        for(int i =0 ;i<k;i++){
            ans.push_back(arr[i].first - 1e4);
        }
        return ans;
    }
};
