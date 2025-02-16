class Solution {
public:
    vector <int> ans;
    // bool flag = false;

    bool helper (int level, int &mask, int &n, vector <int> &arr) {
        if (level >= arr.size()) {

            // for (auto &it: arr) cout << it << ' ';
            // cout << '\n';

            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] > ans[i]) {
                    ans = arr;
                    break;
                } else if (arr[i] < ans[i]){
                    break;
                }
            }
            return true;
        }
        // cout << arr.size() << '\n';

        if (arr[level]) {
            return helper(level + 1, mask, n , arr);
            // return;
        }

        for (int i = n; i >= 1; i--) {
            // if (level + i >= arr.size()) break;
            if ((mask & (1 << i)) == false) {
                if (i == 1) {

                    // set values
                    mask |= (1 << i);
                    arr[level] = i;
                    
                    // move on
                    if (helper(level + 1, mask, n, arr)) return true;

                    // back track
                    arr[level] = 0;
                    mask ^= (1 << i);
                } else if (level + i < arr.size() && !arr[level + i]){

                    // set values
                    mask |= (1<<i);
                    arr[level] = i;
                    arr[level + i] = i;

                    // move on
                    if (helper (level + 1, mask, n , arr)) return true;


                    // back track
                    arr[level] = 0;
                    arr[level + i] = 0;
                    mask ^= (1 << i);
                }

            }
        }
        return false;
    }


    vector<int> constructDistancedSequence(int n) {
        ans = vector <int>((2 * n) - 1, 0);
        int mask = 0;
        vector <int> arr((2 * n) - 1, 0);

        helper(0, mask, n, arr);
        return ans;
    }
};
