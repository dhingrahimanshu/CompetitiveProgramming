class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int const MOD = 1e9 + 7;
        int n = (int)arr.size();
        
        vector<int> next(n) , prev(n);
        for(int i=0 ;i<n;i++){
            prev[i] = i;
            next[i] = n-i-1;
        }
        stack<int>temp;
        for(int i=0 ;i<n;i++){
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && arr[temp.top()]>arr[i]){
                    next[temp.top()] = i- temp.top()-1;
                    temp.pop();
                }
                temp.push(i);
            }
        }
        
        temp = stack<int>();

        for(int i=n-1;i>=0;i--){
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && arr[temp.top()]>=arr[i]){
                    prev[temp.top()] = temp.top()-i-1;
                    temp.pop();
                }
                temp.push(i);
            }
        }
    
        for(int i=0 ;i<n;i++){
         
            sum = (sum + arr[i]*1ll*(next[i] +1)*1ll*(prev[i]+1))%MOD;
        }

        return sum;
    }
};
