class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (auto &it : derived) x^= it;
        return x == 0;
    }
};
