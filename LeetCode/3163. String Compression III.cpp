class Solution {
public:
    string getNum (int n) {
        return to_string(n);
    }
    string compressedString(string word) {
        string ans;
        int n = (int)word.size();

        int j = 0;
        for (int i = 0; i < n;) {
            while (j < n && word[j] == word[i]) j++;

            int count = j-i;

            while (count) {
                int temp = min(9, count);
                count -= temp;
                ans += (getNum(temp) + word[i]);
            }
            i = j;
        }

        return ans;
    }
};
