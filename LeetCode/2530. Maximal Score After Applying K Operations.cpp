class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto & it : nums) pq.push(it);
        int i = 0;
        long long ans = 0;
        while (i < k) {
            int ele = pq.top(); pq.pop();
            ans += ele;
            pq.push(ceil(1.0*ele / 3));
            i++;
        }
        return ans;
    }
};
