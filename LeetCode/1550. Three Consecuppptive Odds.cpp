class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = (int)arr.size();
        for(int i = 1;i<n-1;i++){
            if(arr[i]%2 && arr[i-1]%2 && arr[i+1]%2){
                return true;
            }
        }
        return false;
    }
};
