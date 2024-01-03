class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = (int) arr.size();
        arr[0]=1;
        for(int i = 1;i<n;i++){
            arr[i] = min(1 + arr[i-1] , arr[i]);
        }
        return arr[n-1];
    }
};
