class Solution
{
    public:

    bool areIsomorphic(string str1, string str2)
    {
        if(str1.size()!=str2.size())return 0;
        map <char,char> temp;
        map <char,int> check;
        
        for(int i =0 ;i<str1.size();i++){
            if(temp[str1[i]]=='\0'){
                if(check[str2[i]])return 0;
                temp[str1[i]]=str2[i];
                check[str2[i]]=1;
            }else{
                if(temp[str1[i]]!=str2[i])return 0;
            }
        }
        return 1;
        
    }
};
