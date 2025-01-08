class Solution {
public:
    long long const mod = 1e9 + 9;

    

    long long power_mod(long long p, long long i) {
        long long result = 1;
        p = p % mod; // Ensure base is within mod
        
        while (i > 0) {
            if (i % 2 == 1) { // If i is odd, multiply result by p
                result = (result * p) % mod;
            }
            p = (p * p) % mod; // Square the base and take mod
            i /= 2; // Divide the exponent by 2
        }
        return result;
    }
    // Extended Euclidean Algorithm to find gcd and modular inverse
    long long extended_gcd(long long a, long long b, long long &x, long long &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1;
        long long gcd = extended_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd;
    }

    // Function to find modular inverse of b modulo mod
    long long modular_inverse(long long b) {
        long long x, y;
        long long gcd = extended_gcd(b, mod, x, y);
        if (gcd != 1) {
            throw invalid_argument("Modular inverse does not exist");
        }
        return (x % mod + mod) % mod; // Ensure result is positive
    }

    // Function to calculate (a / b) % mod
    long long divide_mod(long long a, long long b) {
        long long b_inv = modular_inverse(b);
        return (a * b_inv) % mod;
    }

    vector<long long> hashFunction (string & s) {
        vector <long long> ans;
        long long hash_value = 0;
        long long p = 31;
        long long p_pow = 1;

        for (char &c: s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % mod;
            p_pow = (p_pow * p) % mod;
            ans.push_back(hash_value);
        }
        return ans;
    }

    long long getHashValueForARange (int l, int r, vector<long long> &ans) {
        if (l > r) return -1;
        if (!l) return ans[r];
        return divide_mod((ans[r] - ans[l-1] + mod) % mod, power_mod(31ll, l));
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<long long,int> prefixSeen;

        int ans = 0;

        for (auto &it: words) {
            int m = (int)it.size();

            vector <long long> hashedString = hashFunction(it);
            for (int i = 0; i < m ;i++) {
                long long curHash = hashedString[i];
                long long backHash = getHashValueForARange(m-i-1, m-1, hashedString);
                if (curHash != backHash) continue;
                ans += prefixSeen[curHash];
            }

            prefixSeen[hashedString.back()]++;
        }
        return ans;
    }
};
