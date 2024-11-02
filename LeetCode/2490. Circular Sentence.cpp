class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector <string> arr;
        string token;
        stringstream ss(sentence);

        while (getline(ss, token , ' ')) {
            arr.push_back(token);
        }

        int n = (int) arr.size(); 

        for (int i = 0; i<n; i++) {
            int next = (i + 1) % n;

            if (arr[i].back() != arr[next][0]) return false;
        }

        return true;
    }
};
