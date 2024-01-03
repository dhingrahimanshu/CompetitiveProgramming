class Solution {
public:
    string reverseWords(string s) {
        int j=0 ;
        int n = (int) s.size();
        for(int i =0 ;i<n;i++){
            while(j<n && s[j]!=' '){
                j++;
            }
            int k = j-1;
            while(i<k){
                swap(s[i] , s[k]);
                i++;
                k--;
            }
            i = j;
            j++;
        }
        return s;
    }
};
