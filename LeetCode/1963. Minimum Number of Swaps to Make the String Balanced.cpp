class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int n = (int)(s.size());
        int i = 0 , j = n -1;

        int open = 0, close = 0;
        while (i<j) {
            if (s[i] == '[') open++;
            else close++;

            if (close > open) {
                while(j>i && s[j]!='[') {
                    j--;
                }
                swap(s[i],s[j]);
                j--;
                ans++;
                open++;
                close--;
            }
            i++;  
        }
        return ans;

    }
};
