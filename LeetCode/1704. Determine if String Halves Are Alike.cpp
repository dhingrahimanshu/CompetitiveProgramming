class Solution {
public:
    bool valid(char a){
        return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
    }
    bool halvesAreAlike(string s) {
        int count =0 ;
        transform(s.begin() , s.end() , s.begin(), ::tolower);
        for(int i=0 ;i<s.size()/2;i++){
            count += valid(s[i]);
            count -=valid(s[i + s.size()/2]);
        }
        return count==0;
    }
};
