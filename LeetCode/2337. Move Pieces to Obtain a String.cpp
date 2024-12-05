class Solution {
public:
    bool canChange(string start, string target) {
        int n = (int) start.size();
        int i = 0;
        int j = 0;

        while (i < n || j < n) {

            while (i < n && start[i]=='_')i++;
            while (j < n && target[j]=='_')j++;
            
            if ((i < n && j>=n) || (i>=n && j < n)) {
                return false;
            }
            if (i >= n && j >= n) return true;
            if (start[i] == target[j]) {
                if (start[i] == 'L') {
                    if (i < j) {
                        return false;
                    }
                } else {
                    if (i > j) {
                        return false;
                    }
                }
                i++;
                j++;
            } else {
                return false;
            }
            
        }


        return true;
    }
};
