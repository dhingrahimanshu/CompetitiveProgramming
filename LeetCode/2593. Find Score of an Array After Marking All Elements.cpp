class Solution {
public:
    bool canMark (int index, vector<int> & howMarked, int n) {
        if (index < 0 || index >= n) return false;
        if (howMarked[index]) return false;

        return true;
    }

    void markNeighbor (int index, vector<int> & howMarked, int n) {
        if (index < 0 || index >= n) return ;

        howMarked[index] = 1;
        if (index) howMarked[index - 1] = 2;
        if (index + 1 < n) howMarked[index + 1] = 2;
    }
    long long findScore(vector<int>& nums) {
        int n = (int) nums.size();
        vector<pair<int,int>> arr;

        long long ans = 0;


        vector <int> howMarked (n, 0); // 0- not marked, 1 - marked itself, 2 - marked by neighbor 

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

        for (auto &it: arr) {
            pair <int,int> ele = it;
            if (!canMark(ele.second, howMarked, n)) continue;
            ans += it.first;
            markNeighbor(ele.second, howMarked, n);
        }
        return ans;
    }
};
