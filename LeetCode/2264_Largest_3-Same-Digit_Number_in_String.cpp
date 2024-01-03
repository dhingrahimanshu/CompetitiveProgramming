class Solution {
public:
    string largestGoodInteger(string num) {
        int n = (int) num.size();
        string s = num;
        string ans;
        for(int i = 1;i<n-1;i++){
            if(s[i]==s[i-1] && s[i+1]==s[i]){
                string ans2(3 ,s[i]);
                if(ans<ans2){
                    ans=ans2;
                }
            }
        }   

        return ans;
    }
};
