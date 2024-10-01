class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> hash;
        for(auto & it : arr) hash[(it%k + k)%k]++;

        if (hash[0]%2) return false;
        for (int i = 1;i<=k/2;i++) {
            if (hash[i] != hash[k-i]){
                return false;
            }
        }
        return true;
    }
};
