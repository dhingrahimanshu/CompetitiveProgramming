class Solution{
public:
    bool check(int k , int i ,int m){
        return 2*k*i<=m;
    }
    
    int rec(int value , int n , int m){
        if(n==0)return 1;
        int ans=0;
        for(int i = 2*value;i<=m;i++){
            if(check(i ,n-1 , m)==0)break;
            ans += rec(i , n-1 , m);
        }
        return ans;
    }
    
    int numberSequence(int m, int n){
        if(n>7)return 0;
        int ans =0;
        for(int i =1;i<=m;i++){
            if(check(i , n-1 , m)==0)break;
            ans += rec(i , n-1 , m);
        }
        return ans;
        
    }
};
