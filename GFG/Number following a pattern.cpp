class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans;
        stack<char> temp;
        int x =1;
        for(auto & it : S){
            temp.push((char)(x + '0'));
            x++;
            if(it=='I'){
                while(temp.size()){
                    ans+=temp.top();
                    temp.pop();
                }
            }
        }
        temp.push((char)(x + '0'));
        while(temp.size()){
            ans+=temp.top();
            temp.pop();
        }
        
        
        
        return ans;
    }
};
