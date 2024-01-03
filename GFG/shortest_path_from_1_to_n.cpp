class Solution{   
public:
    int minimumStep(int n){
        if(n==1)return 0;
        if(n%3==0){
            return 1 +minimumStep(n/3);
        }
        return 1 + minimumStep(n-1);
    }
};
