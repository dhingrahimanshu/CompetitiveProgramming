class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        int n = (int)nums.size();
        int sum =0;
        for(auto & it : nums){
            sum +=it;
        }
        int ans2 = 2e9;
        vector<vector<int>> left(n/2 +1), right(n/2 +1);
        for(int i =0 ;i<(1<<n/2);i++){
            int sum =0 , sum2 =0 , sz =0;
            for(int j =0 ;j<n/2;j++){
                if(i&(1<<j)){
                    sum += nums[j];
                    sum2 += nums[j + n/2];
                    sz++;
                }
            }
            left[sz].push_back(sum);
            right[sz].push_back(sum2);
        }
    
        int target = sum/2;
        for(int i =0 ;i<=n/2;i++){
            int r = n/2 -i;
            sort(right[r].begin() , right[r].end());
            for(auto & it : left[i]){
                // cout << i <<" " << it <<' ';
                int ans =2e9;
                int req = target -it;
                auto it2 = upper_bound(right[r].begin() , right[r].end() , req);
                if(it2 == right[r].end())--it2;
                
                ans2 = min(ans2 , abs((sum - (it + *it2)) - (it + *it2)));
                // cout << *it2 <<endl;
                if(it2 !=right[r].begin()){
                    --it2;
                    ans2 = min(ans2 , abs((sum - (it + *it2)) - (it + *it2)));
                }
            }
        }
        return ans2;
    }
};
