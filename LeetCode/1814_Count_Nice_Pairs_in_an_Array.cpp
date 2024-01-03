class Solution {
public:

    int reverseit(int n){
        string s = to_string(n);

        reverse(s.begin() , s.end());
        n = stoi(s);
        return n;
    }
    int const MOD = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        unordered_map <int,int> check;
        int n = (int)nums.size();
        for(int i =0 ;i<n;i++){
            nums[i] = nums[i] - reverseit(nums[i]);
        }

        int ans = 0;

        for(int i =0 ;i<n;i++){
            ans = (ans + check[nums[i]])%MOD;
            check[nums[i]]++;
        }

        return ans;
    }
};
