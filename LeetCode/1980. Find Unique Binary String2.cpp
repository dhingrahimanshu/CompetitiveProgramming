class Solution {
public:

    int binToNum (string & a) {
        int num = 0;
        int two = 1;

        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == '1') {
                num += two;
            }
            two *= 2;
        }

        return num;
    }

    string numToBin (int num) {
        string b;

        while (num) {
            b = ((num % 2)?'1':'0') + b;
            num /= 2;
        }

        return b;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        map <int,bool> mpp;
        int sz = nums[0].size();
        for (auto &it : nums) {
            mpp[binToNum(it)] = 1;
        }

        int ans = 0;

        for (int i = 0; i <= 2 ^ 16; i++) {
            if (!mpp[i]) {
                ans = i;
                break;
            }
        }

        string lastPart = numToBin(ans);
        string startPart(sz - lastPart.size(), '0');

        return startPart + lastPart;
    }
};
