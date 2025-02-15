class Solution {
public:

    bool isOk (string & s, int i, int &og, int sum) {
        if (i == s.size()) {
            return sum == og;
        }

        int temp = 0;
        bool ans = false;

        for (int level = i; level < s.size(); level++) {
            temp = 10*temp + (s[level] - '0');
            ans |= isOk(s, level + 1, og, sum + temp);
        }
        
        return ans;
    }

    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n ;i++) {
            int num = i;
            string s = to_string(num * num);
            if (isOk(s, 0, num, 0)) {
                // cout << i << endl;
                ans += num * num;
            }
        }

        return ans;
    }
};
