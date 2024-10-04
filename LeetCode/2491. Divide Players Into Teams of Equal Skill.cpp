typedef long long ll;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        long long n = (int)skill.size();

        ll sum = 0;
        for (auto & it : skill) sum += it;

        if (sum%(n/2)) return -1;

        ll req = (2*sum) / n;
        
        sort(skill.begin(), skill.end());

        int i = 0, j = n - 1;
        while (i<j) {
            if (skill[i] + skill[j] != req) return -1;
            ans += (skill[i]*skill[j]);
            i++;j--;
        }

        return ans;

    }
};
