class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = (int) box.size();
        int n = (int) box[0].size();

        vector<vector<char>> rotatedBox(n, vector<char>(m));

        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - i - 1] = box[i][j];
            }   
        }

        for (int i = 0; i < m ; i++) {
            int lastFree = -1;
            for (int j = n-1; j>=0; j--) {
                if (rotatedBox[j][i] == '.') {
                    lastFree = max(j, lastFree);
                } else if (rotatedBox[j][i] == '#') {
                    // if (!i) {
                    //     cout << j << ' ' << lastFree << endl;
                    // }
                    if (j < lastFree) {
                        swap(rotatedBox[j][i], rotatedBox[lastFree][i]);
                        lastFree--;
                    }
                } else {
                    lastFree = -1;
                }
            }   
            
        }


        return rotatedBox;
    }
};
