class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = (int) nums.size();
        int ans = n;
        map <int,int> temp;
        for(auto it : nums){
            temp[it]++;
        }
        priority_queue<int> arr;
        for(auto it : temp){
            arr.push(it.second);
        }
        
        while(arr.size()>1){
            int a =arr.top();
            arr.pop();
            int b = arr.top();
            arr.pop();
            ans-= 2;
            a-=1;
            b-=1;
            if(a){
                arr.push(a);
            }
            if(b){
                arr.push(b);
            }
        }
        
        
        return ans;
    }
};
