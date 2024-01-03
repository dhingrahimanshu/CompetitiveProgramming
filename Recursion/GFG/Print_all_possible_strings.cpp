vector<string> ans;
void helper(int i , string s , char str[] , int n){         
    if(i == n){
        ans.push_back(s);
        return;
    }
    helper(i+1 , s+str[i] , str , n);
    if(i!=0){
        helper(i+1 , s+' ' + str[i]  , str, n);
    }
}

vector<string>  spaceString(char str[])
{
    int n =0;
    while(str[n]!='\0'){
        n++;
    }
    string s = "";
    ans.clear();
    helper(0 , s , str , n);
    
    return ans;
}
