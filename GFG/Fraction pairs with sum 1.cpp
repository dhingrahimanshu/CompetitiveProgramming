class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        for(int i =0 ;i<n;i++){
            int g = __gcd(numerator[i]  , denominator[i]);
            numerator[i]/=g;
            denominator[i]/=g;
        }
        int ans =0;
        
        map <pair <int,int> ,int> arr;
        
        for(int i =0 ;i<n;i++){
            int a = denominator[i]-numerator[i];
            int b=  denominator[i];
            ans+= arr[{a,b}];
            arr[{numerator[i] , denominator[i]}]++;
        }
        return ans;
    }
};
