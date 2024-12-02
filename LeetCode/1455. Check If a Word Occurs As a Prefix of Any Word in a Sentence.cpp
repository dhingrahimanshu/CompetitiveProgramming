class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> arr;
        stringstream ss(sentence);
        string token;

        while (getline(ss, token , ' ')) {
            arr.push_back(token);
        }

        for (int i = 0; i < (int) arr.size(); i++) {
            if ((int)arr[i].size() < searchWord.size()) continue;

            int j = 0;
            bool flag = true;
            while (j < searchWord.size()) {
                if (searchWord[j] != arr[i][j]) {
                    flag = false;
                    break;
                }
                j++;
            }
            if (flag) return i + 1;


        }

        return -1;
    }
};
