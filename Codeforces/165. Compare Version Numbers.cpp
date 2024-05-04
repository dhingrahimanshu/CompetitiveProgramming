class Solution {
public:
    int comp(string & s1 , string & s2){
        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end());
        while(s1.size() && s1.back()=='0'){
            s1.pop_back();
        }
        while(s2.size() && s2.back()=='0'){
            s2.pop_back();
        }

        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end());
        if(s1.size() != s2.size()){
            if(s1.size() < s2.size()){
                return -1;
            }else{
                return 1;
            }
        }
        for(int i =0;i<s1.size();++i){
            if(s1[i]<s2[i])return -1;
            if(s2[i]<s1[i])return 1;
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        // int n  = version1.size() , = version2.size();
        vector<string> arr , arr2;
        
        string temp;

        for(auto & it : version1){
            if(it =='.'){
                arr.push_back(temp);
                temp ="";
            }else{
                temp +=it;
            }
        }
        arr.push_back(temp);
        temp="";
        for(auto & it : version2){
            if(it =='.'){
                arr2.push_back(temp);
                temp ="";
            }else{
                temp +=it;
            }
        }
        arr2.push_back(temp);

        for(int i =0 ;i<max(arr.size(),arr2.size());i++){
            string x , y;
            if(i<arr.size()){
                x = arr[i];
            }
            if(i<arr2.size()){
                y = arr2[i];
            }
            int uf = comp(x , y);
            if(uf!=0)return uf;
        }


        return 0;
    }
};
