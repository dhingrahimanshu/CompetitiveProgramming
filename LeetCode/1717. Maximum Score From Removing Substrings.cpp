class Solution {
public:

    int helper(string &s,string a,int x){
        stack<char>temp;
        int ans = 0;    
        for(int i = 0;i<s.size();i++){
            if(temp.size() == 0){
                temp.push(s[i]);
            }else{
                if(temp.size() && s[i]==a[1] && temp.top() == a[0]){
                    temp.pop();
                    ans += x;
                }else{
                    temp.push(s[i]);
                }
            }
        }
        s = "";
        while(temp.size()){
            s += temp.top();
            temp.pop();
        }
        reverse(s.begin(),s.end());

        return ans;
    }
    int maximumGain(string s, int x, int y) {

        string a = "ab", b = "ba";

        if(x < y){
            swap(x,y);
            swap(a,b);
        }
        int ans = helper(s,a,x);
        ans += helper(s,b,y);

        return ans;
    }
};
