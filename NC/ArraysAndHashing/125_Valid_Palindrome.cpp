class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        int n = s.size();
        for(int i =0 ;i<n;i++){
            char a= s[i];
            if(a>='a' && a<='z'){
                temp+=a;
            }else if(a>='A' && a<='Z'){
                temp+= (char)(a-65 + 97);
            }else if(a>='0' && a<='9'){
                temp+=a;
            }
        }
        string temp2 = temp;
        reverse(temp2.begin(),temp2.end());
        return temp==temp2;
    }
};
