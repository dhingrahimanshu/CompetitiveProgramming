class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto & it : nums){
            ans^=it;
        }
        int x =0 ,  y =0;
        int i =0;
        while((ans&(1<<i)) == 0){
            i++;
        }
        for(auto & it : nums){
            if(it&(1<<i)){
                x^=it;
            }else{
                y^=it;
            }
        }

        return {x , y};
    }
};
