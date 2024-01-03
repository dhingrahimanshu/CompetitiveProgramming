class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int a = (upper_bound(arr , arr+n , x)-arr) -1;
        int b = (upper_bound(arr , arr+ n , x-1) -arr);
        if(b>a)return{-1,-1};
        return {b ,a};
    }
};
