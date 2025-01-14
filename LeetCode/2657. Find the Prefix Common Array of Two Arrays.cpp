class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = (int)A.size();

        vector <bool> hashA(n + 1, 0), hashB(n + 1, 0);
        vector <int> ans;
        int same = 0;
        for (int i = 0; i < n; i++) {
            hashA[A[i]] = 1;
            if (hashB[A[i]]) {
                same++;
            }

            hashB[B[i]] = 1;
            if (hashA[B[i]]) {
                same++;
            }

            ans.push_back(same);
        }
        return ans;
    }
};
