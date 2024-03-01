class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = (int)s.size();
        int count =0;
        for(auto &it : s){
            if(it == '1')count++;
        }
        string ans ;
        for(int i =0;i<count-1;i++){
            ans += '1';
        }   
        for(int i =0;i<n-count;i++){
            ans +='0';
        }

        ans +='1';
        return ans;
    }
};
