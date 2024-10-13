class Solution {
public:
    bool isPrime (int n) {
        for (int i = 2;i*i<=n;i++) {
            if (n%i == 0)return 0;
        }
        return 1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        map <int,int> mp;

        for (int i = -1000;i<=1000;i++) {
            int oir = ((i)|(i+1));
            if (mp.find(oir) == mp.end()) {
                mp[oir] = i;
            }
            
        }

        for (auto & it : mp) {
            if (it.first < 2 || !isPrime(it.first)) continue;
            cout<< it.first << ' ' << it.second << endl;
        }

        for (auto & it : nums) {
            if(mp.find(it)!=mp.end()) {
                ans.push_back(mp[it]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
