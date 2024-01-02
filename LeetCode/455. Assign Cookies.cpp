class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int i =g.size()-1 ,j = s.size()-1;
        int ans =0;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                i--;
                j--;
                ans++;
            }else{
                i--;
            }
        }
        return ans;
    }
};
