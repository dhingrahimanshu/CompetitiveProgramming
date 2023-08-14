class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int x =0;
        for(auto it : nums){
            x^=it;
        }
        int mask =0;
        for(int i =0 ;i<30;i++){
            if((x&(1<<i))){
                mask = (1<<i);
                break;
            }
        }
        int ans =0 , ans2=0;
        
        for(auto it : nums){
            if(it&(mask)){
                ans^=it;
            }else{
                ans2^=it;
            }
        }
        
        return {min(ans , ans2) , max(ans , ans2)};
    }
};
