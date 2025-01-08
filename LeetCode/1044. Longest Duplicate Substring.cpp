class Solution {
public:
    struct pair_hash {
        template <typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ (hash2 << 1); // Combine the two hashes
        }
    };
    string longestDupSubstring(string s) {
        long long const p = 31;
        long long const mod = 1e9 + 9;

        long long const p2 = 37;
        long long const mod2 = 1e9 + 7;

        int n = (int)s.size();
        string ans;

        int lo = 1, hi = n-1;

        vector <long long> pow_p(n), pow_p2(n);
        vector <long long> hash(n + 1), hash2(n + 1);
        pow_p[0] = 1;
        pow_p2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow_p[i] = (pow_p[i-1]*1ll*p)%mod;
            pow_p2[i] = (pow_p2[i-1]*1ll*p2)%mod2;
        }

        hash[0] = 0;
        hash2[0] = 0;

        for (int i = 0; i < n; i++) {
            hash[i+1] = (hash[i] + ((s[i] - 'a' + 1)*1ll*pow_p[i])%mod)%mod;

            hash2[i+1] = (hash2[i] + ((s[i] - 'a' + 1)*1ll*pow_p2[i])%mod2)%mod2;
        }

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            bool flag = false;

            unordered_set<pair<int,int>, pair_hash> st;
            // if (mid == 1) cout << 1 << endl;

            for (int i = 0; i <= n - mid; i++) {
                int hashValue = (hash[i + mid] - hash[i] + mod) % mod;
                int hashValue2 = (hash2[i + mid] - hash2[i] + mod2) % mod2;

                hashValue = (hashValue *1ll* pow_p[n-i-1])%mod;

                hashValue2 = (hashValue2 *1ll* pow_p2[n-i-1])%mod2;

                if (st.find({hashValue, hashValue2}) != st.end()) {
                    // if (ans.size() > )
                    // cout << mid << endl;
                    ans = s.substr(i, mid);
                    flag = true;
                    break;
                }
                st.insert({hashValue, hashValue2});
            }


            if (flag) {
                lo = mid + 1;
                // cout << mid << endl;
            } else {
                hi = mid - 1;
            }
        }



        return ans;

    }
};
