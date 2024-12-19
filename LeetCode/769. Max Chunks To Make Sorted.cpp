class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = (int) arr.size();
        vector <int> temp(arr.begin(), arr.end());
        vector<int> cur;

        sort (temp.begin(), temp.end());

        int ans = 0;
        int lastChunkEnd = 0;
        
        for (int i = 0; i < n; i++) {
            
            cur.push_back(arr[i]);
            sort(cur.begin(), cur.end());

            bool flag = true;

            for (int j = lastChunkEnd; j <= i; j++) {
                if (cur[j - lastChunkEnd] != temp[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                lastChunkEnd = i + 1;
                cur.clear();
                ans++;
            }
            
        }

        return ans;

    }
};
