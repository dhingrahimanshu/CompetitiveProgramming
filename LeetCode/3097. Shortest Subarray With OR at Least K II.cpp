class Solution {
public:
    void changeBits(vector<int> & hash, int a, int flag) {
        for (int i = 0; i < 31; i++) {
            if ((a>>i) & 1)  {
                if (flag) {
                    hash[i]++;
                } else {
                    hash[i]--;
                }
                
            }
        }
    }
    int getNum (vector<int> & hash) {
        int ans = 0;

        for (int i = 0; i < 31; i++) {
            if (hash[i]) {
                ans += (1<<i);
            }
        }

        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (!k) return 1;
        vector<int> hash(32, 0);
        int n = (int)nums.size();
        int j = 0;
        int oR = 0;
        int ans = n;
        while (j<n && oR < k) {
            oR |= nums[j];
            changeBits(hash, nums[j], 1);
            j++;
        }

        if (oR < k) return -1;
        ans = j;
        for (int i = 0;i<n; i++) {
            changeBits(hash, nums[i], 0);
            oR = getNum(hash);
            // cout << oR << endl;
            while (j<n && oR < k) {
                changeBits(hash, nums[j], 1);
                oR|=nums[j];
                j++;
            }
            if (oR < k) break;
            ans = min(ans ,j - i - 1);
        }

        return ans;
    }
};
