class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ma=0 , mi =0;
        stack<int> temp;
        int n = (int)nums.size();
        vector<int> ng(n) , pg(n);
        for(int i =0;i<n;i++){
            ng[i] = n-i-1;
            pg[i]=i;
        }
        for(int i =0 ;i<n;i++){
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && nums[temp.top()]<nums[i]){
                    ng[temp.top()] = i- temp.top()-1;
                    temp.pop();
                }
                temp.push(i);
            }
        }
        temp = stack<int>();

        for(int i =n-1 ;i>=0;i--){
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && nums[temp.top()]<=nums[i]){
                    pg[temp.top()] = temp.top()-i-1;
                    temp.pop();
                }
                temp.push(i);
            }
        }
        for(int i =0 ;i<n;i++){
            ma+= (pg[i]+1)*1ll*(ng[i]+1)*nums[i];
        }
        temp = stack<int>();
        for(int i =0;i<n;i++){
            ng[i] = n-i-1;
            pg[i]=i;
        }
        for(int i =0 ;i<n;i++){
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && nums[temp.top()]>nums[i]){
                    ng[temp.top()] = i- temp.top()-1;
                    temp.pop();
                }
                temp.push(i);
            }
        }
        temp = stack<int>();

        for(int i =n-1 ;i>=0;i--){
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && nums[temp.top()]>=nums[i]){
                    pg[temp.top()] = temp.top()-i-1;
                    temp.pop();
                }
                temp.push(i);
            }
        }
        for(int i =0 ;i<n;i++){
            mi += (pg[i]+1)*1ll*(ng[i]+1)*nums[i];
        }
        
        return ma -mi;
    }
};
