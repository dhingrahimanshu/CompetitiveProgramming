class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int,bool> mpp;

        for (auto &it: arr) {
            if (mpp[2*it]) return true;
            if (it % 2 == 0 && mpp[it / 2]) {
                return true;
            }
            mpp[it] = 1;
        }

        return false;
    }
};
