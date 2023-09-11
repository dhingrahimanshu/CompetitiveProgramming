class Solution{
public:
    bool isLucky(int n) {
        int x = 2;
        while(x<=n){
            if(n%x==0)return false;
            n -= n/x;
            x++;
        }
        return true;
    }
};
