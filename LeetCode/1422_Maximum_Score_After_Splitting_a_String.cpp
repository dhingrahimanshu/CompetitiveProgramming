class Solution {
public:
    int maxScore(string s) {
        int n = (int)s.size();
        int count =0;
        for(auto & it : s){
            count += (it=='1');
        }
        int count2=0;
        int ans =0; 

        for(int i =0;i<n-1;i++){
            if(s[i]=='0'){
                count2++;
            }else{
                count--;
            }
            ans = max(ans , count2+count);
        }


        return ans;
    }
};
