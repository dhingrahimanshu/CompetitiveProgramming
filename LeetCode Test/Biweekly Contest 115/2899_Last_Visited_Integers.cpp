class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ans;
        vector<int> stor;
        
        int n = (int)words.size();
        int count=0;
        for(int i=0 ;i<n;i++){
            if(words[i]=="prev"){
                int m = (int) stor.size() -count -1;
                if(m>=0){
                    ans.push_back(stor[m]);
                }else{
                    ans.push_back(-1);
                }
                count++;
            }else{
                stor.push_back(stoi(words[i]));
                count=0;
            }
        }
        
        return ans;
    }
};
