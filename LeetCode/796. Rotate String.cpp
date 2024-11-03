class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = (int)goal.size();
        for (int i = 0; i < n; i++) {
            goal = goal.back() + goal;
            goal.pop_back();
            if (goal == s) return true;
        }
        return false;
    }
};
