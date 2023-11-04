class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        int a = lower_bound(arr , arr+n , 1) -arr;
        if(a>=n)return -1;
        return a;
    }
};
