typedef long long ll;
class Solution {
public:
    bool check(vector<int> & start, ll dif , ll d) {
        ll prev = start[0];
        for(int i = 1;i<start.size();i++) {
            if((prev + dif) > (start[i]*1ll + d)) return 0;
            prev = max(start[i]*1ll, prev + dif);
        }
        return 1;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        ll lo =0,  hi = 2e9;
        ll ans = 0;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            if(check(start, mid, d)) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
