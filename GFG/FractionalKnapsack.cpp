class Solution
{
    public:
    static bool mycmp(Item & a , Item &b){
        double val = (double)1.0*a.value/a.weight;
        double val2 = (double)1.0*b.value/b.weight;
        return val>val2;
    }
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr , arr + n , mycmp);
        double ans =0;
        
        for(int i=0 ;i<n;i++){
            if(W==0)break;
            int temp = min(W , arr[i].weight);
            W-=temp;
            ans +=  temp*((double)1.0*arr[i].value/arr[i].weight);
        }
        
        return ans;
    }
        
};
