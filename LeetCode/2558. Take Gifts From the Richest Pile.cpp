class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;

        for (auto &it: gifts) ans += it;

        priority_queue <int> pq(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++) {
            int ele = pq.top(); pq.pop();
            if (ele <= 1) break;
            int rem = sqrt(ele);
            int picked = ele - rem;
            ans -= picked;
            pq.push(rem);
        }

        return ans;
    }
};
