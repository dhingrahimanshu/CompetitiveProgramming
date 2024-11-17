typedef long long ll;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int j = 0;
        int n = (int) nums.size();
        ll ans = 1e9;

        ll sum = 0;
        priority_queue<pair<ll, ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum >= k) {
                ans = min(ans, i + 1ll);
            }

            while (pq.size() && (sum - pq.top().first) >= k) {
                ans = min(ans, 1ll *(i - pq.top().second));
                pq.pop();
            }
            pq.push({sum, i});
        }
        return (ans == 1e9)?-1:ans;

    }
};
