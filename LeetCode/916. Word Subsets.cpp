class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector <int> hashWords2(26, 0);

        for (auto &it: words2){
            vector <int> tempHash(26, 0);

            for (auto &it2: it) {
                tempHash[it2 - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                hashWords2[i] = max(hashWords2[i], tempHash[i]);
            }
        }

        vector <string> ans;

        for (auto &it: words1){
            vector <int> tempHash(26, 0);

            for (auto &it2: it) {
                tempHash[it2 - 'a']++;
            }

            bool flag = true;

            for (int i = 0; i < 26; i++) {
                if (hashWords2[i] > tempHash[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)ans.push_back(it);
        }



        return ans;
    }
};
