class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> temp;
        map <int,int> uf;
        int n = nums2.size() , m = nums1.size();
        vector<int> ans(n ,-1) , ans2(m);

        for(int i=0 ;i<n;i++){
            uf[nums2[i]] =i;
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && nums2[temp.top()]<nums2[i]){
                    ans[temp.top()]= nums2[i];
                    temp.pop();
                }
                temp.push(i);
            }
        }
        for(int i=0 ;i<m;i++){
            ans2[i] = ans[uf[nums1[i]]];
        }
        return ans2;
    }
};
