class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        stringstream ss(sentence1);
        stringstream s2(sentence2);

        string word, word2;
        vector<string> arr1, arr2;

        while (getline(ss, word, ' ')) {
            arr1.push_back(word);
        }

        while (getline(s2, word2, ' ')) {
            arr2.push_back(word2);
        }

        int i1 = 0, j1 = (int)arr1.size() - 1;
        int i2 = 0, j2 = (int)arr2.size() - 1;

        while(i1<=j1 && i2<=j2) {
            bool ok = false;
            if (arr1[i1] == arr2[i2]) {
                i1++;
                i2++;
                ok = true;
            }

             if (arr1[j1] == arr2[j2]) {
                j1--;
                j2--;
                ok = true;
            }
            if (!ok) break;
        }
        return (i1>j1 || i2>j2);
    }
};
