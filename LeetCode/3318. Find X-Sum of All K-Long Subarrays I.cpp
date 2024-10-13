class Solution {
public:
    static bool mycmp (pair<int,int> &p1, pair<int,int> &p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = (int)nums.size();
        for (int i = 0; i<= n-k;i++) {
            int sum =0;
            map<int,int>mp;
            vector<pair<int,int>> arr;
            for (int j = i;j<i+k;j++) {
                mp[nums[j]]++;
            }
            for( auto & it : mp) {
                arr.push_back({it.first, it.second});
            }
            sort(arr.begin(), arr.end(),mycmp);
            for (int uf = 0;uf<min(x,(int)arr.size()); uf++) {
                sum += arr[uf].first*arr[uf].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
