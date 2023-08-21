class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i =0, j=0;
        int n = str1.size();
        int m = str2.size();
        while(i<n && j<m){
            int x = str1[i]-'a';
            int y = str2[j]-'a';
            if(x==y || (x+1)==y || (str1[i]=='z' && str2[j]=='a')){
                j++;
            }
            i++;
        }
        return j==m;
    }
};
