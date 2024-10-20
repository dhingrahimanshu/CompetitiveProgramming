class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;

        int n = (int) target.size();

        int i = 0;
        string temp = "a";
        while (i < n) {
            ans.push_back(temp);
            if (target[i] == temp[i]) {
                i++;
                temp += 'a';
            } else {
                temp[i] = (char)((temp[i] - 'a' + 1)%26 + 'a');
            }
        }
        return ans;
    }
};
