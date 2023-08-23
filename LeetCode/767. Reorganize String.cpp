class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        int n = s.size();
        priority_queue<pair<int,int>> pending;
        vector<int> hash(26 , 0);
        for(int i =0 ;i<n;i++){
            hash[s[i]-'a']++;
        }
        
        for(int i=0 ;i<26;i++){
            if(hash[i]==0)continue;
            pending.push({hash[i] ,i});
        }
        while(pending.size()){
            pair<int,int> x = pending.top(); pending.pop();
            if(ans.size()==0 || (ans.back()-'a')!=x.second){
                x.first--;
                ans+= (char)(x.second + 97);
                if(x.first){
                    pending.push(x);
                }
            }else{
                if(pending.size()){
                    pair<int,int> y = pending.top(); pending.pop(); pending.push(x);
                    y.first--;
                    ans+= (char)(y.second +97);
                    if(y.first){
                        pending.push(y);
                    }
                }else{
                    return "";
                }
            }
            
        }
        
        return ans;
    }
};
