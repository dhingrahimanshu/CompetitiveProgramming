typedef long long ll;
class Solution {
public:


    ll totalSetBits (ll num, ll x) {
        ll ans = 0;
        for (int i = x; i < 60; i+=x) {
            // ll temp = i - 1;
            ll cycle = (num + 1) / (1LL<<i);
            ll leftTemp = (num + 1) % (1LL<<i);
            ll left = max(0ll, leftTemp - (1LL<<(i-1)));

            ans += (cycle * (1LL<<(i-1))) + left;
        }
        return ans;
    }

    long long findMaximumNumber(long long k, int x) {
        long long ans = 0;

        ll lo = 0, hi = 1e15;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2ll;
            if (totalSetBits(mid, x) <= k) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
