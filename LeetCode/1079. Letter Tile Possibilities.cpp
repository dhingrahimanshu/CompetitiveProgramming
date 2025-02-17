class Solution {
public:
    vector <int> fact;

    void preComputeFact () {
        fact[0] = 1;
        for (int i = 1; i <= 7; i++) {
            fact[i] = fact[i-1] * i;
        }
    }

    int calculateCombinations (string & cur) {
        vector <int> freq(26, 0);

        for (auto &it: cur) {
            freq[it - 'A']++;
        }

        int ans = fact[(int)cur.size()];

        for (auto &it: freq) {
            if (it > 1) {
                ans /= fact[it];
            }
        }

        return ans;

    }

    int helper (int level, int &n, string &current, string & tiles, unordered_set <string> & seen) {
        if (level >= n) {

            if (seen.find(current) == seen.end()) {
                seen.insert(current);
                return calculateCombinations(current);
            }

            return 0;
        }

        // don't take
        int ans = helper (level + 1, n, current, tiles, seen);


        // take
        current += tiles[level];
        ans += helper(level + 1, n, current, tiles, seen);
        current.pop_back();

        return ans;
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        fact.resize(8, 0);
        preComputeFact();

        unordered_set <string> seen;
        sort(tiles.begin(), tiles.end());

        string cur;
        return helper(0, n, cur, tiles, seen) - 1;
    }
};
