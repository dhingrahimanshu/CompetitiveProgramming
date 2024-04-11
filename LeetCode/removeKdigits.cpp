class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> temp;
        
        int n = (int)num.size();
        for(int i =0;i<n;i++){
            if(temp.empty()){
                if(num[i] != '0'){
                    temp.push(num[i]);
                }
            }else{
                
                while(temp.size() && k && temp.top() > num[i]){
                    temp.pop();
                    k--;
                }
                if(temp.size()==0 && num[i]=='0'){
                    continue;
                }
                temp.push(num[i]);
            }
        }
        string ans;
        while(temp.size()){
            ans += temp.top();
            temp.pop();
        }
        reverse(ans.begin() , ans.end());
        while(k && ans.size()){
            k--;
            ans.pop_back();
        }
        if(ans.size() == 0){
            return "0";
        }
        return ans;

    }
};
