class Solution
{
public:
    vector<long long int> ans;
    long long int helper(long long int n){
        if(n<=2){
            ans[n] = n-1;
            return n-1;
        }
        if(ans[n]!=0)return ans[n];
        long long int a = pow(helper(n-2) , 2);
        long long int b= helper(n-1);
        ans[n] = a-b;
        return a-b;
    }

    void gfSeries(int N)
    {
        ans.resize(20 ,0);
        helper(N);
        for(int i= 1;i<N;i++){
            cout << ans[i] << ' ';
        }
        cout << ans[N] <<endl;
    }
};
