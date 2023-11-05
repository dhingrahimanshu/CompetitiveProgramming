
class Solution {
  public:
    static bool mycmp(pair<int,int> & a , pair<int,int> & b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
    vector<int> topK(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<pair<int,int>> arr;
        map <int,int> check;
        for(int i =0 ;i<n;i++){
            check[nums[i]]++;
        }
        for(auto &it : check){
            arr.push_back(it);
        }
        sort(arr.begin() , arr.end() , mycmp);
        
        vector<int> ans;
        for(int i =0 ;i<k;i++){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};
