class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0 , j = numbers.size()-1;
        while(i<j){
            int x = numbers[i]+ numbers[j];
            if(x==target){
                return {i+1 , j+1};
            }else if(x>target){
                j--;
            }else{
                i++;
            }
        }
        return {-1 , -1};
    }
};
