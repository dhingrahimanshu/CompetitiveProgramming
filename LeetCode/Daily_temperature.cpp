class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        stack <int > arr;
        vector <int > ans(n,0);
        for(int i=0 ;i<temperatures.size();i++){
            if(arr.empty()){
                arr.push(i);
            }else{
                while(!arr.empty() && temperatures[arr.top()]<temperatures[i]){
                    ans[arr.top()]= (i - arr.top());
                    arr.pop();
                }
                arr.push(i);
            }
        }
        return ans;
    }
};
