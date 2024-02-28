class Solution{
    public:
    int DivisibleByEight(string s){
        int p = 0;
        int n = (int)s.size();
        for(int i=0;i<min(3 ,n);i++){
            p += pow(10 , i)*(s[n-i-1] -'0');
        }
        return (p%8?-1:1); 
    }
};
